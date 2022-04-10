/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pipex.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvan-der <mvan-der@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/10 16:09:03 by mvan-der      #+#    #+#                 */
/*   Updated: 2022/04/10 16:24:39 by mvan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include "ft_printf/ft_printf.h"

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


int	main(int argc, char **argv)
{
	char *str;
	int	fd;
	int	ret;

	if (argc == 1)
	{
		ft_printf("Not enough.. arguments\n");
		return (1);
	}
	if (ft_file_size(argv[1]) < 0)
		return (1);
	str = ft_calloc(sizeof(char), ft_file_size(argv[1]) + 1);
	if (!str)
		return (1);
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		return (1);
	ret = read(fd, str, ft_file_size(argv[1]));
	close(fd);
	ft_printf("str:\n%s\n", str);
	free(str);
	return(0);
}
