/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffacilla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 11:36:18 by ffacilla          #+#    #+#             */
/*   Updated: 2021/01/11 15:56:10 by ffacilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Takes a string as input and returns a copy of the string,
** allocated with malloc.
*/

char	*ft_strdup(const char *src)
{
	char	*dup;
	int		i;

	i = -1;
	if ((dup = (char *)malloc(sizeof(char) * (ft_strlen(src) + 1))) == NULL)
		return (NULL);
	while (src[++i])
		dup[i] = src[i];
	dup[i] = 0;
	return (dup);
}
