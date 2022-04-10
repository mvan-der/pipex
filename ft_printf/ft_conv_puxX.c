/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_conv_puxX.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvan-der <mvan-der@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/13 17:36:57 by mvan-der      #+#    #+#                 */
/*   Updated: 2022/03/16 13:34:57 by mvan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_conv_p(va_list arguments)
{
	void				*p;
	unsigned long int	i;
	char				*str;
	char				*res;

	p = va_arg(arguments, void *);
	if (p == NULL)
	{
		ft_putstr("0x0");
		return ;
	}
	i = (unsigned long int) p;
	str = ft_utoa_printf(i, 16, 'x');
	res = ft_strjoin("0x", str);
	ft_putstr(res);
	free(str);
	free(res);
}

void	ft_conv_u(va_list arguments)
{
	unsigned int	j;
	char			*str;

	j = va_arg(arguments, int);
	str = ft_utoa_printf(j, 10, 'u');
	ft_putstr(str);
	free(str);
}

void	ft_conv_x(va_list arguments)
{
	unsigned int	j;
	char			*str;

	j = va_arg(arguments, int);
	str = ft_utoa_printf(j, 16, 'x');
	ft_putstr(str);
	free(str);
}

void	ft_conv_x2(va_list arguments)
{
	unsigned int	j;
	char			*str;

	j = va_arg(arguments, int);
	str = ft_utoa_printf(j, 16, 'X');
	ft_putstr(str);
	free(str);
}
