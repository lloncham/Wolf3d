/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lloncham <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 17:25:38 by lloncham          #+#    #+#             */
/*   Updated: 2018/11/16 11:51:46 by lloncham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_word(char const *s, char c)
{
	size_t	word;
	size_t	i;

	word = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i] != c && s[i])
			word++;
		while (s[i] != c && s[i])
			i++;
	}
	return (word);
}

char			**ft_strsplit(char const *s, char c)
{
	char		**cut;
	size_t		i;
	size_t		j;
	size_t		k;

	i = 0;
	j = 0;
	if (s == NULL)
		return (NULL);
	if (!(cut = (char **)malloc(sizeof(char *) * (ft_word(s, c) + 1))))
		return (NULL);
	while (s[i])
	{
		while (s[i] == c && s[i])
			i++;
		k = i;
		while (s[k] != c && s[k])
			k++;
		if (s[i])
			cut[j++] = ft_strsub(s, i, (k - i));
		i = k;
	}
	cut[j] = 0;
	return (cut);
}
