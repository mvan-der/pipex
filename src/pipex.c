/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pipex.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvan-der <mvan-der@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/21 13:28:25 by mvan-der      #+#    #+#                 */
/*   Updated: 2022/05/05 17:50:28 by mvan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

int	input_check(int argc)
{
	if (argc < 5)
	{
		write(1, ARG_FAIL, 50);
		exit(EXIT_FAILURE);
	}
	return (0);
}

int	main(int argc, char **argv, char **envp)
{
	t_pipex	pipex;

	input_check(argc);
	pathfinder(&pipex, envp);
	if (file_open(&pipex, argc, argv) == 1)
		exit (EXIT_FAILURE);
	if (pipe(pipex.pipefd) == -1)
		return (error_message("Pipe fail"));
	pipex.pid = fork();
	if (pipex.pid < 0)
		return (error_message("Fork fail"));
	else if (pipex.pid == 0)
	{
		dup2(pipex.infile, STDIN_FILENO);
		first_command(&pipex, argv);
	}
	else
	{
		close(pipex.pipefd[1]);
		wait(NULL);
	}
	dup2(pipex.pipefd[0], STDIN_FILENO);
	last_command(&pipex, argv);
	return (0);
}
