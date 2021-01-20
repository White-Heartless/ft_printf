/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffacilla <ffacilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/20 17:05:55 by ffacilla          #+#    #+#             */
/*   Updated: 2021/01/20 18:12:20 by ffacilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/ft_printf.h"

int	ft_printf(const char *to_parse, ...)
{
	va_list arguments;
	char	*str;

	str = (char *)to_parse;
	while (*str != '%' && *str)
	{
		write(1, &(*str), 1);
		str++;
	}
	va_end(arguments);
	return (1);
}

int	main(void)
{
	ft_printf("ciao mamma\n");
}
