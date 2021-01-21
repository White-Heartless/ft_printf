/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putlong_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffacilla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 08:47:19 by ffacilla          #+#    #+#             */
/*   Updated: 2021/01/14 11:20:08 by ffacilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putlong_fd(long int n, int fd, int *counter)
{
	size_t	st;

	st = (size_t)n;
	if (n < 0)
	{
		write(fd, "-", 1);
		*counter = *counter + 1;
		st = (size_t)(-1 * n);
	}
	if (st > 9)
	{
		ft_putlong_fd(st / 10, fd, counter);
		ft_putchar_fd('0' + st % 10, fd);
		*counter = *counter + 1;
	}
	else
	{
		ft_putchar_fd('0' + st, fd);
		*counter = *counter + 1;
	}
}
