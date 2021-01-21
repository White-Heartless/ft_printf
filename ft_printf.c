/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffacilla <ffacilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/20 18:50:16 by ffacilla          #+#    #+#             */
/*   Updated: 2021/01/20 19:10:08 by ffacilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/ft_printf.h"
#include <stdio.h>

static t_variables	ft_init_vars(t_variables v)
{
	int i;

	i = 0;
	v.to_ret = 0;
	v.counter = 0;
	v.num = 0;
	v.width = -1;
	v.length = -1;
	v.precision = -1;
	v.flags[0] = 0;
	v.flags[1] = 0;
	v.flags[2] = 0;
	v.flags[3] = 0;
	v.flags[4] = 0;
	v.fd = FD;
	v.i = 0;
	error = 0;
	while (i < 11)
		v.stmp[i++] = 0;
	return (v);
}

t_variables			ft_flush_v(t_variables v)
{
	int i;

	i = 0;
	while (i < 11)
		v.stmp[i++] = 0;
	v.i = 0;
	v.counter = 0;
	v.num = 0;
	v.width = -1;
	v.length = -1;
	v.precision = -1;
	v.flags[0] = 0;
	v.flags[1] = 0;
	v.flags[2] = 0;
	v.flags[3] = 0;
	v.flags[4] = 0;
	return (v);
}

int					ft_printf(const char *to_parse, ...)
{
	t_variables	v;
	//wchar_t test = 0x3f;

	va_start(v.arguments, to_parse);
	v.str = (char *)to_parse;
	v = ft_init_vars(v);
	while (*v.str)
	{
		if (*v.str != '%')
		{
			write(v.fd, &(*v.str++), 1);
			v.to_ret++;
		}
		else
		{
			v = ft_found_percent(v);
		}
	}
	va_end(v.arguments);
	return (v.to_ret);
}

int	main(void)
{
	int i= 14;
	long int b = 166;
	int j= 0;
	j = ft_printf("ciao\nmam>%d<ma>%d<xxx>%d<ttt>%ld<\nchar>%c<\n", 13, 166, 0,b,'w');
	i =    printf("ciao\nmam>%d<ma>%d<xxx>%d<ttt>%ld<\nchar>%c<\n", 13, 166, 0,b,'w');
	printf(">>%d<<\n",j);
	printf(">>%d<<\n",i);
}
