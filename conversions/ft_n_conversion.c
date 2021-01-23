/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_n_conversion.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffacilla <ffacilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 22:16:43 by ffacilla          #+#    #+#             */
/*   Updated: 2021/01/22 20:09:30 by ffacilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

t_variables			ft_n_conversion(t_variables v)
{
	int			*a;
	char		*b;
	short		*c;
	long		*d;
	long long	*e;
	if (v.length == 1)
	{
		c = va_arg(v.arguments, short *);
		*c = v.to_ret;
	}
	else if (v.length == 2)
	{
		b = va_arg(v.arguments, char *);
		*b = v.to_ret;
	}
	else if (v.length == 3)
	{
		d = va_arg(v.arguments, long *);
		*d = v.to_ret;
	}
	else if (v.length == 4){
		e = va_arg(v.arguments, long long *);
		*e = v.to_ret;
	}
	else
	{
		a = va_arg(v.arguments, int *);
		*a = v.to_ret;
	}
	v.str = v.str + v.i + 1;
	return (v);
}
