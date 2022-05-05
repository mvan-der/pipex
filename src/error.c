/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   error.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvan-der <mvan-der@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/21 14:14:43 by mvan-der      #+#    #+#                 */
/*   Updated: 2022/05/05 16:14:30 by mvan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"
#include <stdio.h>
#include <stdlib.h>

int	error_message(char *str)
{
	perror(str);
	exit (EXIT_FAILURE);
}
