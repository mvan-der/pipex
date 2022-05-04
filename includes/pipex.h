/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pipex.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvan-der <mvan-der@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/21 13:27:32 by mvan-der      #+#    #+#                 */
/*   Updated: 2022/05/04 21:13:04 by mvan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# define ARGFAIL "Required usage: ./pipex infile cmd1 cmd2 outfile\n"

# include "../libft/includes/libft.h"
# include <sys/types.h>


typedef struct s_pipex
{
	int			pipefd[2];
	pid_t		pid1;
	pid_t		pid2;
	char		**path;
	int			infile;
	int			outfile;
}	t_pipex;

void	pathfinder(t_pipex *pipex, char **envp);
char	*pathjoin(t_pipex *pipex, char *command);
int		file_open(t_pipex *pipex, int argc, char **argv);
void	first_command(t_pipex *pipex, char **argv);
void	last_command(t_pipex *pipex, char **argv);
int		error_message(char *str);

#endif
