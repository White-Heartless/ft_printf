/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffacilla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 10:48:51 by ffacilla          #+#    #+#             */
/*   Updated: 2021/01/11 10:55:30 by ffacilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Compares the first n bytes of
** memory area str1 and str2
** returns value < 0 if str1 is lesser
** returns 0 if both are equal
** returns value > 0 if str1 is greater
*/

int		ft_memcmp(const void *str1, const void *str2, size_t n)
{
	unsigned char *s1;
	unsigned char *s2;

	s1 = (unsigned char*)str1;
	s2 = (unsigned char*)str2;
	while (n-- > 0)
	{
		if (*s1++ != *s2++)
			return (s1[-1] - s2[-1]);
	}
	return (0);
}
