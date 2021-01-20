/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffacilla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 17:24:11 by ffacilla          #+#    #+#             */
/*   Updated: 2021/01/13 17:24:47 by ffacilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*list;
	t_list	*tmp;

	if (lst && *lst)
	{
		list = *lst;
		*lst = NULL;
		while (list)
		{
			tmp = list->next;
			del(list->content);
			free(list);
			list = tmp;
		}
	}
}
