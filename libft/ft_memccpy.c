/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffacilla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 10:43:36 by ffacilla          #+#    #+#             */
/*   Updated: 2021/01/11 10:55:12 by ffacilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Copies characters from memory area source to
** memory area dest until it encounters
** character c or until it has copied n bytes,
** whichever comes first
*/

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	unsigned char		*destination;
	const unsigned char	*source;

	destination = (unsigned char*)dest;
	source = (unsigned char*)src;
	while (n--)
	{
		*destination = *source;
		if (*source == (unsigned char)c)
			return (destination + 1);
		destination++;
		source++;
	}
	return (NULL);
}
