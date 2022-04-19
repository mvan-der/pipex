/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   input_check.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvan-der <mvan-der@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/19 14:32:03 by mvan-der      #+#    #+#                 */
/*   Updated: 2022/04/19 14:41:35 by mvan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

int	input_check(int argc, char **argv, t_file *pipex)
{
	if (argc < 5)
	{
		ft_printf(ARG_ERROR);
		return (-1);
	}
	else if (ft_strncmp(argv[1], "here_doc", ft_strlen(argv[1])))
	{
		pipex->command1 = ft_split(argv[2], ' '); //Breaks on "awk {'print $1'}" as an argument! Need a pipex-split..
		return (0);
	}
	else
	{
		ft_printf("HERE_DOC!!!!\n");
		return (0);
	}
}
