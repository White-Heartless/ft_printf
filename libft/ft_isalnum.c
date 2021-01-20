/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffacilla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 11:22:56 by ffacilla          #+#    #+#             */
/*   Updated: 2021/01/14 10:51:25 by ffacilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Takes a char as input and returns:
** nonzero if it is an alphabetic char or a digit
** 0 otherwise
*/

int	ft_isalnum(int character)
{
	int c;

	c = character;
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (1);
	else if ((c >= '0' && c <= '9'))
		return (1);
	else
		return (0);
}
