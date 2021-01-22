/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_found_percent.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffacilla <ffacilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/20 22:16:43 by ffacilla          #+#    #+#             */
/*   Updated: 2021/01/22 17:36:07 by ffacilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libftprintf.h"

static t_variables	ft_set_flag(t_variables v)
{
	if (v.tmp == '-')
		v.flags[0] = 1;
	else if (v.tmp == '+')
		v.flags[1] = 1;
	else if (v.tmp == '#')
		v.flags[2] = 1;
	else if (v.tmp == ' ')
		v.flags[3] = 1;
	else if (v.tmp == '0')
		v.flags[4] = 1;
	if (v.flags[4] == 1 && v.flags[0] == 1)
		v.flags[4] = 0;
	if (v.flags[3] == 1 && v.flags[1] == 1)
		v.flags[3] = 0;
	v.i++;
	return (v);

}

/*possible segfault if a width higher than int limit*/

static t_variables	ft_set_width(t_variables v)
{
	size_t i;

	i = 0;
	if (v.tmp == '*')
	{
		v.num = va_arg(v.arguments, int);
		v.width = v.num;
		v.i++;
	}
	else
	{
		while ((v.tmp = ft_ischarset(*(v.str + v.i), "0123456789")) >= 0)
		{
			v.stmp[i++] = *(v.str + v.i);
			v.i++;
		}
		v.width = ft_atoi(v.stmp);
	}
	i = 0;
	while (i < 11)
		v.stmp[i++] = 0;
	return (v);
}

/*possible segfault if a precision higher than int limit*/

static t_variables	ft_set_precision(t_variables v)
{
	size_t i;

	i = 0;
	v.str++;
	if (*(v.str + v.i) == '*')
	{
		v.num = va_arg(v.arguments, int);
		v.precision = v.num;
		v.i++;
	}
	else
	{
		while ((v.tmp = ft_ischarset(*(v.str + v.i), "0123456789")) >= 0)
		{
			v.stmp[i++] = *(v.str + v.i);
			v.i++;
		}
		v.precision = ft_atoi(v.stmp);
	}
	i = 0;
	while (i < 11)
		v.stmp[i++] = 0;
	return (v);
}

/* h hh l ll = 1,2,3,4*/

static t_variables	ft_set_length(t_variables v)
{
	if (*(v.str + v.i) == 'h')
	{
		v.i++;
		if (*(v.str + v.i) == 'h')
		{
			v.length = 2;
			v.i++;
		}
		else
			v.length = 1;
	}
	else
	{
		v.i++;
		if (*(v.str + v.i) == 'l')
		{
			v.length = 4;
			v.i++;
		}
		else
			v.length = 3;
	}
	return (v);
}

t_variables	ft_found_percent(t_variables v)
{
	v.i = 0;
	v.str++;
	while ((v.tmp = ft_ischarset(*(v.str + v.i), "-+# 0")) >= 0)
		v = ft_set_flag(v);
	if ((v.tmp = ft_ischarset(*(v.str + v.i), "123456789*")) >= 0)
		v = ft_set_width(v);
	if ((v.tmp = ft_ischarset(*(v.str + v.i), ".")) >= 0)
		v = ft_set_precision(v);
	if ((v.tmp = ft_ischarset(*(v.str + v.i), "hl")) >= 0)
		v = ft_set_length(v);
	if((v.tmp = ft_ischarset(*(v.str + v.i), "diuxXfegcspn%")) >= 0)
		v = ft_found_conversion(v);
	else
		v.str = v.str + v.i;
	v = ft_flush_v(v);

	return (v);
}
