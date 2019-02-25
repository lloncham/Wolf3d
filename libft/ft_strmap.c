/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lloncham <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 11:12:33 by lloncham          #+#    #+#             */
/*   Updated: 2018/11/16 14:48:19 by lloncham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	size_t	i;
	char	*new;

	i = 0;
	if (s == NULL)
		return (NULL);
	if (NULL == (new = (char *)malloc(sizeof(*s) * (ft_strlen(s) + 1))))
		return (NULL);
	while (s[i])
	{
		new[i] = f(s[i]);
		i++;
	}
	new[i] = '\0';
	return (new);
}
