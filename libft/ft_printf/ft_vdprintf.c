/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vdprintf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpouget <cassepipe@ymail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/13 11:18:09 by tpouget           #+#    #+#             */
/*   Updated: 2021/04/19 16:41:14 by tpouget          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_utils.h"

int						ft_vdprintf(int fd, const char *fs, va_list args)
{
	struct s_parameters	format;
	const char			*last_loc;
	ssize_t				ret;

	ret = 0;
	last_loc = fs;
	format.error = 0;
	while (*fs)
	{
		if (*fs == '%' && fs++)
		{
			init_format(&format);
			parse_str_into_format(fs, &format, args);
			arrange_format(&format);
			ret += write_format(fd, args, &format);
			while (is_in(*fs, "0123456789- .*"))
				fs++;
			last_loc = ++fs;
		}
		while (*fs && *fs != '%')
			fs++;
		ret += write(fd, last_loc, fs - last_loc);
	}
	return (format.error ? -1 : ret);
}
