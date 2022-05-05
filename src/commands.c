/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   commands.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvan-der <mvan-der@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/21 13:43:36 by mvan-der      #+#    #+#                 */
/*   Updated: 2022/05/05 16:40:01 by mvan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void	first_command(t_pipex *pipex, char **argv)
{
	char	**command;
	char	*binpath;

	command = ft_split(argv[2], ' ');
	dup2(pipex->pipefd[1], STDOUT_FILENO);
	if (access(command[0], F_OK) == 0)
		binpath = command[0];
	else
	{
		binpath = pathjoin(pipex, command[0]);
		if (!binpath)
		{
			perror("Path 1 fail");
			exit (0);
		}
	}
	execve(binpath, command, NULL);
	perror("execve");
	exit (EXIT_FAILURE);
}

void	last_command(t_pipex *pipex, char **argv)
{
	char	**command;
	char	*binpath;

	command = ft_split(argv[3], ' ');
	close(pipex->pipefd[1]);
	dup2(pipex->outfile, STDOUT_FILENO);
	if (access(command[0], F_OK) == 0)
		binpath = command[0];
	else
	{
		binpath = pathjoin(pipex, command[0]);
		if (!binpath)
		{
			perror("Path 2 fail");
			exit(EXIT_FAILURE);
		}
	}
	execve(binpath, command, NULL);
	perror("execve");
	exit (EXIT_FAILURE);
}
