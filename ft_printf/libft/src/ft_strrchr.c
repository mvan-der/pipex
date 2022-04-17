/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strrchr.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvan-der <mvan-der@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/28 16:02:10 by mvan-der      #+#    #+#                 */
/*   Updated: 2021/03/09 16:18:36 by mvan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strrchr(const char *s, int c)
{
	char	*a;
	int		i;

	a = (char *)s;
	i = 0;
	while (a[i] != '\0')
		i++;
	if (c == '\0')
		return (&a[i]);
	while (i >= 0)
	{
		if (a[i] == c)
			return (&a[i]);
		i--;
	}
	return (0);
}
