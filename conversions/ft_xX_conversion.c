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

int					ft_hexlen(size_t n)
{
	int c;
	size_t pow;

	c = 1;
	pow = 15;
	while (n > pow)
	{
		c++;
		pow = ((pow + 1) * 16) -1;
	}
	return (c + 1);
}

static char			*ft_hextoa(size_t n, t_variables *v)//max hex 16char + 0
{
	char		*arr;
	size_t		i;

	if (v->error == 1)
		return (NULL);
	i = ft_hexlen(n) - 2;
	if (n == 0 && (arr = malloc(1)) && ((arr[0] = 0) == 0))
		return (arr);//ok
	if (!(arr = (char *)malloc(i + 2)) && (v->error = 1))
	{
		v->stmp[0] = 1;
		return (NULL);
	}
	arr[i + 1] = 0;
	while (i < 99)
	{
		if (n % 16 > 9 && *(v->str + v->i) == 'x')
			arr[i--] = 'a' + (n % 16) - 10;
		else if (n % 16 > 9 && *(v->str + v->i) == 'X')
			arr[i--] = 'A' + (n % 16) - 10;
		if (n % 16 <= 9)
			arr[i--] = '0' + (n % 16);
		n /= 16;
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
	if ((v.error == 1) || (!(p = (char *)malloc(len + 1)) && (v.error = 1)))
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

	if (v.error == -1 || !(p = (char *)malloc(len + 1)))
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

t_variables			ft_xX_conversion(t_variables v)
{
	if (v.length == 1 || v.length == 2)
		v.buffer = ft_hextoa((size_t)va_arg(v.arguments, unsigned int), &v);
	else if (v.length == 3)
		v.buffer = ft_hextoa((size_t)va_arg(v.arguments, unsigned long), &v);
	else if (v.length == 4)
		v.buffer = ft_hextoa((size_t)va_arg(v.arguments, size_t), &v);
	else
		v.buffer = ft_hextoa((size_t)va_arg(v.arguments, unsigned int), &v);
	write(FD,"",0);
	if (ft_strlen(v.buffer) - 1 < (size_t)v.precision)
		v = ft_add_precision(v, v.precision - ft_strlen(v.buffer) - 1);
	if (v.flags[2] == 1 && *(v.str + v.i) == 'x')
		if (/*v.pflag == 1 && v.precision == 0 && */v.stmp[0] != 1)
			v.buffer = ft_prefixfree("0x", &v.buffer);
	if (v.flags[2] == 1 && *(v.str + v.i) == 'X')
		if (/*v.pflag == 1 && v.precision != 0  && */v.stmp[0] != 1)
			v.buffer = ft_prefixfree("0X", &v.buffer);
	if (ft_strlen(v.buffer) < (size_t)v.width)
		v = ft_add_width(v, v.width - ft_strlen(v.buffer));
	if (v.error == 1)
		return (v);
	ft_putstr_fd(v.buffer,FD);
	v.str = v.str + v.i + 1;
	v.to_ret = v.to_ret + ft_strlen(v.buffer);
	return (v);
}
