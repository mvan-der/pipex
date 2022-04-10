/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_spec_conv.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvan-der <mvan-der@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/13 17:16:41 by mvan-der      #+#    #+#                 */
/*   Updated: 2022/01/27 10:59:36 by mvan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_spec_conv(const char *a, va_list arguments)
{
	a++;
	if (*a == 'c')
		ft_conv_c(arguments);
	else if (*a == 's')
		ft_conv_s(arguments);
	else if (*a == 'p')
		ft_conv_p(arguments);
	else if (*a == 'd')
		ft_conv_di(arguments);
	else if (*a == 'i')
		ft_conv_di(arguments);
	else if (*a == 'u')
		ft_conv_u(arguments);
	else if (*a == 'x')
		ft_conv_x(arguments);
	else if (*a == 'X')
		ft_conv_x2(arguments);
	else if (*a == '%')
		ft_putchar ('%');
}
