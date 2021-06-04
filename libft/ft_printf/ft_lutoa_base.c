/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lutoa_base.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpouget <cassepipe@ymail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/21 11:00:49 by tpouget           #+#    #+#             */
/*   Updated: 2021/04/19 16:39:29 by tpouget          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_utils.h"

static unsigned long	to_the_power_of(unsigned long n, unsigned long p)
{
	long result;

	result = 1;
	while (p--)
		result *= n;
	return (result);
}

char					*ft_lutoa_base(unsigned long n, const char *base_str)
{
	unsigned long	base;
	long			pos;
	unsigned long	i;
	unsigned long	digit;
	char			*result;

	base = ft_strlen(base_str);
	pos = 1;
	i = n;
	while (i /= base)
		pos++;
	result = malloc(pos + 1);
	if (!result)
		return (NULL);
	i = 0;
	while (--pos >= 0)
	{
		digit = n / to_the_power_of(base, pos);
		result[i++] = base_str[digit];
		n = n - digit * to_the_power_of(base, pos);
	}
	result[i] = '\0';
	return (result);
}
