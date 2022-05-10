/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   file_path.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvan-der <mvan-der@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/21 13:45:11 by mvan-der      #+#    #+#                 */
/*   Updated: 2022/05/10 11:49:55 by mvan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

static void	ft_free_array(char **result)
{
	int	i;

	i = 0;
	while (result[i])
	{
		free(result[i]);
		i++;
	}
	free(result);
}

static char	*search_path(char **envp)
{
	while (*envp)
	{
		if (!ft_strncmp(*envp, "PATH", 4))
			return (*envp + 5);
		envp++;
	}
	return (NULL);
}

void	file_and_path(t_pipex *pipex, int argc, char **argv, char **envp)
{
	pipex->fin = open(argv[1], O_RDONLY);
	if (pipex->fin < 0)
		exit(err_msg("Infile open error"));
	pipex->fout = open(argv[argc - 1], O_CREAT | O_TRUNC | O_WRONLY, 0644);
	if (pipex->fout < 0)
		exit(err_msg("Outfile open error"));
	pipex->path = ft_split(search_path(envp), ':');
	if (!pipex->path)
	{
		ft_free_array(pipex->path);
		exit (EXIT_FAILURE);
	}
}

char	*path_finder(t_pipex *pipex, char *command)
{
	char	*binpath;

	if (!command)
		return (NULL);
	if (access(command, X_OK) == 0)
	{
		binpath = command;
		return (binpath);
	}
	while (*pipex->path)
	{
		binpath = ft_strjoin(*pipex->path, "/");
		binpath = ft_strjoin(binpath, command);
		if (access(binpath, X_OK) == 0)
			return (binpath);
		pipex->path++;
	}
	return (NULL);
}

void	fd_closer(t_pipex *pipex)
{
	close(pipex->pipefd[0]);
	close(pipex->pipefd[1]);
	close(pipex->fin);
	close(pipex->fout);
}
