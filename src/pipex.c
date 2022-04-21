/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pipex.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvan-der <mvan-der@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/21 13:28:25 by mvan-der      #+#    #+#                 */
/*   Updated: 2022/04/21 17:49:03 by mvan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"
#include <stdio.h>

int	main(int argc, char **argv, char **envp)
{
	t_pipex	pipex;

	if (argc != 5)
		return (error_message("Argument fail"));
	pathfinder(&pipex, envp);
	if (file_open(&pipex, argc, argv))
		return (1);
	if (pipe(pipex.pipefd) == -1)
		return (error_message("Pipe fail"));
	pipex.pid1 = fork();
	if (pipex.pid1 < 0)
		return (error_message("Fork fail"));
	if (pipex.pid1 == 0)
		command_one(&pipex, argv);
	pipex.pid2 = fork();
	if (pipex.pid2 < 0)
		return (error_message("Fork fail"));
	if (pipex.pid2 == 0)
		command_two(&pipex, argv);

	close(pipex.pipefd[1]);
	// waitpid(pipex.pid1, );
	// waitpid(pipex.pid2, )
	if (WIFEXITED())
		return (WEXITSTATUS());
	close(pipex.infile);
	close(pipex.outfile);
	return (0);
}
