/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_f_conversion.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffacilla <ffacilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 22:16:43 by ffacilla          #+#    #+#             */
/*   Updated: 2021/01/22 20:09:30 by ffacilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

void    fillarr(char *arr, size_t numlen, double n, t_variables v)
{
    size_t	i;
	size_t	fraction;
	size_t	whole;

	whole = (n < 0) ? ((size_t)n * -1) : ((size_t)n);
	if (n < 0)
		fraction = (size_t)(-n * f_power(v.precision)) % (size_t)(f_power(v.precision));
	else
		fraction = (size_t)(n * f_power(v.precision)) % (size_t)(f_power(v.precision));
    arr[0] = (n < 0) ? '-' : arr[0];
    arr[(i = numlen - 1) + 1] = 0;
    if (fraction % 10 > 4)
        fraction += 10;
    fraction /= 10;
    while (i > numlen - v.precision -1)
    {
        arr[i--] = '0' + (fraction % 10);
		fraction /= 10;
    }
	(v.precision != 0) ? arr[i--] = '.' : 0;
    while (n < 0 ? (i > 0 && i < 99) : (i < 99))
    {
        arr[i--] = '0' + (whole % 10);
	    whole /= 10;
    }
}

static char			*ft_dtoa(double n, t_variables *v)
{
    size_t  i;
    size_t	ln;
	char	*arr;
    int		numlen;

    ln = (n < 0) ? ((size_t)n * -1) : ((size_t)n);
	//printf("precision: %d\n",v->precision);
	numlen = (n < 0) ? (3 + v->precision) : (2 + v->precision);
	i = 1;
	while (ln >= (i *= 10))
		numlen++;
	if (n == 0)
		return (ft_zeroftoa(v));
	/*else if (n != n || n == INFINITY || n == -INFINITY)
	    return (nanorinf(v));*/
	//printf("n:        %f\n",n);
	if (v->precision == 0 && v->pflag ==1)
		numlen--;
	if (!(arr = (char *)malloc(numlen + 1)))
	    return (NULL);
	fillarr(arr, numlen,n,*v);
	//printf("%s\n",arr);
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

t_variables			ft_f_conversion(t_variables v)
{
	if (v.precision == 0 && v.pflag == 0)
		v.precision = 6;
	v.buffer = ft_dtoa(va_arg(v.arguments, double), &v);
	if (v.flags[1] == 1 && v.buffer[0] != '-')
		v.buffer = ft_prefixfree("+", &v.buffer);
	else if (v.flags[3] == 1 && v.buffer[0] != '-')
		v.buffer = ft_prefixfree(" ", &v.buffer);
	write(FD,"",0);
	if (ft_strlen(v.buffer) - 1 < (size_t)v.precision)
		v = ft_add_precision(v, v.precision - ft_strlen(v.buffer) - 1);
	if (ft_strlen(v.buffer) < (size_t)v.width)
		v = ft_add_width(v, v.width - ft_strlen(v.buffer));
	if (v.error == 1)
		return (v);
	ft_putstr_fd(v.buffer,FD);
	v.str = v.str + v.i + 1;
	v.to_ret = v.to_ret + ft_strlen(v.buffer);
	return (v);
}
