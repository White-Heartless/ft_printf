/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffacilla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 10:39:59 by ffacilla          #+#    #+#             */
/*   Updated: 2021/01/11 10:53:47 by ffacilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Fills a block of memory with 0 ('\0') up to n bytes
** s ==> Starting address of memory to be filled
** n   ==> Number of bytes to be filled starting
**         from ptr to be filled
*/

void	ft_bzero(void *s, size_t n)
{
	unsigned char *address;

	address = (unsigned char*)s;
	while (n-- > 0)
		*address++ = '\0';
}
