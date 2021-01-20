/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffacilla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 17:27:08 by ffacilla          #+#    #+#             */
/*   Updated: 2021/01/13 17:35:03 by ffacilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*add;

	if (!(add = (t_list *)malloc(sizeof(t_list))))
		return (NULL);
	add->next = NULL;
	add->content = content;
	return (add);
}
