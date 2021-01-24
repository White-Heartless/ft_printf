/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffacilla <ffacilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/20 18:50:16 by ffacilla          #+#    #+#             */
/*   Updated: 2021/01/22 18:58:34 by ffacilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libftprintf.h"

static t_variables	ft_init_vars2(t_variables v)
{
	v.plus = (char *)malloc(2);
	v.space = (char *)malloc(2);
	v.plus[0] = '+';
	v.plus[1] = 0;
	v.space[0] = ' ';
	v.space[1] = 0;
	return (v);
}

static t_variables	ft_init_vars(t_variables v)
{
	int i;

	i = 0;
	v.to_ret = 0;
	v.counter = 0;
	v.num = 0;
	v.width = 0;
	v.length = 0;
	v.precision = 0;
	v.flags[0] = 0;
	v.flags[1] = 0;
	v.flags[2] = 0;
	v.flags[3] = 0;
	v.flags[4] = 0;
	v.pflag = 0;
	v.fd = FD;
	v.i = 0;
	v.error = 0;
	v.buffer = malloc(1);
	while (i < 11)
		v.stmp[i++] = 0;
	v = ft_init_vars2 (v);
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
	v.width = 0;
	v.length = 0;
	v.precision = 0;
	v.flags[0] = 0;
	v.flags[1] = 0;
	v.flags[2] = 0;
	v.flags[3] = 0;
	v.flags[4] = 0;
	v.pflag = 1;
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
			if (v.error == 1)
				return (-1);
		}
	}
	va_end(v.arguments);
	return (v.to_ret);
}


int	main(void)
{
	unsigned int a = 155;
	unsigned int k = a;
	/*int i= 0;
	int j= 0;*/
	/*j =*/ ft_printf("|%#3.5X|\n", a);
	/*i =*/    printf("|%#3.5X|\n", k);
	/*printf(">>%d<<\n",j);
	printf(">>%d<<\n",i);*/
		/*j =*/ ft_printf("|%#5.3X|\n", 13);
	/*i =*/    printf("|%#5.3X|\n", 13);
		/*j =*/ ft_printf("|%#.0X|\n", 9);
	/*i =*/    printf("|%#.0X|\n", 9);
		/*j =*/ ft_printf("|%#5.0X|\n", 15678);
	/*i =*/    printf("|%#5.0X|\n", 15678);
}

