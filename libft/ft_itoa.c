/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffacilla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 15:36:52 by ffacilla          #+#    #+#             */
/*   Updated: 2021/01/13 18:00:33 by ffacilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**Takes an integer as input and puts it into
**a freshly allocated array.
*/

char	*ft_itoa(int n)
{
	long long	ln;
	char		*arr;
	long long	i;
	int			numlen;
	int			divisor;

	ln = (n < 0) ? ((long long)n * -1) : ((long long)n);
	numlen = (n < 0) ? (2) : (1);
	i = 1;
	while (ln >= (i *= 10))
		numlen++;
	if (!(arr = (char *)malloc((sizeof(char) * numlen) + 1)))
		return (NULL);
	arr[0] = (n < 0) ? '-' : arr[0];
	i = numlen - 1;
	divisor = 10;
	while (n < 0 ? (i > 0) : (i >= 0))
	{
		arr[i] = '0' + (ln % divisor);
		i--;
		ln /= 10;
	}
	arr[numlen] = 0;
	return (arr);
}
