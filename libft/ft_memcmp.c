/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lloncham <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 17:02:57 by lloncham          #+#    #+#             */
/*   Updated: 2018/11/12 12:49:44 by lloncham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*sa;
	unsigned char	*sb;

	i = 0;
	sa = (unsigned char *)s1;
	sb = (unsigned char *)s2;
	while (i < n)
	{
		if (sa[i] == sb[i])
			i++;
		else
			return (sa[i] - sb[i]);
	}
	return (0);
}
