/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pipex.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvan-der <mvan-der@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/21 13:27:32 by mvan-der      #+#    #+#                 */
/*   Updated: 2022/05/13 14:47:26 by mvan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# define ARG_FAIL "Required usage: ./pipex infile cmd1 cmd2 outfile\n"

# include <sys/types.h>

typedef struct s_pipex
{
	char		**path;
	int			pipefd[2];
	pid_t		first;
	pid_t		second;
	int			fin;
	int			fout;
}	t_pipex;

void	env_path(t_pipex *pipex, char **envp);
char	*path_finder(t_pipex *pipex, char *command);
void	parents(t_pipex *pipex);

int		err_msg(char *str, int exit_code);

void	first_command(t_pipex *pipex, char *file, char *argv);
void	second_command(t_pipex *pipex, char *argv, char *file);
void	execute_command(t_pipex *pipex, char *argv);

char	**ft_split(char const *s, char c);

void	*ft_calloc(size_t nmemb, size_t size);
size_t	ft_strlen(const char *s);
char	*ft_substr(const char *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
size_t	ft_strcpy(char *dest, const char *src);

#endif
