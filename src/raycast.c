/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louali <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 13:27:04 by louali            #+#    #+#             */
/*   Updated: 2019/03/18 14:36:20 by lloncham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	side(t_wolf *r)
{
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
}

void	raycast(t_wolf *r)
{
	double		x;
	double		y;

	x = 0;
	y = 0;
	if (r->y == 0)
	{
		r->pos_x = r->start_y + 0.5;
		r->pos_y = r->start_x + 0.5;
	}
	while (x <= WEI)
	{
		init_raycast(r, x);
		text_wall(r, x, y);
		side(r);
		text_floor(r, x, y);
		x++;
	}
	controls(*r);
	menu(*r);
	r->press[4] == 1 ? mini_map(*r) : 0;
	mlx_put_image_to_window(r->img_data, r->win, r->img, 0, 0);
}
