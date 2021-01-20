/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffacilla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 17:21:29 by ffacilla          #+#    #+#             */
/*   Updated: 2021/01/14 11:17:04 by ffacilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**Applies the function f to each character of the string passed
**as argument by giving it's index as argument.
**A new string is created in which the results of the operations are stored
*/

char	*ft_strmapi(const char *s, char (*f)(unsigned int, char))
{
	size_t	i;
	char	*newstr;

	if (s && f)
	{
		i = 0;
		newstr = (char *)malloc(1 + sizeof(char) * ft_strlen(s));
		if (newstr)
		{
			while (s[i])
			{
				newstr[i] = f((unsigned int)i, s[i]);
				i++;
			}
			newstr[i] = 0;
			return (newstr);
		}
	}
	return (NULL);
}
