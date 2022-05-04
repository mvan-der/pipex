/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pipex.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvan-der <mvan-der@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/21 13:28:25 by mvan-der      #+#    #+#                 */
/*   Updated: 2022/05/04 17:58:58 by mvan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

int	main(int argc, char **argv, char **envp)
{
	t_pipex	pipex;

	if (argc < 5)
		exit (error_message("Not enough arguments given"));
	pathfinder(&pipex, envp);
	if (file_open(&pipex, argc, argv))
		return (1);
	if (pipe(pipex.pipefd) == -1)
		return (error_message("Pipe fail"));
	pipex.pid1 = fork();
	if (pipex.pid1 < 0)
		return (error_message("Fork 1 fail"));
	else if (pipex.pid1 == 0)
		first_command(&pipex, argv);
	else
		last_command(&pipex, argv);
	return (0);
}
