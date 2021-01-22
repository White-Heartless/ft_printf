/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffacilla <ffacilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/20 17:06:29 by ffacilla          #+#    #+#             */
/*   Updated: 2021/01/22 18:55:54 by ffacilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <stdarg.h>
# include <unistd.h>//mac only
#include <stdio.h>
//#include <io.h>//windows
#include "../libft/libft.h"

#ifndef FD
#define FD 1
#endif

typedef struct	s_variables
{
	va_list	arguments;
	char	*str;
	int		num;
	char	conv_spec;
	char	chr;
	int		to_ret;
	int		counter;
	int		flags[5];
	int		width;
	int		precision;
	int		length;
	int		fd;
	char	stmp[11];
	char	tmp;
	int		i;
	char	*buffer;
	int 	error;
}				t_variables;

int				ft_printf(const char *to_parse, ...);
t_variables		ft_found_percent(t_variables v);
t_variables		ft_flush_v(t_variables v);
t_variables		ft_found_conversion(t_variables v);
t_variables		ft_di_conversion(t_variables v);

#endif
