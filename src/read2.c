/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louali <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/25 15:23:48 by louali            #+#    #+#             */
/*   Updated: 2019/02/25 16:08:39 by louali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/wolf3d.h"

void		ft_exit(char *s)
{
	ft_putendl(s);
	exit (0);
}

int			ft_count(char *line)
{
	int		count;
	int		i;

	count = 0;
	i = 0;
	while (line[i])
	{
		while ((!ft_isdigit(line[i])) && line[i])
			i++;
		if (ft_isdigit(line[i]) || line[i] == 'X')
		{
			i++;
			count++;
		}
	}
	return (count);
}

t_wolf		check_line(char *line, int y, t_wolf tab)
{
	if (y == 0)
		tab.nbc = ft_count(line);
	if (tab.nbc != ft_count(line))
		ft_exit("Fichier invalide.\n");
	return (tab);
}

int			*num(t_wolf map, char *line, int y)
{
	int		i;
	int		x;
	int		z;
	char	num[11];

	z = 0;
	x = 0;
	i = 0;
	while (line[i])
	{
		if (ft_isdigit(line[i]))
			map.tab[y][x++] = ft_atoi(&line[i++]);
		else if (line[i] == 'X')
		{
			if (map.j != 0)
				ft_exit("Map incorrecte.");
			map.start_x = x;
			map.start_y = y;
			map.j++;
			map.tab[y][x++] = 0;
		}
	}
//		z = 0;
//		while (line[i] == ' ')
//			i++;
//		(x == 0 && line[i] == '\0') ? ft_exit("Fichier invalide.\n") : 0;
//		line[i] == '-' ? num[z++] = line[i++] : 0;
//		while (ft_isdigit(line[i]))
//			num[z++] = line[i++];
//		num[z] = '\0';
//		(line[i] != ' ' && line[i] != ',' && line[i]) ? ft_exit("Exit.\n") : 0;
//		while (line[i] != ' ' && line[i])
//			i++;
//		map.tab[y][x++] = ft_atoi(num);
//	}
//	map.tab[y][x] = -2147483648;
	return (map.tab[y]);
}

int			contour(t_wolf map)
{
	int x;
	int y;

	x = 0;
	y = 0;
	while (x < map.nbc)
	{
		if (map.tab[0][x] != 1 || map.tab[map.nbl][x] != 1)
			return (0);
		x++;
	}
	while (y < map.nbl)
	{
		if (map.tab[y][0] != 1 || map.tab[y][map.nbc] != 1)
			return (0);
		y++;
	}
	return (1);
}

t_wolf		fd_tab(int fd, int fd2)
{
	t_wolf		map;
	char		*line;
	int			y;

	y = 0;
	map.nbc = 0;
	map.nbl = 0;
	map.j = 0;
	while (get_next_line(fd, &line))
	{
		map.nbl++;
		free(line);
	}
	map.nbl == 0 ? ft_exit("Fichier invalide.") : 0;
	if ((map.tab = (int **)malloc(sizeof(int*) * map.nbl + 1)) == NULL)
		ft_exit("Fichier invalide.");
	while (get_next_line(fd2, &line))
	{
		if (!(map.tab[y] = (int *)malloc(sizeof(int) * ft_count(line) + 1)))
			ft_exit("Fichier invalide.");
		map = check_line(line, y, map);
		map.tab[y] = num(map, line, y);
		free(line);
		y++;
	}
	map.j == 0 ? ft_exit("Pas de point de depart.") : 0;
	contour(map) == 0 ? ft_exit("Pas de contours.") : 0;
//	map.y_max = y - 1;
	return (map);
}

t_wolf		ft_read(char *av)
{
	t_wolf	map;
	int		fd;
	int		fd2;

	fd = open(av, O_RDONLY);
	fd2 = open(av, O_RDONLY);
	if (fd == -1)
		ft_exit("Fichier invalide.");
	map = fd_tab(fd, fd2);
	close(fd);
	close(fd2);
	return (map);
}

int			main(int ac, char **av)
{
	(void)ac;
	ft_read(av[1]);
	return (0);
}
