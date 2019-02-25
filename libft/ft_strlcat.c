/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lloncham <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 10:10:17 by lloncham          #+#    #+#             */
/*   Updated: 2018/11/16 14:47:55 by lloncham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t n)
{
	size_t	destlen;

	destlen = ft_strlen(dest);
	if (destlen < n)
	{
		ft_strncat(dest, src, n - destlen - 1);
		return ((size_t)ft_strlen(src) + destlen);
	}
	else
		return ((size_t)ft_strlen(src) + n);
}
