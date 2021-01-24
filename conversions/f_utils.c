/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_utils.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffacilla <ffacilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 22:16:43 by ffacilla          #+#    #+#             */
/*   Updated: 2021/01/22 20:09:30 by ffacilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

char			*ft_zeroftoa(t_variables *v)
{
    char *arr;
    int i;

    if (v->precision == 0)
    {
        arr = malloc(2);
        arr[0] = '0';
        arr[1] = 0;
        return (arr);
    }
    i = 2;
    arr = malloc(9);
    arr[0] = '0';
    arr[1] = '.';
    while (i < 8)
        arr[i++] = '0';
    arr[i] = 0;
    return (arr);
}

double   f_power(size_t precision)
{
    size_t i;
    double base;

    i = 0;
    base = 1;
    while (i <= precision)
    {
        base *= 10;
        i++;
    }
    return (base);
}
