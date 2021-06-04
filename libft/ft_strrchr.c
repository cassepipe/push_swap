/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpouget <cassepipe@ymail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/14 17:04:38 by tpouget           #+#    #+#             */
/*   Updated: 2020/05/14 17:06:13 by tpouget          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	unsigned char	value;
	char			*ptr;
	char			*last_encounter;

	value = (unsigned char)c;
	ptr = (char *)s;
	last_encounter = NULL;
	while (*ptr)
	{
		if (*ptr == value)
			last_encounter = ptr;
		ptr++;
	}
	if (!value)
		return (ptr);
	return (last_encounter);
}
