/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pipex.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvan-der <mvan-der@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/11 15:19:04 by mvan-der      #+#    #+#                 */
/*   Updated: 2022/04/17 17:24:46 by mvan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX
# define PIPEX


# define EXIT_ERROR -1
# define READ_FAILURE -1
# include <unistd.h>
# include "../ft_printf/includes/ft_printf.h"

typedef struct s_file1
{
	char	*file_str;
}			t_file1;

void	file_open(char *str, t_file1 *placeholder);

#endif
