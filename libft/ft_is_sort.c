/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louali <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/24 16:13:26 by louali            #+#    #+#             */
/*   Updated: 2018/11/16 15:58:15 by louali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_is_sort(int *tab, int length, int (*f)(int, int))
{
	int i;

	i = 0;
	while (i < length - 2)
	{
		if (f(tab[0], tab[1]) <= 0)
		{
			if (f(tab[i], tab[i + 1]) < 0 && f(tab[i + 1], tab[i + 2]) > 0)
				return (0);
		}
		if (f(tab[0], tab[1]) >= 0)
		{
			if (f(tab[i], tab[i + 1]) > 0 && f(tab[i + 1], tab[i + 2]) < 0)
				return (0);
		}
		i++;
	}
	return (1);
}
