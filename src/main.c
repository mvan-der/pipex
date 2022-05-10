/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvan-der <mvan-der@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/21 13:28:25 by mvan-der      #+#    #+#                 */
/*   Updated: 2022/05/10 11:39:22 by mvan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void	wait_status(pid_t process)
{
	int		status;

	waitpid(process, &status, 0);
	if (WEXITSTATUS(status))
		exit(WEXITSTATUS(status));
}

int	err_msg(char *str)
{
	perror(str);
	exit (EXIT_FAILURE);
}

void	input_check(int argc)
{
	if (argc < 5)
	{
		write(1, ARG_FAIL, 50);
		exit(EXIT_FAILURE);
	}
}

int	main(int argc, char **argv, char **envp)
{
	t_pipex	pipex;

	input_check(argc);
	file_and_path(&pipex, argc, argv, envp);
	if (pipe(pipex.pipefd) == -1)
		return (err_msg("Pipe fail"));
	pipex.first = fork();
	if (pipex.first < 0)
		return (err_msg("Fork fail"));
	if (pipex.first == 0)
		first_command(&pipex, argv[2]);
	pipex.second = fork();
	if (pipex.second < 0)
		return (err_msg("Fork fail"));
	if (pipex.second == 0)
		second_command(&pipex, argv[3]);
	fd_closer(&pipex);
	wait_status(pipex.first);
	wait_status(pipex.second);
	return (0);
}
