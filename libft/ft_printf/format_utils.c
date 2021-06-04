/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpouget <cassepipe@ymail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/12 20:00:36 by tpouget           #+#    #+#             */
/*   Updated: 2021/04/19 16:35:26 by tpouget          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_utils.h"

int			is_in(char c, const char *charset)
{
	while (*charset)
	{
		if (c == *charset)
			return (1);
		charset++;
	}
	return (0);
}

void		init_format(struct s_parameters *format)
{
	format->zero_flag = 0;
	format->minus_flag = 0;
	format->min_field_width = 0;
	format->precision = -1;
}

void		arrange_format(struct s_parameters *format)
{
	if (format->min_field_width == INT_MIN)
		format->min_field_width++;
	if (format->min_field_width < 0)
	{
		format->min_field_width = -format->min_field_width;
		format->minus_flag = 1;
	}
	if (format->minus_flag)
		format->zero_flag = 0;
	if (format->precision >= 0 && is_in(format->type, "diuxX"))
		format->zero_flag = 0;
}

void		*parse_str_into_format(const char *fs,
		struct s_parameters *format,
		va_list args)
{
	while (is_in(*fs, "0- "))
	{
		if (*fs == '0')
			format->zero_flag = 1;
		else if (*fs == '-')
			format->minus_flag = 1;
		fs++;
	}
	if (*fs == '*')
		format->min_field_width = va_arg(args, int);
	else
		format->min_field_width = ft_atoi(fs);
	while (ft_isdigit(*fs) || *fs == '*')
		fs++;
	if (*fs == '.' && fs++)
	{
		if (*fs == '*')
			format->precision = va_arg(args, int);
		else
			format->precision = ft_atoi(fs);
	}
	while (ft_isdigit(*fs) || *fs == '*')
		fs++;
	format->type = *fs;
	return (format);
}

ssize_t		write_format(int fd,
		va_list args,
		struct s_parameters *format)
{
	char	*replacement;
	ssize_t	size;

	replacement = NULL;
	size = -1;
	if (is_in(format->type, "di"))
		replacement = nbr_repr(va_arg(args, int), format, &size);
	else if (is_in(format->type, "uxX"))
		replacement = nbr_repr(va_arg(args, unsigned int), format, &size);
	else if (format->type == 's')
		replacement = str_repr(va_arg(args, char*), format, &size);
	else if (format->type == 'c')
		replacement = char_repr(va_arg(args, int), format, &size);
	else if (format->type == 'p')
		replacement = ptr_repr(va_arg(args, void*), format, &size);
	else if (format->type == '%')
		replacement = str_repr("%", format, &size);
	else
	{
		write(fd, "|unknown format|", 16);
		format->error = 1;
	}
	size = write(fd, replacement, size);
	free(replacement);
	return (size);
}
