/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpouget <cassepipe@ymail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/14 17:04:37 by tpouget           #+#    #+#             */
/*   Updated: 2021/04/28 11:53:23 by tpouget          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static long	ft_10powerof(long n)
{
	long result;

	result = 1;
	while (n--)
		result *= 10;
	return (result);
}

void		ft_putnbr_fd(int n, int fd)
{
	long	nbr;
	long	digit;
	long	i;
	long	len;
	char	result[12];

	len = 1;
	nbr = n < 0 ? -1 * (long)n : n;
	i = nbr;
	while (i /= 10)
		len++;
	i = 0;
	if (n < 0)
		result[i++] = '-';
	while (--len >= 0)
	{
		digit = nbr / ft_10powerof(len);
		result[i++] = digit + '0';
		nbr = nbr - digit * ft_10powerof(len);
	}
	result[i] = '\0';
	write(fd, result, i);
}
