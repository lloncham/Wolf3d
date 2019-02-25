/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louali <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 13:49:03 by louali            #+#    #+#             */
/*   Updated: 2018/11/16 15:51:14 by louali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrev(char *str)
{
	int		a;
	int		b;
	char	t;

	a = 0;
	b = 0;
	if (str == NULL)
		return (NULL);
	while (str[a])
		a++;
	a--;
	while (b < a)
	{
		t = str[b];
		str[b] = str[a];
		str[a] = t;
		b++;
		a--;
	}
	return (str);
}
