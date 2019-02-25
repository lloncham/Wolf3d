/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lloncham <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 11:13:39 by lloncham          #+#    #+#             */
/*   Updated: 2018/11/15 13:33:09 by lloncham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count(int n)
{
	int		i;
	int		nbr;

	nbr = n;
	i = 0;
	if (nbr < 0)
	{
		i++;
		nbr = -nbr;
	}
	while (nbr > 9)
	{
		nbr = nbr / 10;
		i++;
	}
	return (i);
}

char		*ft_itoa(int n)
{
	char	*str;
	int		i;

	i = 0;
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	i = ft_count(n);
	if (!(str = (ft_strnew((i + 1)))))
		return (NULL);
	str[i] = '\0';
	if (n == 0)
		*str = n + '0';
	while (n < 0)
	{
		str[0] = '-';
		n = -n;
		str[i--] = '0' + (n % 10);
		n = n / 10;
	}
	while (n > 0)
	{
		str[i--] = '0' + (n % 10);
		n = n / 10;
	}
	return (str);
}
