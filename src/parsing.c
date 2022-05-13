/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parsing.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvan-der <mvan-der@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/21 13:45:11 by mvan-der      #+#    #+#                 */
/*   Updated: 2022/05/13 10:46:49 by mvan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include <stdlib.h>
#include <unistd.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*newstr;
	size_t	i;
	size_t	j;

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
	char	*temp;
	char	*binpath;

	if (!command)
		return (NULL);
	if (access(command, X_OK) == 0)
	{
		binpath = command;
		return (temp);
	}
	while (*pipex->path)
	{
		temp = ft_strjoin(*pipex->path, "/");
		if (!temp)
			err_msg("Strjoin fail", EXIT_FAILURE);
		binpath = ft_strjoin(temp, command);
		free(temp);
		if (!binpath)
			err_msg("command fail", EXIT_FAILURE);
		if (access(binpath, X_OK) == 0)
			return (binpath);
		pipex->path++;
	}
	return (NULL);
}
