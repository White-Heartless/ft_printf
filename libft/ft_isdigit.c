/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffacilla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 11:21:44 by ffacilla          #+#    #+#             */
/*   Updated: 2021/01/14 10:49:47 by ffacilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Takes a char ass input and returns:
** 1 if the char is a digit
** 0 otherwise
*/

int	ft_isdigit(int character)
{
	int	c;

	c = character;
	if ((c >= '0' && c <= '9'))
		return (1);
	else
		return (0);
}
