/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_words_tables.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lloncham <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 14:02:21 by lloncham          #+#    #+#             */
/*   Updated: 2018/12/20 18:10:20 by lloncham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_print_words_tables(char **tab, char c)
{
	int i;
	int j;

	i = 0;
	while (tab[i])
	{
		j = 0;
		while (tab[i][j])
		{
			ft_putchar(tab[i][j]);
			j++;
		}
		ft_putchar(c);
		i++;
	}
}
