/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parsing.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvan-der <mvan-der@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/21 13:45:11 by mvan-der      #+#    #+#                 */
/*   Updated: 2022/05/10 16:17:02 by mvan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include <stdlib.h>
#include <unistd.h>

void	wait_status(pid_t process)
{
	int		status;

	waitpid(process, &status, 0);
	if (WEXITSTATUS(status))
		exit(WEXITSTATUS(status));
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
		exit (EXIT_FAILURE);
}

char	*path_finder(t_pipex *pipex, char *command)
{
	char	*temp;

	if (!command)
		return (NULL);
	if (access(command, X_OK) == 0)
	{
		temp = command;
		return (temp);
	}
	while (*pipex->path)
	{
		temp = ft_strjoin(*pipex->path, "/");
		temp = ft_strjoin(temp, command);
		if (!temp)
			err_msg("command fail", EXIT_FAILURE);
		if (access(temp, X_OK) == 0)
			return (temp);
		pipex->path++;
	}
	return (NULL);
}

void	parents(t_pipex *pipex)
{
	close(pipex->pipefd[0]);
	close(pipex->pipefd[1]);
	wait_status(pipex->first);
	wait_status(pipex->second);
}
