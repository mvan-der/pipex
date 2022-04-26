/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strchr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvan-der <mvan-der@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/03 19:09:14 by mvan-der      #+#    #+#                 */
/*   Updated: 2020/11/26 15:04:18 by mvan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

char	*ft_strchr(const char *s, int c)
{
	char	*a;
	size_t	i;

	a = (char *)s;
	i = 0;
	while (a[i] != c)
	{
		if (a[i] == '\0')
			return (0);
		i++;
	}
	return (&a[i]);
}
