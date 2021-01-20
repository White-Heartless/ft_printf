/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffacilla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 11:32:53 by ffacilla          #+#    #+#             */
/*   Updated: 2021/01/14 10:53:11 by ffacilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** when passed and uppercase alphabet, returns its lowercase
** otherwise returns the unchanged char
*/

int	ft_tolower(int character)
{
	int c;

	c = character;
	if ((c >= 'A' && c <= 'Z'))
		return (c + 32);
	else
		return (character);
}
