/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvan-der <mvan-der@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/21 13:28:25 by mvan-der      #+#    #+#                 */
/*   Updated: 2022/06/01 12:04:47 by mvan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int	err_msg(char *str, int exit_code)
{
	perror(str);
	exit(exit_code);
}

static void	wait_status(pid_t process)
{
	int		status;

	waitpid(process, &status, 0);
	if (WEXITSTATUS(status))
		exit(WEXITSTATUS(status));
}

static void	parents(t_pipex *pipex)
{
	close(pipex->pipefd[0]);
	close(pipex->pipefd[1]);
	wait_status(pipex->second);
}

static void	input_check(int argc)
{
	if (argc != 5)
	{
		write(STDOUT_FILENO, ARG_FAIL, ft_strlen(ARG_FAIL));
		exit(EXIT_FAILURE);
	}
}

int	main(int argc, char **argv, char **envp)
{
	t_pipex	pipex;

	input_check(argc);
	env_path(&pipex, envp);
	if (pipe(pipex.pipefd) == -1)
		err_msg("Pipe fail", EXIT_FAILURE);
	pipex.first = fork();
	if (pipex.first < 0)
		err_msg("Fork fail", EXIT_FAILURE);
	else if (pipex.first == 0)
		first_command(&pipex, argv[1], argv[2]);
	pipex.second = fork();
	if (pipex.second < 0)
		err_msg("Fork fail", EXIT_FAILURE);
	else if (pipex.second == 0)
		second_command(&pipex, argv[3], argv[4]);
	parents(&pipex);
	return (0);
}
