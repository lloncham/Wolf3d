/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lloncham <lloncham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/25 14:47:42 by lloncham          #+#    #+#             */
/*   Updated: 2019/02/25 14:51:22 by lloncham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/wolf3d.h"

int		count_line(int fd, char **av)
{
	int		i;
	char	*line;
	int		nbline;
	int		ret;

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

int		ft_count_col(char **split)
{
	int	i;

	i = 0;
	while (split[i])
		i++;
	return (i);
}

int		*convert(int **tab, int j, char **split, int nbcol)
{
	int		i;

	i = 0;
	while (split[i])
	{
		tab[j][i] = ft_atoi(split[i]);
		free(split[i]);
		i++;
	}
	if (i != nbcol)
		error("wrong number of column");
	free(split);
	return (tab[j]);
}

void	read_line(int fd, t_fdf *d)
{
	char	**split;
	char	*line;
	int		j;

	j = 0;
	if (!(d->tab = (int **)malloc(sizeof(int *) * d->nbline)))
		return ;
	while (get_next_line(fd, &line))
	{
		if (valid_char(line) == 0)
			error("Unvalid char!");
		split = ft_strsplit(line, ' ');
		if (j == 0)
			d->nbcol = ft_count_col(split);
		if (!(d->tab[j] = (int *)malloc(sizeof(int) * d->nbcol)))
			return ;
		d->tab[j] = convert(d->tab, j, split, d->nbcol);
		free(line);
		j++;
	}
}

t_fdf	read_file(char **av)
{
	int		fd;
	t_fdf	d;

	if (valid_file(av[1]) == 0)
		error("Unvalid file!");
	if ((fd = open(av[1], O_RDONLY)) == -1)
		error("Error");
	d.nbline = count_line(fd, av);
	if (d.nbline == 0)
		error("nothing into the file");
	read_line(fd, &d);
	close(fd);
	return (d);
}
