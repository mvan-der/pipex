/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parsing.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvan-der <mvan-der@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/21 13:45:11 by mvan-der      #+#    #+#                 */
/*   Updated: 2022/06/01 11:58:08 by mvan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	*a;
	unsigned char	*b;
	size_t			i;

	a = (unsigned char *)s1;
	b = (unsigned char *)s2;
	i = 0;
	while ((a[i] != '\0' || b[i] != '\0') && i < n)
	{
		if (a[i] != b[i])
			return (a[i] - b[i]);
		i++;
	}
	return (0);
}

static char	*search_path(char **envp)
{
	while (*envp)
	{
		if (!ft_strncmp(*envp, "PATH=", 5))
			return (*envp + 5);
		envp++;
	}
	return (NULL);
}

void	env_path(t_pipex *pipex, char **envp)
{
	char	*path_temp;

	path_temp = search_path(envp);
	if (!path_temp)
		return ;
	pipex->path = ft_split(path_temp, ':');
	if (!pipex->path)
		err_msg("No path", EXIT_FAILURE);
}

char	*path_finder(t_pipex *pipex, char *command)
{
	char	*binpath;
	char	*temp;

	if (!command)
		return (NULL);
	else if (access(command, X_OK) == 0)
		return (command);
	while (*pipex->path)
	{
		temp = ft_strjoin(*pipex->path, "/");
		binpath = ft_strjoin(temp, command);
		if (!binpath)
			err_msg("Path fail", EXIT_FAILURE);
		else if (access(binpath, X_OK) == 0)
			return (binpath);
		free(binpath);
		free(temp);
		binpath = NULL;
		temp = NULL;
		pipex->path++;
	}
	return (binpath);
}
