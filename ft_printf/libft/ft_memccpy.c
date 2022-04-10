/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memccpy.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvan-der <mvan-der@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/03 14:44:04 by mvan-der      #+#    #+#                 */
/*   Updated: 2020/11/26 14:23:37 by mvan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	unsigned char	*pdst;
	unsigned char	*psrc;
	size_t			i;

	pdst = (unsigned char *)dest;
	psrc = (unsigned char *)src;
	i = 0;
	while (i < n)
	{
		pdst[i] = psrc[i];
		if (psrc[i] == (unsigned char)c)
			return (pdst + i + 1);
		i++;
	}
	return (0);
}
