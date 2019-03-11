/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louali <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/15 14:47:51 by louali            #+#    #+#             */
/*   Updated: 2018/11/15 15:27:53 by louali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *start;
	t_list *list;

	if (lst == NULL)
		return (NULL);
	list = f(lst);
	start = list;
	while (lst->next != NULL)
	{
		list->next = f(lst->next);
		lst = lst->next;
		list = list->next;
	}
	return (start);
}
