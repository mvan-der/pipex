/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pipex.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvan-der <mvan-der@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/21 13:43:36 by mvan-der      #+#    #+#                 */
/*   Updated: 2022/05/17 12:46:11 by mvan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void	execute_command(t_pipex *pipex, char *argv)
{
	char	*binpath;
	char	**command;

	command = ft_split(argv, ' ');
	if (!command)
		err_msg("Split fail", EXIT_FAILURE);
	binpath = path_finder(pipex, command[0]);
	if (!binpath)
		err_msg("Command not found", 127);
	execve(binpath, command, NULL);
	perror("execve");
	exit(EXIT_FAILURE);
}

void	first_command(t_pipex *pipex, char *file, char *argv)
{
	pipex->fin = open(file, O_RDONLY);
	if (pipex->fin < 0)
		err_msg("Infile open error", EXIT_FAILURE);
	close(pipex->pipefd[0]);
	if (dup2(pipex->fin, STDIN_FILENO) == -1)
		err_msg("Dup2 stdin fail", EXIT_FAILURE);
	if (dup2(pipex->pipefd[1], STDOUT_FILENO) == -1)
		err_msg("Dup2 stdout fail", EXIT_FAILURE);
	execute_command(pipex, argv);
}

void	second_command(t_pipex *pipex, char *argv, char *file)
{
	pipex->fout = open(file, O_CREAT | O_TRUNC | O_WRONLY, 0644);
	if (pipex->fout < 0)
		err_msg("Outfile open error", EXIT_FAILURE);
	close(pipex->pipefd[1]);
	if (dup2(pipex->pipefd[0], STDIN_FILENO) == -1)
		err_msg("Dup2 stdin fail 2", EXIT_FAILURE);
	if (dup2(pipex->fout, STDOUT_FILENO) == -1)
		err_msg("Dup2 stdout fail 2", EXIT_FAILURE);
	execute_command(pipex, argv);
}
