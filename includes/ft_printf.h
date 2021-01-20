/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffacilla <ffacilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/20 17:06:29 by ffacilla          #+#    #+#             */
/*   Updated: 2021/01/20 19:02:28 by ffacilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
//# include <unistd.h>mac only
#include <io.h>//windows
# include "../libft/libft.h"

typedef struct	s_variables
{
	va_list	arguments;
	char	*str;
	int		num;
	char	conv_spec;
	char	chr;
	int		to_ret;
	int		counter;
}				t_variables;

int				ft_printf(const char *to_parse, ...);
t_variables		found_percent(t_variables v);

#endif
