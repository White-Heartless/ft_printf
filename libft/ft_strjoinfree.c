/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoinfree.c                                   :+:      :+:    :+:   */
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
** and frees the first string if f is 0, the second if f is 1 and both if s is 2
*/

char	*ft_strjoinfree(char **s1, char **s2, int f)
{
	char	*new;
	int		i;
	int		j;

	if (*s1 == NULL || *s2 == NULL)
		return (NULL);
	new = (char *)malloc(sizeof(char) * (ft_strlen(*s1) +  ft_strlen(*s2) + 1));
	if (new == NULL)
		return (NULL);
	i = 0;
	while (s1[0][i])
	{
		new[i] = s1[0][i];
		i++;
	}
	j = 0;
	while (s2[0][j])
		new[i++] = s2[0][j++];
	new[i] = 0;
	if (f == 0 || f == 2)
		free(s1);
	if (f == 1 || f == 2)
		free(s2);
	return (new);
}
