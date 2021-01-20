/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffacilla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 11:29:58 by ffacilla          #+#    #+#             */
/*   Updated: 2021/01/14 10:52:23 by ffacilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Takes a char as input and returns:
** nonzero if it is printable
** 0 otherwise
*/

int	ft_isprint(int character)
{
	int c;

	c = character;
	if (c >= 32 && c <= 126)
		return (1);
	else
		return (0);
}
