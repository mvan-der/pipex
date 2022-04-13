/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_itoa.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvan-der <mvan-der@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/12 14:20:39 by mvan-der      #+#    #+#                 */
/*   Updated: 2021/03/09 16:15:37 by mvan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>

static int	ft_count_n(long int nb)
{
	size_t	count;

	count = 0;
	if (nb == 0)
	{
		count = 1;
		return (count);
	}
	if (nb < 0)
		count++;
	while (nb != 0)
	{
		nb = nb / 10;
		count++;
	}
	return (count);
}

char	*ft_itoa(int n)
{
	char		*str;
	size_t		i;
	long int	nb;

	nb = n;
	i = ft_count_n(nb) - 1;
	str = ft_calloc(sizeof(char), ft_count_n(nb) + 1);
	if (!str)
		return (NULL);
	if (nb == 0)
		str[ft_count_n(nb) - 1] = '0';
	if (nb < 0)
	{
		nb = nb * -1;
		str[0] = '-';
	}
	while (nb > 0)
	{
		str[i] = (nb % 10) + '0';
		nb = nb / 10;
		i--;
	}
	return (str);
}
