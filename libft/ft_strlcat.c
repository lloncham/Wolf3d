/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louali <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 11:09:32 by louali            #+#    #+#             */
/*   Updated: 2018/11/12 13:35:48 by louali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	destlen;

	destlen = ft_strlen((const char *)dest);
	if (destlen < size)
	{
		ft_strncat(dest, src, size - destlen - 1);
		return ((size_t)ft_strlen(src) + destlen);
	}
	else
		return ((size_t)ft_strlen(src) + size);
}
