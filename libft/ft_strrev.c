/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lloncham <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 13:29:38 by lloncham          #+#    #+#             */
/*   Updated: 2018/11/16 16:12:09 by lloncham         ###   ########.fr       */
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
	a = a - 1;
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
