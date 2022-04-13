/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memmove.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvan-der <mvan-der@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/03 15:01:27 by mvan-der      #+#    #+#                 */
/*   Updated: 2020/11/14 15:02:22 by mvan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char		*dptr;
	const char	*sptr;
	char		*enddest;
	const char	*endsrc;

	dptr = dest;
	sptr = src;
	enddest = dptr + (n - 1);
	endsrc = sptr + (n - 1);
	if (dptr == NULL && sptr == NULL)
		return (0);
	if (enddest < endsrc)
	{
		ft_memcpy(dest, src, n);
		return (dest);
	}
	while (n)
	{
		*enddest = *endsrc;
		enddest--;
		endsrc--;
		n--;
	}
	return (dest);
}
