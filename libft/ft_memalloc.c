/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louali <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 11:05:03 by louali            #+#    #+#             */
/*   Updated: 2018/11/13 11:51:06 by louali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void *str;

	if ((str = (void *)malloc(sizeof(size_t) * size)) == NULL)
		return (NULL);
	ft_bzero(str, size);
	return (str);
}
