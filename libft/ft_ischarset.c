/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ischarset.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffacilla <marvin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/20 21:52:35 by ffacilla          #+#    #+#             */
/*   Updated: 2021/01/20 21:52:35 by ffacilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Takes a character and a string as input and returns:
** the matching char if it is in the set, or -1 otherwise
*/

int	ft_ischarset(int character, char *charset)
{
	while (*charset)
	{
		if (character == *charset)
			return (*charset);
		charset++;
	}
	return (-1);
}
