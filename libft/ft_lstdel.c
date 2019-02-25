/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lloncham <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/15 16:29:15 by lloncham          #+#    #+#             */
/*   Updated: 2018/11/15 17:56:10 by lloncham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	while ((*(alst))->next != NULL)
	{
		del((*(alst))->content, (*(alst))->content_size);
		free(*alst);
		*alst = (*(alst))->next;
	}
	del((*(alst))->content, (*(alst))->content_size);
	free(*alst);
	*alst = NULL;
}
