/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_put_printf.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvan-der <mvan-der@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/13 17:16:36 by mvan-der      #+#    #+#                 */
/*   Updated: 2022/03/16 13:34:39 by mvan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar(int c)
{
	ft_count(write(1, &c, 1));
}

void	ft_putstr(char *s)
{
	if (!s)
		return ;
	ft_count(write(1, s, ft_strlen(s)));
}
