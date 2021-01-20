/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffacilla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 08:47:19 by ffacilla          #+#    #+#             */
/*   Updated: 2021/01/14 11:20:08 by ffacilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd, int *counter)
{
	unsigned int	u_n;

	u_n = (unsigned int)n;
	if (n < 0)
	{
		write(fd, "-", 1);
		*counter = *counter + 1;
		u_n = (unsigned int)(-1 * n);
	}
	if (u_n > 9)
	{
		ft_putnbr_fd(u_n / 10, fd, counter);
		ft_putchar_fd('0' + u_n % 10, fd);
		*counter = *counter + 1;
	}
	else
	{
		ft_putchar_fd('0' + u_n, fd);
		*counter = *counter + 1;
	}
}
