/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   paths.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvan-der <mvan-der@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/19 13:14:46 by mvan-der      #+#    #+#                 */
/*   Updated: 2022/04/19 16:28:34 by mvan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

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
	return (PATH_ERROR1);
}

char	*pathfinder(t_file *pipex, char **envp)
{
	char	**paths;
	char	*binpath;

	paths = ft_split(env_path(envp), ':');
	if (*paths == PATH_ERROR1 || !paths)
	{
		ft_free_array(paths);
		return (PATH_ERROR2);
	}
	while (*paths)
	{
		binpath = ft_strjoin(*paths, "/");
		binpath = ft_strjoin(binpath, pipex->command1[0]);
		if (access(binpath, F_OK) == 0)
			return (binpath);
		paths++;
	}
	return (PATH_ERROR2);
}
