/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffacilla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 11:50:35 by ffacilla          #+#    #+#             */
/*   Updated: 2021/01/14 11:09:10 by ffacilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** allocates a fresh substring
** starting from the start index of s and is of size len
*/

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	i;

	if (!(s))
		return (NULL);
	substr = (char *)malloc((sizeof(char) * len + 1));
	if (substr == NULL)
		return (NULL);
	i = 0;
	if (start < ft_strlen(s))
	{
		while (s[i] && i < len)
		{
			substr[i] = s[start + i];
			i++;
		}
	}
	substr[i] = 0;
	return (substr);
}
