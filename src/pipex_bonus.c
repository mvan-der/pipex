/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pipex_bonus.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvan-der <mvan-der@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/05 20:44:26 by mvan-der      #+#    #+#                 */
/*   Updated: 2022/05/06 12:39:19 by mvan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>

void	input_check(int argc)
{
	if (argc < 4)
	{
		write(1, ARG_FAIL, 50);
		exit(EXIT_FAILURE);
	}
}

void	command(t_pipex *pipex, char *argv)
{
	char	**command;
	char	*binpath;

	command = ft_split(argv, ' ');
	if (!command)
		exit (999);
	close(pipex->pipefd[0]);
	dup2(pipex->pipefd[1], STDOUT_FILENO);
	if (access(command[0], F_OK) == 0)
		binpath = command[0];
	else
	{
		binpath = pathjoin(pipex, command[0]);
		if (!binpath)
		{
			perror("Path fail");
			exit (EXIT_FAILURE);
		}
	}
	execve(binpath, command, NULL);
	perror("command function execve");
	exit (EXIT_FAILURE);
}

void	forkception(t_pipex *pipex, char *argv)
{
	if (pipe(pipex->pipefd) == -1)
		exit (error_message("Pipe fail"));
	dup2(pipex->infile, STDIN_FILENO);
	pipex->pid = fork();
	if (pipex->pid < 0)
		exit (error_message("Fork fail"));
	else if (pipex->pid == 0)
	{
		command(pipex, argv);
	}
	else
	{
		close(pipex->pipefd[1]);
		wait(NULL);
		dup2(pipex->pipefd[0], pipex->infile);
	}
}

int	main(int argc, char **argv, char **envp)
{
	t_pipex	pipex;
	int		arg_counter;
	int		i;

	input_check(argc);
	arg_counter = argc - 3;
	i = 0;
	pathfinder(&pipex, envp);
	if (file_open(&pipex, argc, argv) == 1)
		exit (EXIT_FAILURE);
	while (i < arg_counter)
	{
		forkception(&pipex, argv[i++]);
	}
	last_command(&pipex, argv[i]);
	return (0);
}
