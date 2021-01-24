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

char	*ft_prefixfree(char *s1, char **s2)
{
	char	*new;
	int		i;
	int		j;

	if (s1 == NULL || *s2 == NULL)
		return (NULL);
	new = (char *)malloc(sizeof(char) * (ft_strlen(s1) +  ft_strlen(*s2) + 1));
	if (new == NULL)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		new[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[0][j])
		new[i++] = s2[0][j++];
	new[i] = 0;
	free(*s2);
	return (new);
}
