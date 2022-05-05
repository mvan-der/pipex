/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   paths.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvan-der <mvan-der@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/21 13:37:59 by mvan-der      #+#    #+#                 */
/*   Updated: 2022/05/05 14:35:57 by mvan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"
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

static char	*env_path(char **envp)
{
	while (*envp)
	{
		if (!ft_strncmp(*envp, "PATH", 4))
			return (*envp + 5);
		envp++;
	}
	return (NULL);
}

void	pathfinder(t_pipex *pipex, char **envp)
{
	pipex->path = ft_split(env_path(envp), ':');
	if (!pipex->path)
	{
		ft_free_array(pipex->path);
		exit (EXIT_FAILURE);
	}
}

char	*pathjoin(t_pipex *pipex, char *command)
{
	char	*binpath;

	if (!command)
		return (NULL);
	while (*pipex->path)
	{
		binpath = ft_strjoin(*pipex->path, "/");
		binpath = ft_strjoin(binpath, command);
		if (access(binpath, F_OK) == 0)
			return (binpath);
		pipex->path++;
	}
	return (NULL);
}
