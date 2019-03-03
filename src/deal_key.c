/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deal_key.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lloncham <lloncham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/28 15:13:52 by lloncham          #+#    #+#             */
/*   Updated: 2019/03/03 14:03:53 by lisa             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/wolf3d.h"

int		press_key(int key, t_wolf *r)
{
	ft_putnbr(key);
	ft_putchar('\n');
	if (key == 53)
		exit(0);
	key == 36 ? r->start = 1 : 0;
	key == GAUCHE ? r->press[0] = 1 : 0;
	key == DROITE ? r->press[1] = 1 : 0;
	key == BAS ? r->press[2] = 1 : 0;
	key == HAUT ? r->press[3] = 1 : 0;
	key == 4 ? r->press[4] = 1 : 0;
	if (key == DEL && r->start == 1)
	{
		bzero(r->img_data, W * H * 4);
		r->dir_x = -1;
		r->dir_y = 0;
		r->plane_x = 0;
		r->plane_y = 1;
		r->y = 0;
		raycast(r);
	}
	return (0);
}

int		release_key(int key, t_wolf *r)
{
	key == 4 ? r->press[4] = 0 : 0;
	key == GAUCHE ? r->press[0] = 0 : 0;
	key == DROITE ? r->press[1] = 0 : 0;
	key == BAS ? r->press[2] = 0 : 0;
	key == HAUT ? r->press[3] = 0 : 0;
	return (0);
}

void	right_left(t_wolf *ptr, double dir_x, double plane_x)
{
	if (ptr->press[0] == 1)
	{
		dir_x = ptr->dir_x;
		plane_x = ptr->plane_x;
		dir_x = ptr->dir_x;
		ptr->dir_x = ptr->dir_x * cos(0.02) - ptr->dir_y * sin(0.02);
		ptr->dir_y = dir_x * sin(0.02) + ptr->dir_y * cos(0.02);
		plane_x = ptr->plane_x;
		ptr->plane_x = ptr->plane_x * cos(0.02) - ptr->plane_y * sin(0.02);
		ptr->plane_y = plane_x * sin(0.02) + ptr->plane_y * cos(0.02);
	}
	if (ptr->press[1] == 1)
	{
		dir_x = ptr->dir_x;
		plane_x = ptr->plane_x;
		dir_x = ptr->dir_x;
		ptr->dir_x = ptr->dir_x * cos(-0.02) - ptr->dir_y * sin(-0.02);
		ptr->dir_y = dir_x * sin(-0.02) + ptr->dir_y * cos(-0.02);
		plane_x = ptr->plane_x;
		ptr->plane_x = ptr->plane_x * cos(-0.02) - ptr->plane_y * sin(-0.02);
		ptr->plane_y = plane_x * sin(-0.02) + ptr->plane_y * cos(-0.02);
	}
}

void	up_down(t_wolf *ptr, double dir_x, double plane_x)
{
	if (ptr->press[3] == 1)
	{
		ptr->y++;
		if (ptr->tab[(int)(ptr->pos_x + ptr->dir_x * 0.02)][(int)(ptr->pos_y)] == 0)
			ptr->pos_x += ptr->dir_x * 0.02;
		if (ptr->tab[(int)(ptr->pos_x)][(int)(ptr->pos_y + ptr->dir_y * 0.02)] == 0)
			ptr->pos_y += ptr->dir_y * 0.02;
	}
	if (ptr->press[2] == 1)
	{
		ptr->y++;
		if (ptr->tab[(int)(ptr->pos_x - ptr->dir_x * 0.02)][(int)(ptr->pos_y)] == 0)
			ptr->pos_x -= ptr->dir_x * 0.02;
		if (ptr->tab[(int)(ptr->pos_x)][(int)(ptr->pos_y - ptr->dir_y * 0.02)] == 0)
			ptr->pos_y -= ptr->dir_y * 0.02;
	}
}

int		deal_key(t_wolf *ptr)
{
	double dir_x;
	double plane_x;
	if (ptr->start == 1)
	{
		right_left(ptr, dir_x, plane_x);
		up_down(ptr, dir_x, plane_x);
		bzero(ptr->img_data, W * H * 4);
		raycast(ptr);
	}
	return (0);
}

int		ft_close(t_wolf *param)
{
	(void)param;
	exit(0);
	return (1);
}


