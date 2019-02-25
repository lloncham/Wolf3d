/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lloncham <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/15 14:04:30 by lloncham          #+#    #+#             */
/*   Updated: 2018/11/20 12:20:56 by lloncham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*n;

	if (!(n = (t_list *)malloc(sizeof(t_list))))
		return (NULL);
	if (content == NULL)
	{
		n->content = NULL;
		n->content_size = 0;
	}
	else
	{
		if (!(n->content = ft_memalloc(content_size)))
			return (NULL);
		ft_memcpy(n->content, content, content_size);
		n->content_size = content_size;
	}
	n->next = NULL;
	return (n);
}
