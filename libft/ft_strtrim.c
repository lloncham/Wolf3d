/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louali <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 15:27:38 by louali            #+#    #+#             */
/*   Updated: 2018/11/15 18:27:53 by louali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_count(char const *s)
{
	size_t	i;
	size_t	count;

	count = 0;
	i = 0;
	while ((s[i] == ' ' || s[i] == '\n' || s[i] == '\t') && s[i])
		i++;
	if (s[i] == '\0')
		return (i);
	while (s[i])
	{
		count++;
		i++;
	}
	i--;
	while ((s[i] == ' ' || s[i] == '\n' || s[i] == '\t'))
	{
		count--;
		i--;
	}
	return (count);
}

char			*ft_strtrim(char const *s)
{
	size_t	len;
	size_t	i;
	size_t	t;
	char	*str;

	if (s == NULL)
		return (NULL);
	len = ft_count(s);
	t = 0;
	if ((str = malloc(sizeof(char) * len + 1)) == NULL)
		return (NULL);
	i = 0;
	while (s[i] && (s[i] == ' ' || s[i] == '\n' || s[i] == '\t'))
		i++;
	while (len > t)
	{
		str[t] = s[i];
		i++;
		t++;
	}
	str[t] = '\0';
	return (str);
}
