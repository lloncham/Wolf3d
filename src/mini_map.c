/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lisa <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/01 12:30:02 by lisa              #+#    #+#             */
/*   Updated: 2019/03/10 15:22:03 by louali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/wolf3d.h"

void		controls(t_wolf r)
{
	int x;
	int y;
	int color;
	int x2;
	int y2;

	y2 = 20;
	y = 12;
	while (y < 210)
	{
		x2 = 0;
		x = 934;
		while (x < 1169)
		{
			color = r.text_data[4][x2 + y2 * (r.t_size[4] / 4)];
			ft_put_pixel(x, y, color, &r);
			x++;
			x2++;
		}
		y++;
		y2++;
	}
}

void		carre2(t_wolf r, int x, int y, int color)
{
	int x2;
	int y2;

	x = (x + 2) * 10;
	y = (y + 2) * 10;
	x2 = x;
	y2 = y;
	while (y < y2 + 10)
	{
		x = x2;
		while (x < x2 + 10)
		{
			ft_put_pixel(x, y, color, &r);
			x++;
		}
		y++;
	}
}
void		carre(t_wolf r, int x, int y, int color)
{
	int x2;
	int y2;

	x = (x + 2) * 10;
	y = (y + 2) * 10;
	x2 = x;
	y2 = y;
	while (y < y2 + 10)
	{
		x = x2;
		while (x < x2 + 10)
		{
			color = r.text_data[3][(x + x2) + (y +y2) * (r.t_size[3] / 4)];
			ft_put_pixel(x, y, color, &r);
			x++;
		}
		y++;
	}
}
void		mini_map(t_wolf r)
{
	int		x;
	int		y;

	y = 0;
	while (y < r.nbl)
	{
		x = 0;
		while (x < r.nbc)
		{
			carre(r, x, y, r.text_data[3][x + y * (r.t_size[3] / 4)]);
			x++;
		}
		y++;
	}
	y = 0;
	while (y < r.nbl)
	{
		x = 0;
		while (x < r.nbc)
		{
		if (r.tab[y][x] == 0)
			carre2(r, x, y, 8282937);
		if (x == (int)r.pos_y && y == (int)r.pos_x)
			carre2(r, x, y, 3289800);
		x++;
		}
	y++;
	}
}
