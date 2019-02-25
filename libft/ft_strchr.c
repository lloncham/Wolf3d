/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lloncham <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 12:14:31 by lloncham          #+#    #+#             */
/*   Updated: 2018/11/16 14:43:20 by lloncham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int i;

	i = 0;
	if (s[i] == (unsigned char)c)
		return ((char *)(s + i));
	while (s[i])
	{
		i++;
		if (s[i] == (unsigned char)c)
			return ((char *)(s + i));
	}
	return (NULL);
}
