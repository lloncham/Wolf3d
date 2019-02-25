/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lloncham <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 13:43:09 by lloncham          #+#    #+#             */
/*   Updated: 2018/11/16 14:31:21 by lloncham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *str, const char *to_find)
{
	int i;
	int j;

	i = 0;
	if (*to_find == '\0')
		return ((char *)(str));
	while (str[i])
	{
		j = 0;
		while (str[i + j] == to_find[j] && str[i + j])
		{
			j++;
			if (to_find[j] == '\0')
			{
				return ((char *)(str + i));
			}
		}
		i++;
	}
	return (0);
}
