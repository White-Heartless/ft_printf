/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffacilla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 10:46:03 by ffacilla          #+#    #+#             */
/*   Updated: 2021/01/14 10:44:42 by ffacilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Copies n characters from memory area source to
** memory area dest
** this will not generate issues if the memory blocks overlap.
** unlike memcpy
*/

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*destination;
	unsigned char	*source;

	if (dest == NULL && src == NULL)
		return (NULL);
	destination = (unsigned char*)dest;
	source = (unsigned char*)src;
	if (destination < source)
	{
		while (n--)
			*destination++ = *source++;
	}
	else
	{
		destination = (unsigned char*)dest + (n - 1);
		source = (unsigned char*)src + (n - 1);
		while (n--)
			*destination-- = *source--;
	}
	return (dest);
}
