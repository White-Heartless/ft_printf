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
		}
	}
	va_end(v.arguments);
	return (v.to_ret);
}

int	main(void)
{
	int i= 0;
	int j= 0;
	j = ft_printf("%d\n", 13);
	i =    printf("%d\n", 13);
	printf(">>%d<<",j);
	printf(">>%d<<\n",i);
	printf("_/T\\_/T\\_/T\\_/T\\_/T\\_\n");
	j = ft_printf("%d\n", 'a');
	i =    printf("%d\n", 'a');
	printf(">>%d<<",j);
	printf(">>%d<<\n",i);
	printf("_/T\\_/T\\_/T\\_/T\\_/T\\_\n");
	j = ft_printf("%5d\n", 42);
	i =    printf("%5d\n", 42);
	printf(">>%d<<",j);
	printf(">>%d<<\n",i);
	printf("_/T\\_/T\\_/T\\_/T\\_/T\\_\n");
	j = ft_printf("%05d\n", 43);
	i =    printf("%05d\n", 43);
	printf(">>%d<<",j);
	printf(">>%d<<\n",i);
	printf("_/T\\_/T\\_/T\\_/T\\_/T\\_\n");
	j = ft_printf("%5.3d\n", 14);
	i =    printf("%5.3d\n", 14);
	printf(">>%d<<",j);
	printf(">>%d<<\n",i);
	printf("_/T\\_/T\\_/T\\_/T\\_/T\\_\n");
	j = ft_printf("%3.5d\n", 15);
	i =    printf("%3.5d\n", 15);
	printf(">>%d<<",j);
	printf(">>%d<<\n",i);
	printf("_/T\\_/T\\_/T\\_/T\\_/T\\_\n");
	j = ft_printf("%3.5d\n", -16);
	i =    printf("%3.5d\n", -16);
	printf(">>%d<<",j);
	printf(">>%d<<\n",i);
	printf("_/T\\_/T\\_/T\\_/T\\_/T\\_\n");
	j = ft_printf("|%-5.3d|\n", -17);
	i =    printf("|%-5.3d|\n", -17);
	printf(">>%d<<",j);
	printf(">>%d<<\n",i);
	printf("_/T\\_/T\\_/T\\_/T\\_/T\\_\n");
	j = ft_printf("|%.d|\n", 0);
	i =    printf("|%.d|\n", 0);
	printf(">>%d<<",j);
	printf(">>%d<<\n",i);
	printf("_/T\\_/T\\_/T\\_/T\\_/T\\_\n");
	j = ft_printf("|%-5.0d|\n", 19);
	i =    printf("|%-5.0d|\n", 19);
	printf(">>%d<<",j);
	printf(">>%d<<\n",i);
	printf("_/T\\_/T\\_/T\\_/T\\_/T\\_\n");
	j = ft_printf("|%5.0d|\n", 0);
	i =    printf("|%5.0d|\n", 0);
	printf(">>%d<<",j);
	printf(">>%d<<\n",i);
	printf("_/T\\_/T\\_/T\\_/T\\_/T\\_\n");
}

