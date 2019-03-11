/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louali <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 16:35:14 by louali            #+#    #+#             */
/*   Updated: 2018/11/12 12:18:01 by louali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int i;

	i = 0;
	if (s[i] == (unsigned char)c)
		return ((char *)s + i);
	while (s[i])
	{
		i++;
		if (s[i] == (unsigned char)c)
			return ((char *)s + i);
	}
	return (NULL);
}
