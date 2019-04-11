/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lloncham <lloncham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/25 13:49:27 by lloncham          #+#    #+#             */
/*   Updated: 2019/03/25 15:46:23 by lloncham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	error(char *str, t_wolf *r)
{
	ft_putendl(str);
	free_tab(r);
	exit(0);
}

void	ft_put_pixel(int x, int y, int color, t_wolf *p)
{
	if (x < 0 || y < 0 || x >= WEI || y >= H)
		return ;
	p->img_data[y * WEI + x] = color;
}

int		valid_char(char *str, t_wolf *r, int y)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] != '1' && str[i] != '0' && str[i] != 'X')
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

void	free_tab(t_wolf *f)
{
	int i;

	i = -1;
	if (!f->tab)
		return ;
	while (++i < f->nbl && f->tab[i])
		free(f->tab[i]);
	free(f->tab);
}
