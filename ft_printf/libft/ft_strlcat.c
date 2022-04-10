/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strlcat.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvan-der <mvan-der@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/09/02 10:44:15 by mvan-der      #+#    #+#                 */
/*   Updated: 2020/11/19 14:09:29 by mvan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	destlen;
	size_t	i;

	i = 0;
	destlen = ft_strlen(dest);
	if (size > destlen)
	{
		while (src[i] != '\0' && i < (size - destlen - 1))
		{
			dest[destlen + i] = src[i];
			i++;
		}
		dest[destlen + i] = '\0';
		return (destlen + ft_strlen(src));
	}
	return (size + ft_strlen(src));
}
