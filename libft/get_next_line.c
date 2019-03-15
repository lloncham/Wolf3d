/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louali <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 10:53:19 by louali            #+#    #+#             */
/*   Updated: 2019/03/15 12:08:57 by lloncham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*ft_strcdup(const char *s1, int c)
{
	int		i;
	char	*dest;

	i = 0;
	while (s1[i] != c)
		i++;
	if ((dest = malloc(sizeof(char) * (i + 1))) == NULL)
		return (NULL);
	i = 0;
	while (s1[i] != c)
	{
		dest[i] = s1[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

static char		*cutting(char **rest)
{
	char	*tmp;
	char	*ret;

	if (ft_strchr(*rest, '\n') != NULL)
	{
		tmp = *rest;
		ret = ft_strcdup(*rest, '\n');
		*rest = ft_strchr(*rest, '\n') + 1;
		*rest = ft_strdup(*rest);
		free(tmp);
	}
	else
	{
		ret = ft_strdup(*rest);
		ft_strclr(*rest);
	}
	return (ret);
}

static int		reading(const int fd, char **rest)
{
	char	*buf;
	char	*tmp;
	int		ret;

	if (!(buf = (char *)malloc(sizeof(buf) * BUFF_SIZE + 1)))
		return (-1);
	while ((ret = read(fd, buf, BUFF_SIZE)))
	{
		if (ret == -1 || ret == 0)
			return (0);
		buf[ret] = '\0';
		tmp = *rest;
		*rest = ft_strjoin(*rest, buf);
		free(tmp);
		if (*rest == NULL)
			*rest = ft_strdup(buf);
		if (ft_strchr(*rest, '\n') != NULL)
			break ;
	}
	free(buf);
	return (ret);
}

int				get_next_line(const int fd, char **line)
{
	int			ret;
	static char	*rest[OPEN_MAX];

	if (fd < 0)
		return (-1);
	ret = reading(fd, &rest[fd]);
	if (ret == -1)
		return (-1);
	if (rest[fd] == NULL)
		return (0);
	if (ret == 0 && ft_strlen(rest[fd]) == 0)
		return (0);
	*line = cutting(&rest[fd]);
	return (1);
}
