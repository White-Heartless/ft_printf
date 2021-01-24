/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_found_conversion.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffacilla <ffacilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 22:16:43 by ffacilla          #+#    #+#             */
/*   Updated: 2021/01/22 17:36:38 by ffacilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libftprintf.h"

t_variables ft_found_conversion(t_variables v)
{
	if (v.tmp == 'd' || v.tmp == 'i')
		v = ft_di_conversion(v);
	else if (v.tmp == 'n')
		v = ft_n_conversion(v);
	else if (v.tmp == 'x' || v.tmp == 'X')
		v = ft_xX_conversion(v);
	else if (v.tmp == 'f')
		v = ft_f_conversion(v);
	else if (v.tmp == '%')//has to manage width unlike printf or does it?
	{
		ft_putchar_fd('%', v.fd);
		v.str++;
		v.to_ret++;
	}
	else if (v.tmp == 'c')
	{
		v.chr = va_arg(v.arguments, int);
		ft_putchar_fd(v.chr, v.fd);
		v.str++;
		v.to_ret++;
	}
	return (v);
}
