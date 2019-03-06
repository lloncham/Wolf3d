/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louali <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 13:27:04 by louali            #+#    #+#             */
/*   Updated: 2019/03/06 15:49:43 by louali           ###   ########.fr       */
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
	r->deltadist_x = sqrt(1 + (r->raydir_y * r->raydir_y) / (r->raydir_x
		* r->raydir_x));
	r->deltadist_y = sqrt(1 + (r->raydir_x * r->raydir_x) / (r->raydir_y
		* r->raydir_y));
	r->hit = 0;
}

void	lon_rayon(t_wolf *r)
{
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
	if (r->side == 0)
		r->perpwalldist = fabs((r->map_x - r->raypos_x + (1 - r->step_x) / 2)
			/ r->raydir_x);
	else
		r->perpwalldist = fabs((r->map_y - r->raypos_y + (1 - r->step_y) / 2)
			/ r->raydir_y);
}

void	raycast(t_wolf *r)
{
	double		x;
	double		y;

	x = 0;
	y = 0;
	if (r->y == 0)
	{
		r->pos_x = r->start_y;
		r->pos_y = r->start_x;
	}
	while (x <= W)
	{
		init_raycast(r, x);
		lon_rayon(r);
		r->hline = abs((int)(H / r->perpwalldist));
		r->draw_start = (int)(-r->hline / 2 + H / 2);
		r->draw_end = (int)(r->hline / 2 + H / 2);
		r->draw_start < 0 ? r->draw_start = 0 : r->draw_start;
		r->draw_end >= H ? r->draw_end = H - 1 : r->draw_end;
		r->texnum = r->tab[r->map_x][r->map_y] - 1;
		if (r->side == 1)
			r->wall_x = r->raypos_x + ((r->map_y - r->raypos_y + (1 - r->step_y)
				/ 2) / r->raydir_y) * r->raydir_x;
		else
			r->wall_x = r->raypos_y + ((r->map_x - r->raypos_x + (1 - r->step_x)
				/ 2) / r->raydir_x) * r->raydir_y;
		r->wall_x -= floor((r->wall_x));
		r->texwidth = 512;
		r->texheight = 512;
		r->tex_x = r->wall_x * r->texwidth;
		if (r->side == 0 && r->raydir_x > 0)
			r->tex_x = r->texwidth - r->tex_x - 1;
		if (r->side == 1 && r->raydir_y < 0)
			r->tex_x = r->texwidth - r->tex_x - 1;
		y = r->draw_start;
		while (y < r->draw_end)
		{
			r->tex_y = (y * 2 - H + r->hline) * (r->texheight / 2) / r->hline;
			r->color = r->text_data[0][r->t_size[0] / 4 * (int)r->tex_y
				+ (int)r->tex_x];
			if (r->side == 1)
				r->color = (r->color >> 1) & 8355711;
			ft_put_pixel((int)x, (int)y, r->color, r);
			y++;
		}
		r->distplayer = 0;
		r->currentdist = 0;
		r->distwall = r->perpwalldist;
		if (r->side == 0 && r->raydir_x > 0)
		{
			r->floor_x_wall = r->map_x;
			r->floor_y_wall = r->map_y + r->wall_x;
		}
		else if (r->side == 0 && r->raydir_x < 0)
		{
			r->floor_x_wall = r->map_x + 1.0;
			r->floor_y_wall = r->map_y + r->wall_x;
		}
		else if (r->side == 1 && r->raydir_y > 0)
		{
			r->floor_x_wall = r->map_x + r->wall_x;
			r->floor_y_wall = r->map_y;
		}
		else
		{
			r->floor_x_wall = r->map_x + r->wall_x;
			r->floor_y_wall = r->map_y + 1.0;
		}
		y = r->draw_end;
		while (y < H)
		{
			r->currentdist = H / (2 * y - H);
			r->weight = (r->currentdist - r->distplayer) / (r->distwall
				- r->distplayer);
			r->currentfloor_x = r->weight * r->floor_x_wall + (1.0 - r->weight)
				* r->pos_x;
			r->currentfloor_y = r->weight * r->floor_y_wall + (1.0 - r->weight)
				* r->pos_y;
			r->floortex_x = (int)(r->currentfloor_x * r->texwidth)
				% r->texwidth;
			r->floortex_y = (int)(r->currentfloor_y * r->texheight)
				% r->texheight;
			ft_put_pixel(x, y, r->text_data[1][r->t_size[1] / 4 * r->floortex_y
				+ r->floortex_x], r);
			ft_put_pixel(x, H - y - 1, r->text_data[2][r->t_size[2] / 4
				* r->floortex_y + r->floortex_x], r);
			y++;
		}
		x++;
	}
	controls(*r);
	menu(*r);
	r->press[4] == 1 ? mini_map(*r) : 0;
	mlx_put_image_to_window(r->img_data, r->win, r->img, 0, 0);
}
