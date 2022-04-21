/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pipex.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvan-der <mvan-der@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/21 13:27:32 by mvan-der      #+#    #+#                 */
/*   Updated: 2022/04/21 17:22:36 by mvan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "../ft_printf/includes/ft_printf.h"
# include <sys/types.h>

typedef struct s_pipex
{
	int		pipefd[2];
	pid_t	pid1;
	pid_t	pid2;
	char	**path;
	int		infile;
	int		outfile;
}	t_pipex;

void	pathfinder(t_pipex *pipex, char **envp);
char	*pathjoin(t_pipex *pipex, char *command);
int		file_open(t_pipex *pipex, int argc, char **argv);
void	command_one(t_pipex *pipex, char **argv);
void	command_two(t_pipex *pipex, char **argv);
int		error_message(char *str);

#endif
