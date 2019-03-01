/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deal_key.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lloncham <lloncham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/28 15:13:52 by lloncham          #+#    #+#             */
/*   Updated: 2019/02/28 15:42:51 by lloncham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/wolf3d.h"

void	right_left(int key, t_wolf *ptr)
{
	double dir_x;
	double plane_x;

	dir_x = ptr->dir_x;
	plane_x = ptr->plane_x;
	if (key == GAUCHE)
	{
		bzero(ptr->img_data, W * H * 4);
		ptr->dir_x = ptr->dir_x * cos(0.05) - ptr->dir_y * sin(0.05);
		ptr->dir_y = dir_x * sin(0.05) + ptr->dir_y * cos(0.05);
		ptr->plane_x = ptr->plane_x * cos(0.05) - ptr->plane_y * sin(0.05);
		ptr->plane_y = plane_x * sin(0.05) + ptr->plane_y * cos(0.05);
		raycast(ptr);
	}
	if (key == DROITE)
	{
		bzero(ptr->img_data, W * H * 4);
		ptr->dir_x = ptr->dir_x * cos(-0.05) - ptr->dir_y * sin(-0.05);
		ptr->dir_y = dir_x * sin(-0.05) + ptr->dir_y * cos(-0.05);
		ptr->plane_x = ptr->plane_x * cos(-0.05) - ptr->plane_y * sin(-0.05);
		ptr->plane_y = plane_x * sin(-0.05) + ptr->plane_y * cos(-0.05);
		raycast(ptr);
	}
}

void	up_down(int key, t_wolf *ptr)
{
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
}

int		deal_key(int key, t_wolf *ptr)
{
	ft_putnbr(key);
	ft_putchar('\n');
	if (key == 17)
		ptr->textures = 1;
	if (key == 53)
		exit(0);
	right_left(key, ptr);
	up_down(key, ptr);
	if (key == DEL)
	{
		bzero(ptr->img_data, W * H * 4);
		ptr->dir_x = -1;
		ptr->dir_y = 0;
		ptr->plane_x = 0;
		ptr->plane_y = 1;
		ptr->y = 0;
		raycast(ptr);
	}
	return (0);
}
