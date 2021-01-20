/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffacilla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 10:47:18 by ffacilla          #+#    #+#             */
/*   Updated: 2021/01/11 10:54:03 by ffacilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Finds the first occurrence of char c, stopping after n bytes
** str ==> Starting address of memory to be searched
** c   ==> Value to be found
** n   ==> Number of bytes after which to stop
** Return value: pointer to the first occurrence of the char
** or NULL if the char is not found
*/

void	*ft_memchr(const void *str, int c, size_t n)
{
	unsigned char *address;

	address = (unsigned char*)str;
	while (n-- > 0)
	{
		if (*address == (unsigned char)c)
			return (address);
		address++;
	}
	return (NULL);
}
