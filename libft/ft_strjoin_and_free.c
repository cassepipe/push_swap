/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_and_free.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpouget <cassepipe@ymail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/08 16:22:39 by tpouget           #+#    #+#             */
/*   Updated: 2020/12/02 19:25:29 by tpouget          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin_and_free(char const *s1, char const *s2)
{
	size_t	len;
	ssize_t	i;
	ssize_t	j;
	char	*joined;

	len = ft_strlen(s1) + ft_strlen(s2);
	if (!(joined = malloc(len + 1)))
		return (NULL);
	i = -1;
	while (s1[++i])
		joined[i] = s1[i];
	j = -1;
	while (s2[++j])
		joined[i + j] = s2[j];
	joined[i + j] = '\0';
	free((void*)s1);
	free((void*)s2);
	return (joined);
}
