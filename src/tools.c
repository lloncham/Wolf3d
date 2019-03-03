/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lloncham <lloncham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/25 13:49:27 by lloncham          #+#    #+#             */
/*   Updated: 2019/02/28 15:33:31 by lloncham         ###   ########.fr       */
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
	bzero(ptr->img_data, W * H * 4);
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

int		ft_count_col(char *split)
{
	int	i;

	i = 0;
	while (split[i])
		i++;
	return (i);
}
