/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_di_conversion.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffacilla <ffacilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 22:16:43 by ffacilla          #+#    #+#             */
/*   Updated: 2021/01/22 20:09:30 by ffacilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

static char			*ft_ntoa(long long n, t_variables *v)
{
	size_t		ln;
	char		*arr;
	size_t		i;
	int			numlen;

	ln = (n < 0) ? ((size_t)n * -1) : ((size_t)n);
	numlen = (n < 0) ? (2) : (1);
	i = 1;
	while (ln >= (i *= 10))
		numlen++;
	if (n == 0 && (arr = malloc(1)) && ((arr[0] = 0) == 0))
		return (arr);
	if (!(arr = (char *)malloc((sizeof(char) * numlen) + 1)) && (v->error = 1))
		return (NULL);
	arr[0] = (n < 0) ? '-' : arr[0];
	i = numlen - 1;
	arr[numlen] = 0;
	while (n < 0 ? (i > 0 && i < 99) : (i < 99))
	{
		arr[i] = '0' + (ln % 10);
		i--;
		ln /= 10;
	}
	return (arr);
}

static t_variables	ft_add_precision(t_variables v, size_t len)
{
	char *p;
	size_t i;

	if (v.buffer[0] != '-')
		len++;
	else if(v.buffer[0] != '0')
		len += 2;
	if (v.buffer[0] == '0' && v.precision == 0 && v.pflag == 1)
	{
		v.buffer[0] = ' ';
		return (v);
	}
	if (!(p = (char *)malloc(len + 1)) && (v.error = 1))
		return (v);
	i = 0;
	if (v.buffer[0] == '-')
	{
		p[0] = '-';
		v.buffer[i++] = '0';
	}
	while (i < len)
		p[i++] = '0';
	p[i] = 0;
	v.buffer = ft_strjoinfree(&p,&v.buffer,2);
	return (v);
}

static t_variables	ft_add_width(t_variables v, size_t len)
{
	char *p;
	size_t i;
	if (!(p = (char *)malloc(len + 1)))
	{
		v.error = 1;
		return (v);
	}
	i = 0;
	while (i < len)
		p[i++] = (v.flags[4] == 1) ? '0' :' ';
	p[i] = 0;
	if (v.flags[0] == 1)
		v.buffer = ft_strjoinfree(&v.buffer, &p, 2);
	else
		v.buffer = ft_strjoinfree(&p, &v.buffer, 2);
	return (v);
}

t_variables			ft_di_conversion(t_variables v)
{
	if (v.length == 1 || v.length == 2)
		v.buffer = ft_ntoa((long long)va_arg(v.arguments, int), &v);
	else if (v.length == 3)
		v.buffer = ft_ntoa((long long)va_arg(v.arguments, long), &v);
	else if (v.length == 4)
		v.buffer = ft_ntoa(va_arg(v.arguments, long long), &v);
	else
		v.buffer = ft_ntoa((long long)va_arg(v.arguments, int), &v);
	if (v.flags[1] == 1 && v.buffer[0] != '-')
		v.buffer = ft_strjoinfree((char **)"+", &v.buffer, 1);
	else if (v.flags[3] == 1 && v.buffer[0] != '-')
		v.buffer = ft_strjoinfree((char **)" ", &v.buffer, 1);
	write(FD,"",0);
	if (v.buffer[0] == '0' && v.precision == 0 && v.pflag == 1)
		v = ft_add_precision(v, 0);
	if (ft_strlen(v.buffer) - 1 < (size_t)v.precision)
		v = ft_add_precision(v, v.precision - ft_strlen(v.buffer) - 1);
	if (ft_strlen(v.buffer) < (size_t)v.width)
		v = ft_add_width(v, v.width - ft_strlen(v.buffer));
	ft_putstr_fd(v.buffer,FD);
	v.str = v.str + v.i + 1;
	v.to_ret = v.to_ret + ft_strlen(v.buffer);
	return (v);
}
