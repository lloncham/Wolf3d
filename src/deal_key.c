/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deal_key.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lloncham <lloncham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/28 15:13:52 by lloncham          #+#    #+#             */
/*   Updated: 2019/03/12 14:34:00 by lisa             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	right_left(t_wolf *ptr)
{
	double dir_x;
	double plane_x;

	plane_x = ptr->plane_x;
	dir_x = ptr->dir_x;
	if (ptr->press[0] == 1)
	{
		ptr->dir_x = ptr->dir_x * cos(ptr->ang) - ptr->dir_y * sin(ptr->ang);
		ptr->dir_y = dir_x * sin(ptr->ang) + ptr->dir_y * cos(ptr->ang);
		plane_x = ptr->plane_x;
		ptr->plane_x = ptr->plane_x * cos(ptr->ang) - ptr->plane_y * sin(ptr->ang);
		ptr->plane_y = plane_x * sin(ptr->ang) + ptr->plane_y * cos(ptr->ang);
	}
	if (ptr->press[1] == 1)
	{
		dir_x = ptr->dir_x;
		plane_x = ptr->plane_x;
		dir_x = ptr->dir_x;
		ptr->dir_x = ptr->dir_x * cos(-ptr->ang) - ptr->dir_y * sin(-ptr->ang);
		ptr->dir_y = dir_x * sin(-ptr->ang) + ptr->dir_y * cos(-ptr->ang);
		plane_x = ptr->plane_x;
		ptr->plane_x = ptr->plane_x * cos(-ptr->ang) - ptr->plane_y * sin(-ptr->ang);
		ptr->plane_y = plane_x * sin(-ptr->ang) + ptr->plane_y * cos(-ptr->ang);
	}
}

void	up_down(t_wolf *ptr)
{
	music(ptr);
	if (ptr->press[3] == 1)
	{
		ptr->y++;
		if (ptr->tab[(int)(ptr->pos_x + ptr->dir_x * ptr->vit)][(int)(ptr->pos_y)]
				== 0)
			ptr->pos_x += ptr->dir_x * ptr->vit;
		if (ptr->tab[(int)(ptr->pos_x)][(int)(ptr->pos_y + ptr->dir_y * ptr->vit)]
				== 0)
			ptr->pos_y += ptr->dir_y * ptr->vit;
	}
	if (ptr->press[2] == 1)
	{
		ptr->y++;
		if (ptr->tab[(int)(ptr->pos_x - ptr->dir_x * ptr->vit)][(int)(ptr->pos_y)]
				== 0)
			ptr->pos_x -= ptr->dir_x * ptr->vit;
		if (ptr->tab[(int)(ptr->pos_x)][(int)(ptr->pos_y - ptr->dir_y * ptr->vit)]
				== 0)
			ptr->pos_y -= ptr->dir_y * ptr->vit;
	}
}

void	a_d(t_wolf *ptr)
{
	if (ptr->press[8] == 1)
	{
		ptr->y++;
		if (ptr->tab[(int)(ptr->pos_x + ptr->plane_x * ptr->vit)][(int)(ptr->pos_y)]
				== 0)
			ptr->pos_x += ptr->plane_x * ptr->vit;
		if (ptr->tab[(int)(ptr->pos_x)][(int)(ptr->pos_y + ptr->plane_y * ptr->vit)]
				== 0)
			ptr->pos_y += ptr->plane_y * ptr->vit;
	}
	if (ptr->press[7] == 1)
	{
		ptr->y++;
		if (ptr->tab[(int)(ptr->pos_x - ptr->plane_x * ptr->vit)][(int)(ptr->pos_y)]
				== 0)
			ptr->pos_x -= ptr->plane_x * ptr->vit;
		if (ptr->tab[(int)(ptr->pos_x)][(int)(ptr->pos_y - ptr->plane_y * ptr->vit)]
				== 0)
			ptr->pos_y -= ptr->plane_y * ptr->vit;
	}
}

int		deal_key(t_wolf *ptr)
{
	if (ptr->start == 1)
	{
		right_left(ptr);
		up_down(ptr);
		a_d(ptr);
		bzero(ptr->img_data, WEI * H * 4);
		raycast(ptr);
	}
	return (0);
}
