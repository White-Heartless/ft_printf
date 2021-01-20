/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffacilla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 17:26:43 by ffacilla          #+#    #+#             */
/*   Updated: 2021/01/13 17:27:02 by ffacilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*toret;
	t_list	*tmp;

	toret = NULL;
	while (lst)
	{
		if (!(tmp = ft_lstnew(f(lst->content))))
		{
			ft_lstclear(&toret, del);
			return (NULL);
		}
		ft_lstadd_back(&toret, tmp);
		lst = lst->next;
	}
	return (toret);
}
