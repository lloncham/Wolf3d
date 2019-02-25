/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louali <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 15:25:41 by louali            #+#    #+#             */
/*   Updated: 2018/11/14 17:39:40 by louali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		len(int n)
{
	int		i;
	long	x;

	x = n;
	i = 1;
	if (x < 0)
	{
		i++;
		x = -x;
	}
	while (x > 9)
	{
		x = x / 10;
		i++;
	}
	return (i);
}

static	char	*ifneg(char *str, int n, int i)
{
	str[0] = '-';
	n = -n;
	while (i > 0)
	{
		str[i] = (n % 10) + 48;
		n /= 10;
		i--;
	}
	return (str);
}

char			*ft_itoa(int n)
{
	char	*str;
	int		i;

	i = len(n);
	if ((str = malloc(sizeof(char) * (i + 1))) == NULL)
		return (NULL);
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	str[i] = '\0';
	i--;
	if (n >= 0)
	{
		while (i >= 0)
		{
			str[i] = (n % 10) + 48;
			n /= 10;
			i--;
		}
	}
	if (n < 0)
		str = ifneg(str, n, i);
	return (str);
}
