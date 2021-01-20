/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   found_percent.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffacilla <marvin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/20 22:16:43 by ffacilla          #+#    #+#             */
/*   Updated: 2021/01/20 22:16:43 by ffacilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/ft_printf.h"

t_variables	found_percent(t_variables v)
{
	v.str++;
	if((v.conv_spec = ft_ischarset(*v.str, "diuxXfegcspn%")) >= 0)
	{
		if (v.conv_spec == 'd')
			{
			v.num = va_arg(v.arguments, int);
			ft_putnbr_fd(v.num, 1, &v.counter);
			v.str++;
			v.to_ret = v.to_ret +v.counter;
			v.counter = 0;
		}
		else if (v.conv_spec == '%')
		{
			ft_putchar_fd('%', 1);
			v.str++;
			v.to_ret++;
		}
		else if (v.conv_spec == 'c')
		{
			v.chr = va_arg(v.arguments, int);
			ft_putchar_fd(v.chr, 1);
			v.str++;
			v.to_ret++;
		}
	}
	return (v);
}
