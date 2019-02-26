/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lloncham <lloncham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/25 13:49:27 by lloncham          #+#    #+#             */
/*   Updated: 2019/02/26 13:40:04 by lloncham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/wolf3d.h"

void	error(char *str)
{
	ft_putendl(str);
	exit(0);
}

int		clear_img(t_wolf *ptr)
{
//	bzero(ptr->img_data, ptr->size_w * ptr->size_h * 4);
	return (0);
}

void	ft_put_pixel(int x, int y, int color, t_wolf *p)
{
	if (x < 0 || y < 0 || x >= W || y >= H)
		return ;
	p->img_data[y * W + x] = color;
}

int		valid_char(char *str, t_wolf *r, int y)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (!ft_isdigit(str[i]) && str[i] != 'X')
			return (0);
		if (str[i] == 'X')
		{
			r->start_x = i;
			r->start_y = y;
			r->j++;
		}
		i++;
	}
	return (1);
}
