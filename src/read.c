/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lloncham <lloncham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/25 14:47:42 by lloncham          #+#    #+#             */
/*   Updated: 2019/03/02 20:01:50 by lisa             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/wolf3d.h"

int		count_line(int fd, char **av)
{
	int		i;
	char	*line;
	int		nbline;

	nbline = 0;
	i = 0;
	if ((fd = open(av[1], O_RDONLY)) == -1)
		return (0);
	while (get_next_line(fd, &line))
	{
		nbline++;
		free(line);
	}
	close(fd);
	return (nbline);
}

int		contour(t_wolf *map)
{
	int		x;
	int		y;

	x = 0;
	y = 0;
	while (x < map->nbc)
	{
		if (map->tab[0][x] != 1 || map->tab[map->nbl - 1][x] != 1)
			return (0);
		x++;
	}
	while (y < map->nbl)
	{
		if (map->tab[y][0] != 1 || map->tab[y][map->nbc - 1] != 1)
			return (0);
		y++;
	}
	return (1);
}

int		*convert(int **tab, int j, char *split, int nbcol)
{
	int		i;

	i = 0;
	while (split[i])
	{
		if (split[i] == 'X')
			split[i] = '0';
		tab[j][i] = split[i] - '0';
		i++;
	}
	if (i != nbcol)
		error("wrong number of column");
	free(split);
	return (tab[j]);
}

void	read_line(int fd, t_wolf *d)
{
	char	*line;
	int		j;

	j = 0;
	d->j = 0;
	if (!(d->tab = (int **)malloc(sizeof(int *) * d->nbl)))
		return ;
	while (get_next_line(fd, &line))
	{
		if (valid_char(line, d, j) == 0)
			error("Unvalid char!");
		if (j == 0)
			d->nbc = ft_count_col(line);
		if (!(d->tab[j] = (int *)malloc(sizeof(int) * d->nbc)))
			return ;
		d->tab[j] = convert(d->tab, j, line, d->nbc);
		j++;
	}
	d->j != 1 ? error("Mauvaise position.") : 0;
	contour(d) == 0 ? error("Pas de contours.") : 0;
}

t_wolf	read_file(char **av)
{
	int		fd;
	t_wolf	d;

	if ((fd = open(av[1], O_RDONLY)) == -1)
		error("Error");
	d.nbl = count_line(fd, av);
	if (d.nbl == 0)
		error("nothing into the file");
	read_line(fd, &d);
	close(fd);
	return (d);
}
