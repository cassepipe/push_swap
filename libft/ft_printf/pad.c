/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pad.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpouget <cassepipe@ymail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/23 10:31:16 by tpouget           #+#    #+#             */
/*   Updated: 2021/04/19 16:41:33 by tpouget          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_utils.h"

void	leftpad(char **str, char c, size_t n)
{
	char	*padding;
	char	*tmp;

	padding = malloc(++n);
	padding[--n] = '\0';
	while (--n > 0)
		padding[n] = c;
	padding[0] = c;
	tmp = *str;
	*str = ft_strjoin(padding, *str);
	free(tmp);
	free(padding);
}

void	rightpad(char **str, char c, size_t n)
{
	char	*padding;
	char	*tmp;

	padding = malloc(++n);
	padding[--n] = '\0';
	while (--n > 0)
		padding[n] = c;
	padding[0] = c;
	tmp = *str;
	*str = ft_strjoin(*str, padding);
	free(tmp);
	free(padding);
}
