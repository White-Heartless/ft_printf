/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffacilla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 10:56:56 by ffacilla          #+#    #+#             */
/*   Updated: 2021/01/14 09:54:01 by ffacilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Takes string source and concatenates up to n chars from it
** after the end of destination, replacing the '\0' in destination,
** and adding the '\0' from the source at the end.
** This function guarantees that the '\0' will always be placed
** dest HAS to be big enough to contain n chars, or you will segfault
*/

size_t	ft_strlcat(char *dest, const char *src, size_t n)
{
	char	*d;
	size_t	left;
	size_t	dlen;
	char	*sr;

	d = dest;
	sr = (char *)src;
	left = n;
	while (left-- != 0 && *dest != 0)
		dest++;
	dlen = dest - d;
	left = n - dlen;
	if (left == 0)
		return (dlen + ft_strlen(src));
	while (*sr)
	{
		if (left != 1)
		{
			*dest++ = *sr;
			left--;
		}
		sr++;
	}
	*dest = 0;
	return (dlen + (sr - src));
}
