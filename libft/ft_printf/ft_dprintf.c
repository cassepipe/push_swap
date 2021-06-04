/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpouget <cassepipe@ymail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/17 16:29:25 by tpouget           #+#    #+#             */
/*   Updated: 2021/04/19 16:39:20 by tpouget          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_utils.h"

int	ft_dprintf(int fd, const char *formatted_string, ...)
{
	va_list	ap;
	int		ret;

	va_start(ap, formatted_string);
	ret = ft_vdprintf(fd, formatted_string, ap);
	va_end(ap);
	return (ret);
}
