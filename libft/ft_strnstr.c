/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louali <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 14:43:56 by louali            #+#    #+#             */
/*   Updated: 2018/11/09 18:19:41 by louali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t len)
{
	size_t i;
	size_t j;

	i = 0;
	j = 0;
	if (s2[i] == '\0')
		return ((char *)s1);
	while (s1[i])
	{
		j = 0;
		while (s1[i + j] == s2[j] && s1[i + j] && (i + j) < len)
		{
			j++;
			if (s2[j] == '\0')
				return ((char *)s1 + i);
		}
		i++;
	}
	return (0);
}
