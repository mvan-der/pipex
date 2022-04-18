/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pipex.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvan-der <mvan-der@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/10 16:09:03 by mvan-der      #+#    #+#                 */
/*   Updated: 2022/04/18 15:45:41 by mvan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"
#include <fcntl.h>

int	main(int argc, char **argv)
{
	t_file1	placeholder;

	if (argc == 1)
	{
		ft_printf("There is no input given?\n");
		return (EXIT_ERROR);
	}
	else if (ft_strncmp(argv[1], "here_doc", ft_strlen(argv[1])))
		file_open(argv[1], &placeholder);
	else
	{
		ft_printf("HERE_DOC!!!!\n");
		return (0);
	}
	placeholder.file_str = ft_split(argv[2], ' ');
	// ft_printf("Text inside %s:\n%s\n", argv[1], placeholder.file_str);
	int fd1 = open(argv[1], O_WRONLY);
	int	fd = open(argv[3], O_RDWR);
	if (fd < 0) //output file doesn't exist! Time to create it so it can be written to I guess
	{
		fd = open(argv[3], O_CREAT | O_WRONLY , 0644);
		if (fd < 0)
			return (-1);
	}
	if(!fork())
	{
		dup2(fd, STDOUT_FILENO);
		char *binPath = ft_strjoin("/bin/", placeholder.file_str[0]);
		char *const args[] = {binPath, placeholder.file_str[1], NULL};
		char *const env[] = {"env", NULL};
		execve(binPath, args, env);
	}
	else
	{
		close(fd);
		wait(NULL);
	}
	close(fd);
	close(fd1);
	free(placeholder.file_str);
	return(0);
}

/*	
	open file (or here_doc)
	apply command (to file if needed, because ls is a thing :/ (if ls is the command, open file is not needed..? hmm.. are there any other commands that do not need the contents of the given file?))
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
