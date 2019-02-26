/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louali <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 13:27:04 by louali            #+#    #+#             */
/*   Updated: 2019/02/27 00:28:22 by lisa             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/wolf3d.h"

void	raycast(t_wolf *r)
{	
/*	int tab[25][25] =
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
		{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}};*/
	if (r->y == 0)
		r->pos_x = r->start_x, r->pos_y = r->start_y;

	double x = 0, y = 0;
	while (x <= W)
	{
		r->camera_x = (2 * x / W) - 1;
		r->raypos_x = r->pos_x;
		r->raypos_y = r->pos_y;
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
			if (r->tab[r->map_x][r->map_y] > 0)
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
		y = r->draw_start;
		while (y < r->draw_end)
		{
			r->color = 0xf2f2f2;
			if (r->side == 1)
				r->color = 0xCCCCCC;
			ft_put_pixel((int)x, (int)y, r->color, r);
			y++;
		}
		if (r->draw_end < 0)
			r->draw_end = H;
		y = r->draw_end;
		while (y < H)
		{
			ft_put_pixel(x, y, 0x006666, r);
			ft_put_pixel(x, H-y-1, 0xcc0000, r);
			y++;
		}
		x++;
	}
	mlx_put_image_to_window(r->img_data, r->win, r->img, 0, 0);
}

int		deal_key(int key, t_wolf *ptr)
{
/*	int tab[25][25] =
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
		{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}};*/
	double dir_x, plane_x;
	ft_putnbr(key);
	ft_putchar('\n');
	if (key == 53)
		exit(0);
//	if (key == 126 || key == 125 || key == 123 || key == 124 || key == 49 || key == 36)
//	{
	if (key == GAUCHE)
	{ 
		bzero(ptr->img_data, W * H * 4);
		dir_x = ptr->dir_x;
		ptr->dir_x = ptr->dir_x * cos(0.2) - ptr->dir_y * sin(0.2);
		ptr->dir_y = dir_x * sin(0.2) + ptr->dir_y * cos(0.2);
		plane_x = ptr->plane_x;
		ptr->plane_x = ptr->plane_x * cos(0.2) - ptr->plane_y * sin(0.2);
		ptr->plane_y = plane_x * sin(0.2) + ptr->plane_y * cos(0.2);
		raycast(ptr);
	}
	if (key == DROITE)
	{ 
		bzero(ptr->img_data, W * H * 4);
		dir_x = ptr->dir_x;
		ptr->dir_x = ptr->dir_x * cos(-0.2) - ptr->dir_y * sin(-0.2);
		ptr->dir_y = dir_x * sin(-0.2) + ptr->dir_y * cos(-0.2);
		plane_x = ptr->plane_x;
		ptr->plane_x = ptr->plane_x * cos(-0.2) - ptr->plane_y * sin(-0.2);
		ptr->plane_y = plane_x * sin(-0.2) + ptr->plane_y * cos(-0.2);
		raycast(ptr);
	}
	if (key == HAUT)
	{ 
		ptr->y++;
		bzero(ptr->img_data, W * H * 4);
		if (ptr->tab[(int)(ptr->pos_x + ptr->dir_x * 0.1)][(int)(ptr->pos_y)] == 0)
			ptr->pos_x += ptr->dir_x * 0.1;
		if (ptr->tab[(int)(ptr->pos_x)][(int)(ptr->pos_y + ptr->dir_y * 0.1)] == 0)
			ptr->pos_y += ptr->dir_y * 0.1;
		raycast(ptr);
	}
	if (key == BAS)
	{ 
		ptr->y++;
		bzero(ptr->img_data, W * H * 4);
		if (ptr->tab[(int)(ptr->pos_x - ptr->dir_x * 0.1)][(int)(ptr->pos_y)] == 0)
			ptr->pos_x -= ptr->dir_x * 0.1;
		if (ptr->tab[(int)(ptr->pos_x)][(int)(ptr->pos_y - ptr->dir_y * 0.1)] == 0)
			ptr->pos_y -= ptr->dir_y * 0.1;
		raycast(ptr);
	}
	if (key == DEL)
	{
		bzero(ptr->img_data, W * H * 4);
		ptr->dir_x = -1;
		ptr->dir_y = 0;
		ptr->plane_x = 0;
		ptr->plane_y= 1;
		ptr->y = 0;
		raycast(ptr);
	}
	return (0);
}

int		main(int ac, char **av)
{
	t_wolf ptr;
	int bpp, size, endian;
	(void)ac;
	
	ptr = read_file(av);
	ptr.dir_x = -1;
	ptr.dir_y = 0;
	ptr.plane_x = 0;
	ptr.plane_y= 1;
	ptr.y = 0;
	ptr.mlx = mlx_init();
	ptr.win = mlx_new_window(ptr.mlx, W, H, "Wolf3D");
	ptr.img = mlx_new_image(ptr.mlx, W, H);
	ptr.img_data = (int *)mlx_get_data_addr(ptr.img, &bpp, &size, &endian);
	raycast(&ptr);
	mlx_hook(ptr.win, 2, 0, deal_key, &ptr);
	mlx_loop(ptr.mlx);
	return (0);
}
