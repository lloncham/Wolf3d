/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louali <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 12:39:05 by louali            #+#    #+#             */
/*   Updated: 2018/11/14 10:28:20 by louali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_atoi(const char *nptr)
{
	int		i;
	int		neg;
	long	j;

	j = 0;
	neg = 1;
	i = 0;
	while (nptr[i] == ' ' || nptr[i] == '\f' || nptr[i] == '\t' ||
			nptr[i] == '\n' || nptr[i] == '\r' || nptr[i] == '\v')
		i++;
	if (nptr[i] == '-')
		neg = -1;
	if (nptr[i] == '-' || nptr[i] == '+')
		i++;
	while (nptr[i] > 47 && nptr[i] < 58)
	{
		j = j * 10 + (nptr[i] - 48);
		if (j < 0 && (neg == -1))
			return (0);
		if (j < 0 && (neg == 1))
			return (-1);
		i++;
	}
	return (neg * j);
}
