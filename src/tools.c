/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lloncham <lloncham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/25 13:49:27 by lloncham          #+#    #+#             */
/*   Updated: 2019/02/25 13:50:11 by lloncham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	error(char *str)
{
	ft_putendl(str);
	exit(0);
}

int		clear_img(t_mlx *ptr)
{
	bzero(ptr->img_data, ptr->size_w * ptr->size_h * 4);
	return (0);
}

void	ft_put_pixel(t_mlx *p, int y, int x, int color)
{
	if (x < 0 || y < 0 || x >= p->size_w || y >= p->size_h)
		return ;
	p->img_data[y * p->size_w + x] = color;
}
