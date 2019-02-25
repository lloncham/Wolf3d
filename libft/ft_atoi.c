/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lloncham <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 18:10:43 by lloncham          #+#    #+#             */
/*   Updated: 2018/11/15 12:01:32 by lloncham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	int		i;
	int		j;
	long	num;

	i = 0;
	j = 1;
	num = 0;
	while ((str[i] == ' ') || (str[i] == '\t') || (str[i] == '\v') ||
			(str[i] == '\n') || (str[i] == '\r') || (str[i] == '\f'))
		i++;
	if (str[i] == '-')
		j = -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		num = num * 10 + (str[i] - 48);
		if (num < 0 && (j == -1))
			return (0);
		if (num < 0 && (j == 1))
			return (-1);
		i++;
	}
	return (j * num);
}
