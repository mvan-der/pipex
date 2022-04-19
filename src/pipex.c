/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pipex.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvan-der <mvan-der@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/10 16:09:03 by mvan-der      #+#    #+#                 */
/*   Updated: 2022/04/19 14:52:09 by mvan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"
#include <fcntl.h>
#include <stdio.h>

int	main(int argc, char **argv, char **envp)
{
	t_file	pipex;

	if (input_check(argc, argv, &pipex) == -1)
		return (-1);
	int fd_in = open(argv[1], O_RDONLY);
	if (fd_in < 0)
		return (OPEN_ERROR);
	int	fd_out = open(argv[argc-1], O_RDWR | O_TRUNC);
	if (fd_out < 0) //output file doesn't exist, so creating it here
	{
		fd_out = open(argv[3], O_CREAT | O_WRONLY , 0644);
		if (fd_out < 0)
			return (OPEN_ERROR);
	}
	if(!fork())
	{
		char *binPath;
		dup2(fd_in, STDIN_FILENO);
		dup2(fd_out, STDOUT_FILENO);
		binPath = pathfinder(&pipex, envp);
		char *const env[] = {"env", NULL};
		execve(binPath, pipex.command1, env);
		perror("execve");
	}
	else
	{
		close(fd_out);
		wait(NULL);
	}
	close(fd_out);
	close(fd_in);
	free(pipex.command1);
	return(0);
}

/*	
	open file (or here_doc)
	apply command (to file if needed, because ls is a thing :/ (if ls is the command, open file is not needed..? hmm.. are there any other commands that do not need the command1s of the given file?))
	Assumption is that all commands are possible.. so how to apply the command in the first place -> execve I guess?
	pipe output generated from command so it now acts as input for next command (fork somewhere before this.. but where.. and then pipe into new process so fork again?)
	repeat as long as there are commands
	write output last command to file
	No clue where dup() and dup2() are needed yet..
	Starting points:
	First argument after executable is a file or here_doc
	Last argument is always a file
	When first argument after executable is a file, all arguments between it and the last arguments are commands.
	When first argument after executable is here_doc, next argument is the delimiter, followed by command(s) until the last argument (which is always a file)
*/
