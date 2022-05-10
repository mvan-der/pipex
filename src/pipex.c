/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pipex.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvan-der <mvan-der@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/21 13:43:36 by mvan-der      #+#    #+#                 */
/*   Updated: 2022/05/10 12:46:39 by mvan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

static void	ft_free_array(char **result)
{
	int	i;

	i = 0;
	while (result[i])
	{
		free(result[i]);
		i++;
	}
	free(result);
}

void	execute_command(t_pipex *pipex, char *argv)
{
	char	*binpath;
	char	**command;

	command = ft_split(argv, ' ');
	if (!command)
		err_msg("Split fail");
	binpath = path_finder(pipex, command[0]);
	if (!binpath)
		err_msg("Path fail");
	execve(binpath, command, NULL);
	perror("execve");
	free(binpath);
	ft_free_array(command);
	exit(EXIT_FAILURE);
}

void	first_command(t_pipex *pipex, char *argv)
{
	close(pipex->pipefd[0]);
	if (dup2(pipex->fin, STDIN_FILENO) == -1)
		err_msg("Dup2 stdin fail");
	if (dup2(pipex->pipefd[1], STDOUT_FILENO) == -1)
		err_msg("Dup2 stdout fail");
	execute_command(pipex, argv);
}

void	second_command(t_pipex *pipex, char *argv)
{
	close(pipex->pipefd[1]);
	if (dup2(pipex->pipefd[0], STDIN_FILENO) == -1)
		err_msg("Dup2 stdin fail 2");
	if (dup2(pipex->fout, STDOUT_FILENO) == -1)
		err_msg("Dup2 stdout fail 2");
	execute_command(pipex, argv);
}
