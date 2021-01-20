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

int	ft_printf(const char *to_parse, ...)
{
	va_list arguments;
	char	*str;
	int		num;

	va_start(arguments, to_parse);
	str = (char *)to_parse;
	while (*str)
	{
		if (*str != '%')
		{
			write(1, &(*str), 1);
			str++;
		}
		else
		{
			str++;
			if (ft_strchr(str, 'd') > 0)
			{
				num = va_arg(arguments, int);
				ft_putnbr_fd(num, 1);
				str++;
			}
		}
	}
	va_end(arguments);
	return (1);
}

int	main(void)
{
	ft_printf("ciao mam%dma%dxxx%d\n", 13, 42, 0);
}
