/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpouget <cassepipe@ymail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/14 17:04:38 by tpouget           #+#    #+#             */
/*   Updated: 2021/04/19 15:33:04 by tpouget          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_in_set(char c, char const *set)
{
	if (!set)
		return (0);
	while (*set)
	{
		if (*set == c)
			return (1);
		set++;
	}
	return (0);
}

char		*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		len;
	char	*trimmed;

	i = 0;
	len = 0;
	if (!s1)
		return (NULL);
	while (is_in_set(s1[len], set))
		len++;
	i = len;
	while (s1[len])
		len++;
	while (len - 1 >= 0 && is_in_set(s1[len - 1], set) && len != i)
		len--;
	trimmed = ft_strndup(s1 + i, len - i);
	if (!trimmed)
		return (NULL);
	return (trimmed);
}
