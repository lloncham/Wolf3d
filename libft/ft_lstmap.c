/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lloncham <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/15 18:13:22 by lloncham          #+#    #+#             */
/*   Updated: 2018/11/16 11:12:24 by lloncham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *fresh;
	t_list *first;

	fresh = f(lst);
	first = fresh;
	if (lst == NULL)
		return (NULL);
	while (lst->next != NULL)
	{
		fresh->next = f(lst->next);
		fresh = fresh->next;
		lst = lst->next;
	}
	fresh->next = NULL;
	return (first);
}
