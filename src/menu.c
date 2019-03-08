/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louali <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/06 14:03:11 by louali            #+#    #+#             */
/*   Updated: 2019/03/07 10:24:46 by louali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/wolf3d.h"

void	start_screen(t_wolf r)
{
	int color;
	int x;
	int y;

	y = 0;
	while (y < 720)
	{
		x = 0;
		while (x < 1180)
		{
			color = r.text_data[3][x + y * (r.t_size[3] / 4)];
			ft_put_pixel(x, y, color, &r);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(r.mlx, r.win, r.img, 0, 0);
}

void	menu2(t_wolf r, int x, int y)
{
	int color;

	while (x < 1180)
	{
		if (x < 10 || x > 1170)
		{
			color = r.text_data[3][x + y * (r.t_size[3] / 4)];
			ft_put_pixel(x, y, color, &r);
		}
		x++;
	}
}

void	menu(t_wolf r)
{
	int x;
	int y;
	int color;

	y = 0;
	while (y < 720)
	{
		x = 0;
		if (y < 10 || y > 710)
		{
			while (x < 1180)
			{
				color = r.text_data[3][x + y * (r.t_size[3] / 4)];
				ft_put_pixel(x, y, color, &r);
				x++;
			}
		}
		else
			menu2(r, x, y);
		y++;
	}
}
