/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   commands.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvan-der <mvan-der@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/21 13:43:36 by mvan-der      #+#    #+#                 */
/*   Updated: 2022/05/07 14:54:54 by mvan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

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
	perror("execve 1");
	free(binpath);
	ft_free(command);
	exit (EXIT_FAILURE);
}

void	first_command(t_pipex *pipex, char *argv)
{
	close(pipex->pipefd[0]);
	if (dup2(pipex->infile, STDIN_FILENO) == -1)
		err_msg("Dup2 fail");
	if (dup2(pipex->pipefd[1], STDOUT_FILENO) == -1)
		err_msg("Dup2 fail");
	execute_command(pipex, argv);
}

void	second_command(t_pipex *pipex, char *argv)
{
	close(pipex->pipefd[1]);
	if (dup2(pipex->pipefd[0], STDIN_FILENO) == -1)
		err_msg("Dup2 fail");
	if (dup2(pipex->outfile, STDOUT_FILENO) == -1)
		err_msg("Dup2 fail");
	execute_command(pipex, argv);
}
