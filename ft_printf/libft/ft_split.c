/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_split.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvan-der <mvan-der@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/07 16:18:32 by mvan-der      #+#    #+#                 */
/*   Updated: 2021/03/09 16:53:41 by mvan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static char	**ft_free(char **result)
{
	int	i;

	i = 0;
	while (result[i])
	{
		free(result[i]);
		i++;
	}
	free(result);
	return (0);
}

static int	ft_cnt_str(const char *s, char c)
{
	size_t	i;
	size_t	count;
	int		checkflag;

	i = 0;
	count = 0;
	checkflag = 0;
	while (s[i])
	{
		if (s[i] == c)
			checkflag = 0;
		else if (checkflag == 0)
		{
			checkflag = 1;
			count++;
		}
		i++;
	}
	return (count);
}

static int	ft_len_str(const char *s, int i, char c)
{
	size_t	len;

	len = 0;
	while (s[i] && s[i] != c)
	{
		len++;
		i++;
	}
	return (len);
}

static void	ft_split_magic(char const *s, char c, char **result)
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		while (s[i] == c && s[i])
			i++;
		if (s[i])
		{
			*result = ft_substr(s, i, ft_len_str(s, i, c));
			if (!result)
			{
				(ft_free(result));
				return ;
			}
			i = i + ft_len_str(s, i, c);
			result++;
		}
	}
	*result = 0;
}

char	**ft_split(char const *s, char c)
{
	char	**result;

	if (!s)
		return (0);
	result = malloc(sizeof(char *) * (ft_cnt_str(s, c) + 1));
	if (!result)
		return (0);
	ft_split_magic(s, c, result);
	return (result);
}
