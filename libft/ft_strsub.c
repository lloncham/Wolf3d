/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lloncham <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 11:13:01 by lloncham          #+#    #+#             */
/*   Updated: 2018/11/16 11:39:03 by lloncham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char			*new;
	unsigned int	i;

	i = 0;
	if (s == NULL)
		return (NULL);
	if (!(new = ft_strnew(len)))
		return (NULL);
	while (i < len)
		new[i++] = s[start++];
	new[len] = '\0';
	return (new);
}
