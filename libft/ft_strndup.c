/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louali <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 15:21:42 by louali            #+#    #+#             */
/*   Updated: 2018/11/23 15:24:34 by louali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(char *src, int n)
{
	char	*dest;
	int		i;
	int		len;

	len = 0;
	i = 0;
	while (src[len] != n)
		len++;
	if ((dest = malloc((len + 1) * sizeof(char))) == NULL)
		return (NULL);
	while (src[i] != n)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
