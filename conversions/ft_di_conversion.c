/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_di_conversion.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffacilla <marvin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 22:16:43 by ffacilla          #+#    #+#             */
/*   Updated: 2021/01/21 22:16:43 by ffacilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static char			*ft_ntoa(long long n)
{
	size_t		ln;
	char		*arr;
	size_t		i;
	int			numlen;
	long long	divisor;

	ln = (n < 0) ? ((size_t)n * -1) : ((size_t)n);
	numlen = (n < 0) ? (2) : (1);
	i = 1;
	while (ln >= (i *= 10))
		numlen++;
	if (!(arr = (char *)malloc((sizeof(char) * numlen) + 1)))
		return (NULL);
	arr[0] = (n < 0) ? '-' : arr[0];
	i = numlen - 1;
	divisor = 10;
	while (n < 0 ? (i > 0 && i < 99) : (i >= 0 && i < 99))
	{
		arr[i] = '0' + (ln % divisor);
		i--;
		ln /= 10;
	}
	arr[numlen] = 0;
	return (arr);
}

static t_variables	ft_add_precision(t_variables v, size_t len)
{
	char *p;
	int i;

	if (!(p = (char *)malloc(len + 1)))
	{
		v.error = 1;
		return (v);
	}
	i = 0;
	while (i < len)
		p[i++] = '0';
	p[i] = 0;
	v.buffer = ft_strjoinfree(p,v.buffer,2);
	return (v);
}

t_variables			ft_di_conversion(t_variables v)
{
	if (v.length == 1)
		v.buffer = ft_ntoa((long long)va_arg(v.arguments, short));
	else if (v.length == 2)
		v.buffer = ft_ntoa((long long)va_arg(v.arguments, char));
	else if (v.length == 3)
		v.buffer = ft_ntoa((long long)va_arg(v.arguments, long));
	else if (v.length == 4)
		v.buffer = ft_ntoa(va_arg(v.arguments, long long));
	else
		v.buffer = ft_ntoa((long long)va_arg(v.arguments, int));
	if (v.flags[1] == 1 && v.buffer[0] != '-')
		v.buffer = ft_strjoinfree("+",v.buffer,1);
	else if (v.flags[3] == 1 && v.buffer[0] != '-')
		v.buffer = ft_strjoinfree(" ",v.buffer,1);
	if (ft_strlen(v.buffer) < v.precision)
		v = ft_add_precision(v, v.precision - ft_strlen(v.buffer));
//gli spazi vanno a destra se ce il meno, a sinistra se ce 0 o niente
		/*
		v.str = v.str + v.counter -1;
		v.to_ret = v.to_ret + v.counter;*/
	return (v);
}
