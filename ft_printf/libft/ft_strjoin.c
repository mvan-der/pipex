/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strjoin.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvan-der <mvan-der@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/07 12:39:57 by mvan-der      #+#    #+#                 */
/*   Updated: 2020/11/26 15:04:53 by mvan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*newstr;
	size_t	i;
	size_t	j;

	if (!s1 || !s2)
		return (0);
	newstr = ft_calloc(sizeof(char), ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!newstr)
		return (0);
	i = 0;
	j = 0;
	while (s1[i] != '\0')
	{
		newstr[j] = s1[i];
		i++;
		j++;
	}
	i = 0;
	while (s2[i] != '\0')
	{
		newstr[j] = s2[i];
		i++;
		j++;
	}
	return (newstr);
}
