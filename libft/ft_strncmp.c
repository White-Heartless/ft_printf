/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffacilla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 11:16:36 by ffacilla          #+#    #+#             */
/*   Updated: 2021/01/14 10:07:05 by ffacilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** compares s1 and s2, up to n characters
** returns a value lesser, equal , or greater than 0 if
** s1 is lesser, equal, or greater than s2 respectively.
*/

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	if (n == 0)
		return (0);
	while (*s1 && *s2 && *s1 == *s2 && --n)
	{
		s1++;
		s2++;
	}
	if (n == 0 && *s1 == *s2)
		return (0);
	return (*(unsigned char *)s1 - *(unsigned char *)s2);
}
