/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lloncham <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 10:25:30 by lloncham          #+#    #+#             */
/*   Updated: 2018/11/16 11:21:40 by lloncham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *find, size_t len)
{
	size_t i;
	size_t j;

	i = 0;
	j = 0;
	if (*find == '\0')
		return ((char *)(str));
	while (str[i])
	{
		j = 0;
		while (str[i + j] == find[j] && str[i + j] && (i + j) < len)
		{
			j++;
			if (find[j] == '\0')
			{
				return (((char *)str + i));
			}
		}
		i++;
	}
	return (NULL);
}
