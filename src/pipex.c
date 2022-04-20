/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pipex.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvan-der <mvan-der@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/10 16:09:03 by mvan-der      #+#    #+#                 */
/*   Updated: 2022/04/20 12:53:26 by mvan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"
#include <fcntl.h>
#include <stdio.h>

int	main(int argc, char **argv, char **envp)
{
	t_file	pipex;
	int		file_in;
	int		file_out;
	char	*binpath;
	pid_t	pid;

	if (input_check(argc, argv, &pipex) == -1)
		return (-1);
	file_in = open(argv[1], O_RDONLY);
	if (file_in < 0)
		return (OPEN_ERROR);
	file_out = open(argv[argc - 1], O_RDWR | O_TRUNC);
	if (file_out < 0)
	{
		file_out = open(argv[argc - 1], O_CREAT | O_WRONLY, 0644);
		if (file_out < 0)
			return (OPEN_ERROR);
	}
	pid = fork();
	if (pid == 0)
	{
		dup2(file_in, STDIN_FILENO);
		dup2(file_out, STDOUT_FILENO); //-> this is output needed for 2nd command, atm redirected to std_out
		if (access(pipex.command1[0], F_OK) == 0)
			binpath = pipex.command1[0];
		else
			binpath = pathfinder(&pipex, envp);
		execve(binpath, pipex.command1, NULL);
		perror("execve");
	}
	else
	{
		close(file_out);
		wait (NULL);
	}
	close(file_out);
	close(file_in);
	free(pipex.command1);
	return (0);
}
