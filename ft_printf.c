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

int	ft_printf(const char *to_parse, ...)
{
	t_variables	v;
	//wchar_t test = 0x3f;

	va_start(v.arguments, to_parse);
	v.to_ret = 0;
	v.str = (char *)to_parse;
	while (*v.str)
	{
		if (*v.str != '%')
		{
			write(1, &(*v.str++), 1);
			v.to_ret++;
		}
		else
		{
			v = found_percent(v);
		}
	}
	va_end(v.arguments);
	return (v.to_ret);
}

int	main(void)
{
	int i= 0;
	i = ft_printf("ciao\nmam>%d<ma>%d<xxx>%d<ttt>%%<\nchar>%c<\n", 13, 42, 0,'c');
	printf(">>%d<<\n",i);
	i = printf("ciao\nmam>%d<ma>%d<xxx>%d<ttt>%%<\nchar>%c<\n", 13, 42, 0,'c');
	printf(">>%d<<\n",i);

}
