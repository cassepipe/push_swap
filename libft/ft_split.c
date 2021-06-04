/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpouget <cassepipe@ymail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/14 17:04:37 by tpouget           #+#    #+#             */
/*   Updated: 2021/04/28 11:53:32 by tpouget          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static const char	*next_sep(const char *str, char sep)
{
	while (*str && *str != sep)
		str++;
	return (str);
}

static const char	*next_word(const char *str, char sep)
{
	while (*str && *str == sep)
		str++;
	return (str);
}

static char			**diralloc(const char *s, char c)
{
	size_t	size;

	if (!s)
		return (NULL);
	size = 1;
	s = next_word(s, c);
	while (*s)
	{
		s = next_sep(s, c);
		s = next_word(s, c);
		size++;
	}
	return (malloc(size * sizeof(char*)));
}

char				**ft_split(char const *s, char c)
{
	char		**dir;
	const char	*follower;
	long		i;

	if (!(dir = diralloc(s, c)))
		return (NULL);
	s = next_word(s, c);
	follower = s;
	i = 0;
	while (*s)
	{
		s = next_sep(s, c);
		if (!(dir[i++] = ft_strndup(follower, s - follower)))
		{
			while (--i >= 0)
				free(dir[i]);
			free(dir);
			return (NULL);
		}
		s = next_word(s, c);
		follower = s;
	}
	dir[i] = NULL;
	return (dir);
}
