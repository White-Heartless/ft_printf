/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffacilla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 10:41:30 by ffacilla          #+#    #+#             */
/*   Updated: 2021/01/14 10:43:48 by ffacilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Copies n characters from memory area source to
** memory area dest
** will generate issues if the memory blocks overlap.
** memmove solves this issue
*/

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char		*destination;
	const unsigned char	*source;

	if (dest == NULL && src == NULL)
		return (NULL);
	destination = (unsigned char*)dest;
	source = (unsigned char*)src;
	while (n--)
		*destination++ = *source++;
	return (dest);
}
