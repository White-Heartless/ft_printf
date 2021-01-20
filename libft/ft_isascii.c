/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffacilla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 11:26:27 by ffacilla          #+#    #+#             */
/*   Updated: 2021/01/11 11:35:10 by ffacilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Takes a character as input and returns:
** nonzero if it is an ascii char
** 0 otherwise
*/

int	ft_isascii(int character)
{
	if (character >= 0 && character <= 127)
		return (1);
	else
		return (0);
}
