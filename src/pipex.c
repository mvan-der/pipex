/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pipex.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvan-der <mvan-der@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/10 16:09:03 by mvan-der      #+#    #+#                 */
/*   Updated: 2022/04/13 12:17:34 by mvan-der      ########   odam.nl         */
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
	if (ft_strncmp(argv[1], "here_doc", ft_strlen(argv[1])))
		file_open(argv[1], &placeholder);
	else
	{
		ft_printf("HERE_DOC!!!!\n");
		return (0);
	}
	
	ft_printf("Text inside %s:\n%s\n", argv[1], placeholder.file_str);
	int	fd = open(argv[2], O_RDONLY);
	close (fd); //is this needed?
	int	fd2 = 0;
	if (fd == -1) //file doesn't exist! Time to create it so it can be written to I guess
	{
		fd2 = open(argv[2], O_CREAT);
		char *binPath = "/bin/bash";
		char *const args[] = {binPath, "-c", ft_strjoin("chmod 644 ", argv[2]), NULL};
		char *const env[] = {NULL};
		execve(binPath, args, env);
	}
	close (fd2); //is this needed..?
	free(placeholder.file_str);
	return(0);
}

/*	
	open file
	apply command (to file if needed, because ls is a thing :/ (if ls is the command, open file is not needed..? hmm.. are there any other commands that do no need the contents of the given file?))
	Assumption is that all commands are possible.. so how to apply the command in the first place -> use execve utilizing bin/bash as first arg?
	pipe output command so it now acts as input for next command (fork somewhere before this.. but where.. and then pipe into new process so fork again?)
	repeat as long as there are commands
	write output last command to file
	No clue where dup() and dup2() are needed yet.. maybe duplicate and then fork?
	Starting points:
	First argument is a file or here_doc
	Last argument is always a file
	When first argument is a file, all arguments between first and last are commands.
	When first argument is here_doc, next argument is the delimiter, followed by command(s) until the last argument (which is always a file)
*/
