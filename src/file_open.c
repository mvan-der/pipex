/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   file_open.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvan-der <mvan-der@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/12 11:05:37 by mvan-der      #+#    #+#                 */
/*   Updated: 2022/04/12 11:27:10 by mvan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "../includes/pipex.h"

static int	ft_file_size(char *file)
{
	int		fd;
	int		count;
	int		ret;
	char	buffer[256];

	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (fd);
	count = 0;
	ret = 1;
	while (ret > 0)
	{
		ret = read(fd, buffer, 256);
		count += ret;
	}
	close (fd);
	return (count);
}

void	file_open(char *str, t_file1 *placeholder)
{
	int	fd;
	int	ret;

	if (ft_file_size(str) < 0)
		exit (EXIT_ERROR);
	placeholder->file_str = ft_calloc(sizeof(char), ft_file_size(str) + 1);
	if (!placeholder->file_str)
		exit (EXIT_ERROR);
	fd = open(str, O_RDONLY);
	if (fd < 0)
	{

		exit (EXIT_ERROR);
	}
	ret = read(fd, placeholder->file_str, ft_file_size(str));
	close(fd);
}
