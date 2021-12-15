/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhumbert <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 17:50:01 by lhumbert          #+#    #+#             */
/*   Updated: 2021/12/15 21:05:46 by lhumbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

bool	init_buf(fd, *buf)
{
	buf->fd = fd;
	buf->max = read(buf->fd, buf->data, BUFFER_SIZE);
	buf->pos = -1;
	return (ret);
}

bool	read_buf(t_buf *buf)
{
	buf->max = read(buf->fd, buf->data, BUFFER_SIZE);
	buf->pos = 0;
	return (buf->max >= 0);
}

char	*get_next_line(int fd)
{
	static t_buf	buf = {.fd: -1};
	char			*line;

	if (buf.fd != fd)
		if (!init_buf(fd, &buf))
			return (NULL);
	line = 0;
	while (1)
	{
		line = stradd(line, buf->data[buf->pos]);
		if (buf->data[buf.pos] == '\n' || buf->data[buf.pos] == '\0')
			return (line);
		if (++(buf.pos) == buf->max && !read_buf(buf))
			break ;
	}
	free(line);
	return (NULL);
}
