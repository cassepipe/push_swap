/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpouget <cassepipe@ymail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/13 11:18:09 by tpouget           #+#    #+#             */
/*   Updated: 2021/04/19 16:40:20 by tpouget          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_utils.h"

int	ft_printf(const char *formatted_string, ...)
{
	va_list	ap;
	int		ret;

	va_start(ap, formatted_string);
	ret = ft_vdprintf(STDOUT_FILENO, formatted_string, ap);
	va_end(ap);
	return (ret);
}
