/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   repr.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpouget <cassepipe@ymail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/08 17:45:47 by tpouget           #+#    #+#             */
/*   Updated: 2021/04/19 16:41:41 by tpouget          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_utils.h"

static char	*ft_lutoa_format(long nbr, int type)
{
	char *str;

	if (type == 'u' || type == 'd' || type == 'i')
		str = ft_lutoa_base(nbr, "0123456789");
	else if (type == 'x')
		str = ft_lutoa_base(nbr, "0123456789abcdef");
	else if (type == 'X')
		str = ft_lutoa_base(nbr, "0123456789ABCDEF");
	else
		str = NULL;
	return (str);
}

char		*nbr_repr(long nbr, struct s_parameters *format, ssize_t *size)
{
	char	*str;
	long	diff;
	int		neg;

	neg = nbr < 0 ? 1 : 0;
	nbr = neg ? -nbr : nbr;
	if (format->precision == 0 && !nbr)
		str = ft_strdup("");
	else
		str = ft_lutoa_format(nbr, format->type);
	*size = ft_strlen(str);
	if ((diff = format->precision - *size) > 0)
		leftpad(&str, '0', diff);
	else if (format->zero_flag
			&& (diff = format->min_field_width - *size - neg) > 0)
		leftpad(&str, '0', diff);
	*size = diff > 0 ? *size + diff : *size;
	if (neg && ++(*size))
		leftpad(&str, '-', 1);
	if (format->minus_flag && (diff = format->min_field_width - *size) > 0)
		rightpad(&str, ' ', diff);
	else if ((diff = format->min_field_width - *size) > 0)
		leftpad(&str, ' ', diff);
	*size = diff > 0 ? *size + diff : *size;
	return (str);
}

char		*str_repr(char *s, struct s_parameters *format, ssize_t *size)
{
	char	*str;
	long	diff;

	format->precision = format->precision < 0 ? INT_MAX : format->precision;
	if (!s)
		str = ft_strndup("(null)", format->precision);
	else
		str = ft_strndup(s, format->precision);
	*size = ft_strlen(str);
	if ((diff = format->min_field_width - *size) > 0)
	{
		*size += diff;
		if (format->minus_flag)
			rightpad(&str, ' ', diff);
		else if (format->zero_flag)
			leftpad(&str, '0', diff);
		else
			leftpad(&str, ' ', diff);
	}
	return (str);
}

char		*char_repr(unsigned char c,
		struct s_parameters *format,
		ssize_t *size)
{
	long	diff;
	int		null_char;
	char	*char_str;

	null_char = 0;
	if (!c && (null_char = 1))
		c = 1;
	if (!(char_str = ft_strndup((const char*)&c, 1)))
		return (NULL);
	if ((diff = format->min_field_width - 1) > 0)
	{
		if (format->minus_flag)
			rightpad(&char_str, ' ', diff);
		else if (format->zero_flag)
			leftpad(&char_str, '0', diff);
		else
			leftpad(&char_str, ' ', diff);
	}
	*size = diff > 0 ? diff + 1 : 1;
	diff = -1;
	if (null_char)
		while (char_str[++diff])
			if (char_str[diff] == 1)
				char_str[diff] = '\0';
	return (char_str);
}

char		*ptr_repr(void *ptr, struct s_parameters *format, ssize_t *size)
{
	char	*ptr_str;
	char	*tmp;
	long	diff;

	if (!ptr)
		ptr_str = ft_strdup("0");
	else
		ptr_str = ft_lutoa_base((unsigned long)ptr, "0123456789abcdef");
	tmp = ptr_str;
	ptr_str = ft_strjoin("0x", ptr_str);
	free(tmp);
	*size = ft_strlen(ptr_str);
	if ((diff = format->min_field_width - *size) > 0)
	{
		*size += diff;
		if (format->minus_flag)
			rightpad(&ptr_str, ' ', diff);
		else if (format->zero_flag)
			leftpad(&ptr_str, '0', diff);
		else
			leftpad(&ptr_str, ' ', diff);
	}
	return (ptr_str);
}
