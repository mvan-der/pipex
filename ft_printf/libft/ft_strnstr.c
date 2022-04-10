/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strnstr.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvan-der <mvan-der@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/28 17:05:34 by mvan-der      #+#    #+#                 */
/*   Updated: 2020/11/26 15:06:59 by mvan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	char	*pbig;
	size_t	i;
	size_t	j;

	pbig = (char *)big;
	i = 0;
	if (little[i] == '\0')
		return (pbig);
	while (pbig[i] != '\0' && i < len)
	{
		j = 0;
		while (pbig[i + j] == little[j] && i + j < len)
		{
			if (little[j + 1] == '\0')
				return (&pbig[i]);
			j++;
		}
		i++;
	}
	return (NULL);
}
