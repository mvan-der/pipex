/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memset.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvan-der <mvan-der@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/03 12:53:09 by mvan-der      #+#    #+#                 */
/*   Updated: 2020/11/26 09:51:23 by mvan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memset(void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*a;

	i = 0;
	a = s;
	while (i < n)
	{
		a[i] = (unsigned char)c;
		i++;
	}
	return (a);
}
