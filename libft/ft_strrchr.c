/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffacilla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 11:13:52 by ffacilla          #+#    #+#             */
/*   Updated: 2021/01/14 10:09:53 by ffacilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Takes string str and finds the last occurrence of char c
** typecasted to unsigned char.
** returns a pointer to the character found or Null if it is not present in str
*/

char	*ft_strrchr(const char *str, int c)
{
	char *start;
	char *s;

	start = (char *)str;
	s = (char *)str + ft_strlen(str);
	while (s >= start)
	{
		if (*s == (unsigned char)c)
			return (s);
		s--;
	}
	return (NULL);
}
