/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffacilla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 11:31:34 by ffacilla          #+#    #+#             */
/*   Updated: 2021/01/14 10:52:48 by ffacilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** when passed a lowercase alphabet, returns its uppercase
** otherwise returns the unchanged char
*/

int	ft_toupper(int character)
{
	int c;

	c = character;
	if ((c >= 'a' && c <= 'z'))
		return (c - 32);
	else
		return (character);
}
