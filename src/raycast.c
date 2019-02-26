#include "../include/wolf3d.h"

void	put_pixel(int x, int y, int h, int w, int color, int *data)
{
	if (x < 0 || y < 0 || y >= H || x >= W)
		return ;
	printf("ok");
	data[y * W + x] = color;
}

void	raycast(int *data, void *mlx, void *win, void *img)
{	
	int w = 480, h = 240;
	int tab[25][25] =
	{{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
		{1,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,1,1,0,0,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,1,1,0,0,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,1,1,1,0,1,1,1,1},
		{1,1,1,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,1},
		{1,1,1,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1,0,1,0,0,1},
		{1,1,0,0,0,0,0,0,1,1,0,1,0,1,0,1,1,1,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,1,0,1,0,0,1},
		{1,1,0,0,0,0,0,0,1,1,0,1,0,1,0,1,1,1,1,1,0,1,1,1,1},
		{1,1,1,1,0,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,0,1,1,1,1},
		{1,1,1,1,0,1,1,1,1,1,1,1,0,0,1,0,1,1,0,0,0,0,0,0,1},
		{1,1,0,0,0,0,0,1,1,1,0,0,0,0,0,0,1,1,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,1,1,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,1,1,1,1,1,1,1,0,1,1,1,0,0,0,1,0,1},
		{1,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,0,1,0,0,1},
		{1,1,0,0,0,0,0,1,1,1,0,0,0,1,1,1,1,1,1,0,0,0,1,1,1},
		{1,0,0,0,0,0,0,0,1,0,0,0,0,0,1,1,0,1,0,1,0,1,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,1,0,0,0,0,0,1,1,0,1,0,1,0,1,0,0,1},
		{1,1,0,0,0,0,0,1,1,1,0,0,0,1,1,1,1,1,1,0,0,0,1,1,1},
		{1,1,0,0,0,0,0,1,1,1,0,0,0,1,1,1,1,1,1,0,0,0,1,1,1},
		{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}};
	double posx = 22, posy = 11.5, dirx = -1, diry = 0, planex = 0, planey= 1;

	int x = 0;
	while (x <= w)
	{
		double camerax = (2*x/w)-1, rayposx = posx, rayposy = posy, raydirx = dirx+planex*camerax, raydiry = diry+planey*camerax;

		int mapx = (int)rayposx, mapy =(int)rayposy;

		double sidedistx, sidedisty;

		double deltadistx = sqrt(1 +(raydiry*raydiry) / (raydirx*raydirx));
		double deltadisty = sqrt(1 +(raydirx*raydirx) / (raydiry*raydiry));

		double stepx, stepy;

		int hit = 0, side;

		double perpwalldist;

//Connaitre orientation du mur touche et la longeur reelle du rayon!
		if (raydirx < 0)
		{
			stepx = -1;
			sidedistx = (rayposx - mapx) * deltadistx;
		}
		else
		{
			stepx = 1;
			sidedistx = (mapx + 1.0 - rayposx) * deltadistx;
		}
		if (raydiry < 0)
		{
			stepy = -1;
			sidedisty = (rayposy - mapy) * deltadisty;
		}
		else
		{
			stepy = 1;
			sidedisty = (mapy + 1.0 - rayposy) * deltadisty;
		}
		while (hit == 0)
		{
			if (sidedistx < sidedisty)
			{
				sidedistx += deltadistx;
				mapx += stepx;
				side = 0;
			}
			else
			{
				sidedisty += deltadisty;
				mapy += stepy;
				side = 1;
			}
			if (tab[mapx][mapy] > 0)
				hit = 1;
		}
//distance corrigee!
		if (side == 0)
			perpwalldist = fabs((mapx-rayposx+(1-stepx)/2)/raydirx);
		else
			perpwalldist = fabs((mapy-rayposy+(1-stepy)/2)/raydiry);
//Hauteur de la colonne a tracer!
		int hauteurligne = abs((int)(h / perpwalldist));
		int drawstart = (int)(-hauteurligne / 2 + h / 2);
		int drawend = (int)(hauteurligne / 2 + h / 2);

		if (drawstart < 0)
			drawstart = 0;
		if (drawend >= h)
			drawend = h - 1;
//tracer la colonne!
		int y = drawstart;
		while (y < drawend)
		{
			printf("y : %d, drawend : %d\n", y, drawend);
			int color = 0xf2f2f2;
			if (side == 1)
				color = 0xCCCCCC;
			put_pixel(x, y, 240, 480, color, data);
			y++;
		}
		x++;
	}
	mlx_put_image_to_window(data, win, img, 0, 0);
}

int		main(int ac, char **av)
{
	int bpp, size, endian;
	(void)ac;
	void *mlx = mlx_init();
	void *win = mlx_new_window(mlx, 480, 240, "Wolf3D");
	void *img = mlx_new_image(mlx, 480, 240);
	int *data = (int *)mlx_get_data_addr(img, &bpp, &size, &endian);
	raycast(data, mlx, win, img);
	mlx_loop(mlx);
	return (0);
}
