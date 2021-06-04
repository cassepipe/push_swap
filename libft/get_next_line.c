/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpouget <cassepipe@ymail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/27 00:48:46 by tpouget           #+#    #+#             */
/*   Updated: 2020/12/02 19:26:44 by tpouget          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	grow_buffer_until_newline(int fd, char **buffer,
									size_t *buf_len, char **newline)
{
	char		*new_buffer;
	ssize_t		bytes_read;

	while (!(*newline = ft_strchr(*buffer, '\n')))
	{
		if (!(new_buffer = malloc(BUFFER_SIZE + 1)))
			return (0);
		if (!(bytes_read = read(fd, new_buffer, BUFFER_SIZE)))
		{
			free(new_buffer);
			return (1);
		}
		else if (bytes_read < 0)
		{
			free(new_buffer);
			return (0);
		}
		new_buffer[bytes_read] = '\0';
		if (!(*buffer = ft_strjoin_and_free(*buffer, new_buffer)))
			return (0);
		*buf_len += bytes_read;
	}
	return (1);
}

int			get_next_line(int fd, char **line)
{
	static char	*buffer[OPEN_MAX];
	char		*newline;
	size_t		buf_len;
	size_t		line_len;

	if (fd < 0 || BUFFER_SIZE < 1 || !line)
		return (-1);
	if (!buffer[fd] && !(buffer[fd] = ft_calloc(BUFFER_SIZE + 1, sizeof(char))))
		return (-1);
	newline = NULL;
	buf_len = ft_strlen(buffer[fd]);
	if (!grow_buffer_until_newline(fd, &buffer[fd], &buf_len, &newline))
		return (-1);
	line_len = newline ? (size_t)(newline - buffer[fd]) : buf_len;
	if (!(*line = malloc(line_len + 1)))
		return (-1);
	ft_strlcpy(*line, buffer[fd], line_len + 1);
	if (newline)
		ft_strlcpy(buffer[fd], newline + 1, buf_len - line_len);
	else
	{
		free(buffer[fd]);
		buffer[fd] = NULL;
	}
	return (newline ? 1 : 0);
}
