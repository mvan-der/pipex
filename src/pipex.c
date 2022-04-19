/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pipex.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvan-der <mvan-der@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/10 16:09:03 by mvan-der      #+#    #+#                 */
/*   Updated: 2022/04/19 16:27:24 by mvan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"
#include <fcntl.h>
#include <stdio.h>

int	main(int argc, char **argv, char **envp)
{
	t_file	pipex;
	int		fd_in;
	int		fd_out;
	char	*binpath;

	if (input_check(argc, argv, &pipex) == -1)
		return (-1);
	fd_in = open(argv[1], O_RDONLY);
	if (fd_in < 0)
		return (OPEN_ERROR);
	fd_out = open(argv[argc - 1], O_RDWR | O_TRUNC);
	if (fd_out < 0)
	{
		fd_out = open(argv[argc - 1], O_CREAT | O_WRONLY, 0644);
		if (fd_out < 0)
			return (OPEN_ERROR);
	}
	if (!fork ())
	{
		dup2(fd_in, STDIN_FILENO);
		dup2(fd_out, STDOUT_FILENO);
		if (access(pipex.command1[0], F_OK) == 0)
			binpath = pipex.command1[0];
		else
			binpath = pathfinder(&pipex, envp);
		execve(binpath, pipex.command1, NULL);
		perror("execve");
	}
	else
	{
		close(fd_out);
		wait (NULL);
	}
	close(fd_out);
	close(fd_in);
	free(pipex.command1);
	return (0);
}
