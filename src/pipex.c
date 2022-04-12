/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pipex.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvan-der <mvan-der@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/10 16:09:03 by mvan-der      #+#    #+#                 */
/*   Updated: 2022/04/12 15:21:25 by mvan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

int	main(int argc, char **argv)
{
	t_file1	placeholder;

	if (argc == 1)
	{
		ft_printf("There is no input given?\n");
		return (EXIT_ERROR);
	}
	file_open(argv[1], &placeholder);
	ft_printf("Text inside %s:\n%s\n", argv[1], placeholder.file_str);
	free(placeholder.file_str);

	return(0);
}

/*	
	open file
	apply command (to file if needed, because ls is a thing :/ (if ls is the command, open file is not needed..? hmm..))
	Assumption is that all commands are possible.. so how to apply the command in the first place -> use execve utilizing bin/bash as first arg?
	pipe output command so it now acts as input for next command (fork somewhere before this.. but where.. and then pipe into new process so fork again?)
	repeat as long as there are commands
	write output last command to file

	No clue where dup() and dup2() are needed yet.. maybe duplicate and then fork?
*/
