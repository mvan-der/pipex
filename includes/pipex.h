/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pipex.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvan-der <mvan-der@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/11 15:19:04 by mvan-der      #+#    #+#                 */
/*   Updated: 2022/04/19 14:46:14 by mvan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX
# define PIPEX

# define ARG_ERROR "Not enough arguments given, expected format -> program file1 cmd1 cmd2 file2 \n"
# define PATH_ERROR1 "Danger, Will Robinson\n"
# define PATH_ERROR2 "So much more danger\n"
# define OPEN_ERROR -1
# define READ_FAILURE -1
# include <unistd.h>
# include "../ft_printf/includes/ft_printf.h"

typedef struct s_file
{
	char	**command1;
}			t_file;

char	*pathfinder(t_file *pipex, char **envp);
int		input_check(int argc, char **argv, t_file *pipex);

#endif
