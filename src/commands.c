/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   commands.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvan-der <mvan-der@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/21 13:43:36 by mvan-der      #+#    #+#                 */
/*   Updated: 2022/04/21 17:44:16 by mvan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"
#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>

void	command_one(t_pipex *pipex, char **argv)
{
	char	**command;
	char	*binpath;

	command = ft_split(argv[2], ' ');
	close(1);
	dup(pipex->pipefd[1]);
	dup2(pipex->infile, STDIN_FILENO);
	
	if (access(command[0], F_OK) == 0)
		binpath = command[0];
	else
	{
		binpath = pathjoin(pipex, command[0]);
		if(!binpath)
		{
			error_message("HELP!\n");
			exit (EXIT_FAILURE);
		}
	}
	execve(binpath, command, NULL);
	perror("execve");
	exit (EXIT_FAILURE);
}

void	command_two(t_pipex *pipex, char **argv)
{
	char	**command;
	char	*binpath;

	command = ft_split(argv[3], ' ');
	dup2(pipex->pipefd[0], STDIN_FILENO);
	close(pipex->pipefd[0]);
	close(pipex->pipefd[1]);
	close(1);
	dup(pipex->outfile);
	// dup2(pipex->outfile, STDOUT_FILENO);
	if (access(command[0], F_OK) == 0)
		binpath = command[0];
	else
	{
		binpath = pathjoin(pipex, command[0]);
		if(!binpath)
		{
			error_message("HELP!\n");
			exit (EXIT_FAILURE);
		}
	}
	execve(binpath, command, NULL);
	perror("execve");
	exit (EXIT_FAILURE);
}
