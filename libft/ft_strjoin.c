/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffacilla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 11:55:54 by ffacilla          #+#    #+#             */
/*   Updated: 2021/01/14 11:14:47 by ffacilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Allocates a new string big enough to host both s1 and s2 and
** fills the new string with the result of the concatenation of those strings
*/

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new;
	int		i;
	int		s1len;
	int		s2len;
	int		j;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	s1len = ft_strlen(s1);
	s2len = ft_strlen(s2);
	new = (char *)malloc(sizeof(char) * (s1len + s2len + 1));
	if (new == NULL)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		new[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
		new[i++] = s2[j++];
	new[i] = 0;
	return (new);
}
