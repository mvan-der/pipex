/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parsing.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvan-der <mvan-der@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/21 13:45:11 by mvan-der      #+#    #+#                 */
/*   Updated: 2022/05/13 14:51:44 by mvan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*newstr;
	size_t	i;

	if (!s1 || !s2)
		return (NULL);
	newstr = ft_calloc(sizeof(char), ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!newstr)
		return (NULL);
	i = ft_strlen(s1);
	ft_strcpy(newstr, s1);
	ft_strcpy(newstr + i, s2);
	return (newstr);
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

void	env_path(t_pipex *pipex, char **envp)
{
	pipex->path = ft_split(search_path(envp), ':');
	if (!pipex->path)
		err_msg("Split fail", EXIT_FAILURE);
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
		if (!binpath)
			err_msg("command fail", EXIT_FAILURE);
		else if (access(binpath, X_OK) == 0)
			return (binpath);
		free(binpath);
		pipex->path++;
	}	
	err_msg("Command not found", EXIT_FAILURE);
	return (NULL);
}
