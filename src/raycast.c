#include "../include/wolf3d.h"
void	raycast(t_wolf *r)
{	
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
	double posx = 22, posy = 11.5;
	r->dir_x = -1;
	r->dir_y = 0;
	r->plane_x = 0;
	r->plane_y= 1;

	int x = 0;
	while (x <= W)
	{
		r->camera_x = (2 * x / W) - 1;
		r->raypos_x = posx;
		r->raypos_y = posy;
		r->raydir_x = r->dir_x + r->plane_x * r->camera_x;
		r->raydir_y = r->dir_y + r->plane_y * r->camera_x;
		r->map_x = (int)r->raypos_x;
		r->map_y = (int)r->raypos_y;
		r->deltadist_x = sqrt(1 +(r->raydir_y * r->raydir_y) / (r->raydir_x * r->raydir_x));
		r->deltadist_y = sqrt(1 +(r->raydir_x * r->raydir_x) / (r->raydir_y * r->raydir_y));
		r->hit = 0;
//Connaitre orientation du mur touche et la longeur reelle du rayon!
		if (r->raydir_x < 0)
		{
			r->step_x = -1;
			r->sidedist_x = (r->raypos_x - r->map_x) * r->deltadist_x;
		}
		else
		{
			r->step_x = 1;
			r->sidedist_x = (r->map_x + 1.0 - r->raypos_x) * r->deltadist_x;
		}
		if (r->raydir_y < 0)
		{
			r->step_y = -1;
			r->sidedist_y = (r->raypos_y - r->map_y) * r->deltadist_y;
		}
		else
		{
			r->step_y = 1;
			r->sidedist_y = (r->map_y + 1.0 - r->raypos_y) * r->deltadist_y;
		}
		while (r->hit == 0)
		{
			if (r->sidedist_x < r->sidedist_y)
			{
				r->sidedist_x += r->deltadist_x;
				r->map_x += r->step_x;
				r->side = 0;
			}
			else
			{
				r->sidedist_y += r->deltadist_y;
				r->map_y += r->step_y;
				r->side = 1;
			}
			if (tab[r->map_x][r->map_y] > 0)
				r->hit = 1;
		}
//distance corrigee!
		if (r->side == 0)
			r->perpwalldist = fabs((r->map_x - r->raypos_x + (1 - r->step_x) / 2) / r->raydir_x);
		else
			r->perpwalldist = fabs((r->map_y - r->raypos_y + (1 - r->step_y) / 2) / r->raydir_y);
//Hauteur de la colonne a tracer!
		r->hline = abs((int)(H / r->perpwalldist));
		r->draw_start = (int)(-r->hline / 2 + H / 2);
		r->draw_end = (int)(r->hline / 2 + H / 2);

		if (r->draw_start < 0)
			r->draw_start = 0;
		if (r->draw_end >= H)
			r->draw_end = H - 1;
//tracer la colonne!
		int y = r->draw_start;
		while (y < r->draw_end)
		{
			r->color = 0xf2f2f2;
			if (r->side == 1)
				r->color = 0xCCCCCC;
			ft_put_pixel(x, y, r->color, r);
			y++;
		}
		x++;
	}
	mlx_put_image_to_window(r->img_data, r->win, r->img, 0, 0);
}

int		main(int ac, char **av)
{
	t_wolf ptr;
	int bpp, size, endian;
	(void)ac;
	ptr.mlx = mlx_init();
	ptr.win = mlx_new_window(ptr.mlx, 480, 240, "Wolf3D");
	ptr.img = mlx_new_image(ptr.mlx, 480, 240);
	ptr.img_data = (int *)mlx_get_data_addr(ptr.img, &bpp, &size, &endian);
	raycast(&ptr);
	mlx_loop(ptr.mlx);
	return (0);
}
