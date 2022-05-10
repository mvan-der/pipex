/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvan-der <mvan-der@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/21 13:28:25 by mvan-der      #+#    #+#                 */
/*   Updated: 2022/05/10 16:14:44 by mvan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int	err_msg(char *str, int exit_code)
{
	perror(str);
	exit (exit_code);
}

void	input_check(int argc)
{
	if (argc != 5)
	{
		write(1, ARG_FAIL, 50);
		exit(EXIT_FAILURE);
	}
}

int	main(int argc, char **argv, char **envp)
{
	t_pipex	pipex;

	input_check(argc);
	env_path(&pipex, envp);
	if (pipe(pipex.pipefd) == -1)
		return (err_msg("Pipe fail", EXIT_FAILURE));
	pipex.first = fork();
	if (pipex.first < 0)
		return (err_msg("Fork fail", EXIT_FAILURE));
	if (pipex.first == 0)
		first_command(&pipex, argv[1], argv[2]);
	pipex.second = fork();
	if (pipex.second < 0)
		return (err_msg("Fork fail", EXIT_FAILURE));
	if (pipex.second == 0)
		second_command(&pipex, argv[3], argv[4]);
	parents(&pipex);
	return (0);
}
