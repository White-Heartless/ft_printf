/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffacilla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 11:17:32 by ffacilla          #+#    #+#             */
/*   Updated: 2021/01/14 11:14:29 by ffacilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** extracts an integer from a string
** the string will have an arbitrary number of whitespaces
** as defined by isspace(3),
** followed by a single optional sign (+ or -),
** followed by a base 10 number.
*/

int	ft_atoi(const char *s1)
{
	int				sign;
	unsigned int	result;

	sign = 1;
	result = 0;
	while (*s1 == ' ' || (*s1 >= 9 && *s1 <= 13))
		s1++;
	if (*s1 == '+' || *s1 == '-')
	{
		if (*s1 == '-')
			sign = -1;
		s1++;
	}
	while (*s1 >= '0' && *s1 <= '9')
	{
		result = result * 10 + (*s1 - '0');
		s1++;
		if (result > INT_MAX)
			break ;
	}
	if ((result == (unsigned int)INT_MAX + 1 && sign == -1)
			|| result <= INT_MAX)
		return (sign * result);
	return (sign == 1 ? -1 : 0);
}
