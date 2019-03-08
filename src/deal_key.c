/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deal_key.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lloncham <lloncham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/28 15:13:52 by lloncham          #+#    #+#             */
/*   Updated: 2019/03/08 22:05:55 by lisa             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/wolf3d.h"

int		press_key(int key, t_wolf *r)
{
	ft_putnbr(key);
	ft_putchar('\n');
	if (key == 53)
		exit(0);
	key == ENTER || key == 36 ? r->start = 1 : 0;
	key == GAUCHE ? r->press[0] = 1 : 0;
	key == DROITE ? r->press[1] = 1 : 0;
	key == BAS || key == S ? r->press[2] = 1 : 0;
	key == HAUT || key == W ? r->press[3] = 1 : 0;
	key == SHIFT ? r->press[5] = 1 : 0;
	key == 4 ? r->press[4] = 1 : 0;
	key == 17 ? r->textures = 1 : 0;
	key == TEXTURE ? r->press[6]++ : 0;
	key == A ? r->press[7] = 1 : 0;
	key == D ? r->press[8] = 1 : 0;
	if (key == DEL && r->start == 1)
	{
		bzero(r->img_data, WEI * H * 4);
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
	key == SHIFT ? r->press[5] = 0 : 0;
	key == DROITE ? r->press[1] = 0 : 0;
	key == BAS || key == S ? r->press[2] = 0 : 0;
	key == HAUT || key == W ? r->press[3] = 0 : 0;
	key == A ? r->press[7] = 0 : 0;
	key == D ? r->press[8] = 0 : 0;
	return (0);
}

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
	if (ptr->press[5] == 1)
	{
		ptr->colori += 655621;
		ptr->vit = 0.15;
		ptr->ang = 0.05;
		if (ptr->i == 0)
		{
			ptr->i = 1;
			system("afplay ../song/run.mp3&");
		}
	}
	else
	{
		if (ptr->i == 1)
		{
			system("killall afplay");
			ptr->i = 0;
		}
		ptr->ang = 0.02;
		ptr->vit = 0.05;
	}
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
		bzero(ptr->img_data, WEI * H * 4);
		raycast(ptr);
	}
	return (0);
}
