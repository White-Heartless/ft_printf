/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffacilla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 11:02:13 by ffacilla          #+#    #+#             */
/*   Updated: 2021/01/14 11:04:27 by ffacilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** copies up to size -1 chars from src to dest, NUL-terminating the result
** if size is > 0
** Returns the total lenght of the string it tries to create
*/

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int strlen;
	unsigned int i;

	if (dest == NULL || src == NULL)
		return (0);
	strlen = 0;
	i = 0;
	while (src[strlen] != 0)
		strlen++;
	if (size != 0)
	{
		while (src[i] != 0 && i < (size - 1))
		{
			dest[i] = src[i];
			i++;
		}
		dest[i] = 0;
	}
	return (strlen);
}
