/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpouget <cassepipe@ymail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/14 17:04:38 by tpouget           #+#    #+#             */
/*   Updated: 2021/04/28 11:53:52 by tpouget          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *l, const char *r, size_t n)
{
	size_t			i;
	int				diff;
	unsigned char	*s1;
	unsigned char	*s2;

	i = 0;
	diff = 0;
	s1 = (unsigned char*)l;
	s2 = (unsigned char*)r;
	while (i < n)
	{
		if ((diff = s1[i] - s2[i]))
			return (diff);
		if (!s1[i] || !s2[i])
			return (diff);
		i++;
	}
	return (diff);
}
