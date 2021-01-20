/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffacilla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 11:40:14 by ffacilla          #+#    #+#             */
/*   Updated: 2021/01/11 11:45:08 by ffacilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** contiguously allocates amount bytes of memory and returns a pointer
** to the memory area created
*/

void	*ft_calloc(size_t count, size_t amount)
{
	void	*address;

	address = (void *)malloc(amount * count);
	if (address == NULL)
		return (NULL);
	ft_memset(address, 0, amount * count);
	return (address);
}
