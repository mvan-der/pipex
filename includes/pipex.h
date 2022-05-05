/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pipex.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvan-der <mvan-der@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/21 13:27:32 by mvan-der      #+#    #+#                 */
/*   Updated: 2022/05/05 21:10:08 by mvan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# define ARG_FAIL "Required usage: ./pipex infile cmd1 cmd2 outfile\n"

# include <sys/types.h>
# include <sys/wait.h>

typedef struct s_pipex
{
	char		**path;
	int			pipefd[2];
	pid_t		pid;
	int			infile;
	int			outfile;
}	t_pipex;

void	pathfinder(t_pipex *pipex, char **envp);
char	*pathjoin(t_pipex *pipex, char *command);

int		file_open(t_pipex *pipex, int argc, char **argv);

int		error_message(char *str);

void	first_command(t_pipex *pipex, char **argv);
void	last_command(t_pipex *pipex, char **argv);

char	**ft_split(char const *s, char c);

void	*ft_calloc(size_t nmemb, size_t size);
size_t	ft_strlen(const char *s);
char	*ft_substr(const char *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
int		ft_strncmp(const char *s1, const char *s2, size_t n);

#endif
