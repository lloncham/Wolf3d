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

int		ft_count_col(char *split)
{
	int	i;

	i = 0;
	while (split[i])
		i++;
	return (i);
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
	if (!(d->tab = (int **)malloc(sizeof(int *) * d->nbl)))
		return ;
	while (get_next_line(fd, &line) > 0)
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

int		main(int ac, char **av)
{
	read_file(av);
	return (0);
}
