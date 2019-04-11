/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_raycast.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louali <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/06 16:36:58 by louali            #+#    #+#             */
/*   Updated: 2019/03/25 14:35:34 by lloncham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	var_init(t_wolf *ptr)
{
	ptr->press[6] = 1;
	ptr->texwidth = 512;
	ptr->texheight = 512;
	ptr->textures = 0;
	ptr->dir_x = -0.9999999999999;
	ptr->press[0] = 0;
	ptr->press[1] = 0;
	ptr->press[2] = 0;
	ptr->press[3] = 0;
	ptr->dir_y = 0;
	ptr->plane_x = 0;
	ptr->plane_y = 1;
	ptr->y = 0;
	ptr->start = 0;
}

void	ray2(t_wolf *r)
{
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

void	ray(t_wolf *r)
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
	ray2(r);
}

void	init_raycast(t_wolf *r, double x)
{
	r->camera_x = (2 * x / WEI) - 1;
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
	ray(r);
	r->hline = ft_abs((int)(H / r->perpwalldist));
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
}
