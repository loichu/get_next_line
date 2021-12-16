/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhumbert <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 17:50:01 by lhumbert          #+#    #+#             */
/*   Updated: 2021/12/16 12:04:59 by lhumbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

bool	init_buf(int fd, t_buf *buf)
{
	buf->fd = fd;
	buf->max = read(buf->fd, buf->data, BUFFER_SIZE);
	buf->pos = -1;
	return (buf->max >= 0);
}

char	read_buf(t_buf *buf)
{
	if (++(buf->pos) == buf->max)
	{
		buf->max = read(buf->fd, buf->data, BUFFER_SIZE);
		buf->pos = 0;
	}
	if (!buf->max)
		return (0);
	return (buf->data[buf->pos]);
}

char	*get_next_line(int fd)
{
	static t_buf	buf = {.fd = -1};
	char			*line;
	char			c;


	if (buf.fd != fd)
		if (!init_buf(fd, &buf))
			return (NULL);
	c = read_buf(&buf);
	line = 0;
	while (c)
	{
		line = stradd(line, c);
		if (c == '\n')
			return (line);
		c = read_buf(&buf);
	}
	return (line);
}
