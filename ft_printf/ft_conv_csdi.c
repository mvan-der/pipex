/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_conv_csdi.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvan-der <mvan-der@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/13 18:18:31 by mvan-der      #+#    #+#                 */
/*   Updated: 2021/12/22 13:59:50 by mvan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_conv_c(va_list arguments)
{
	ft_putchar(va_arg(arguments, int));
}

void	ft_conv_s(va_list arguments)
{
	char	*s;

	s = va_arg(arguments, char *);
	if (s == NULL)
		ft_putstr("(null)");
	else
		ft_putstr(s);
}

void	ft_conv_di(va_list arguments)
{
	int		i;
	char	*str;

	i = va_arg(arguments, int);
	str = ft_itoa_printf(i, 10);
	ft_putstr(str);
	free(str);
}
