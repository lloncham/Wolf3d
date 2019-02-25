/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lloncham <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 11:13:28 by lloncham          #+#    #+#             */
/*   Updated: 2018/11/16 11:48:54 by lloncham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char	*new;
	size_t	fst;
	size_t	lst;
	int		j;

	if (s == NULL)
		return (NULL);
	fst = 0;
	j = 0;
	lst = ft_strlen(s) - 1;
	if (*s == '\0')
		return (ft_strnew(0));
	while (s[fst] && (s[fst] == ' ' || s[fst] == '\n' || s[fst] == '\t'))
		fst++;
	while (lst > fst && (s[lst] == ' ' || s[lst] == '\n' || s[lst] == '\t'))
		lst--;
	if (!(new = ft_strnew(lst - fst + 1)))
		return (NULL);
	while (fst <= lst)
		new[j++] = s[fst++];
	new[j] = '\0';
	return (new);
}
