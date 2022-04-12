/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pipex.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvan-der <mvan-der@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/11 15:19:04 by mvan-der      #+#    #+#                 */
/*   Updated: 2022/04/12 15:15:18 by mvan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX
# define PIPEX


# define EXIT_ERROR -1
# include <unistd.h>
# include "../ft_printf/ft_printf.h"

typedef struct s_file1
{
	char	*file_str;
}			t_file1;

void	file_open(char *str, t_file1 *placeholder);

#endif
