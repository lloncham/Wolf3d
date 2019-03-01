/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louali <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 13:27:04 by louali            #+#    #+#             */
/*   Updated: 2019/02/28 15:46:28 by lloncham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/wolf3d.h"

void	init_raycast(t_wolf *r, double x)
{
	r->camera_x = (2 * x / W) - 1;
	r->raypos_x = r->pos_x;
	r->raypos_y = r->pos_y;
	r->raydir_x = r->dir_x + r->plane_x * r->camera_x;
	r->raydir_y = r->dir_y + r->plane_y * r->camera_x;
	r->map_x = (int)r->raypos_x;
	r->map_y = (int)r->raypos_y;
	r->deltadist_x = sqrt(1 + (r->raydir_y * r->raydir_y) / (r->raydir_x * r->raydir_x));
	r->deltadist_y = sqrt(1 + (r->raydir_x * r->raydir_x) / (r->raydir_y * r->raydir_y));
	r->hit = 0;
}

void	lon_rayon(t_wolf *r)
{
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
}

void	raycast(t_wolf *r)
{	
	double x;
	double y;

	x = 0;
	y = 0;
	if (r->y == 0)
	{
		r->pos_x = r->start_x; //pos de la camera
		r->pos_y = r->start_y;
	}
	while (x <= W)
	{
		init_raycast(r, x);
		lon_rayon(r);
//Hauteur de la colonne a tracer!
		r->hline = abs((int)(H / r->perpwalldist));
		r->draw_start = (int)(-r->hline / 2 + H / 2);
		r->draw_end = (int)(r->hline / 2 + H / 2);
		r->draw_start < 0 ? r->draw_start = 0 : r->draw_start;
		r->draw_end >= H ? r->draw_end = H - 1 : r->draw_end;
//tracer la colonne!
		y = r->draw_start;
		while (y < r->draw_end)
		{
			choose_color(0xCCCCCC, r->text_data[0][(int)x + ((int)y * (r->t_size[0] / 4))], r);
			if (r->side == 1)
				choose_color(0xCCCCCC + 10, r->text_data[0][(int)x + (((int)y * (r->t_size[0] / 4)))] & 0xB4B4B4, r);
			ft_put_pixel((int)x, (int)y, r->color, r);
			y++;
		}
		r->draw_end < 0 ? r->draw_end = H : r->draw_end;
		y = r->draw_end;
		while (y < H)
		{
			choose_color(0xFFF, r->text_data[1][((int)x + (H - (int)y - 1) * (r->t_size[1] / 4))], r);
			ft_put_pixel((int)x, (int)y, r->color, r);
			choose_color(0xBB, r->text_data[2][(int)x + (H - (int)y - 1) * (r->t_size[2] / 4)], r);
			ft_put_pixel(x, H - y - 1, r->color, r);
			y++;
		}
		x++;
	}
	mlx_put_image_to_window(r->img_data, r->win, r->img, 0, 0);
	//METTRE OMBRE SUR LA MAIN
	mlx_put_image_to_window(r->img_data, r->win, r->text[3], -W/4, -H/9);

}
