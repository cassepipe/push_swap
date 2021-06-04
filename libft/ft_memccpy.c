/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpouget <cassepipe@ymail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/14 17:04:37 by tpouget           #+#    #+#             */
/*   Updated: 2021/04/28 11:52:58 by tpouget          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	size_t			i;
	unsigned char	*d;
	unsigned char	*s;
	unsigned char	value;

	i = 0;
	d = (unsigned char*)dest;
	s = (unsigned char*)src;
	value = (unsigned char)c;
	while (i < n)
	{
		d[i] = s[i];
		if (s[i] == value)
			break ;
		i++;
	}
	return (i == n ? NULL : (dest + i + 1));
}
