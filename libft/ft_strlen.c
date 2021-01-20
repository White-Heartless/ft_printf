/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffacilla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 10:50:28 by ffacilla          #+#    #+#             */
/*   Updated: 2021/01/11 10:58:04 by ffacilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Takes a string as input and returns the length of the string,
** excluding the terminator character.
*/

size_t	ft_strlen(const char *string)
{
	size_t length;

	length = 0;
	while (string[length])
		length++;
	return (length);
}
