/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhumbert <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 17:50:01 by lhumbert          #+#    #+#             */
/*   Updated: 2021/12/15 23:09:48 by lhumbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#include <stdio.h>

bool	init_buf(int fd, t_buf *buf)
{
	buf->fd = fd;
	buf->max = read(buf->fd, buf->data, BUFFER_SIZE);
	buf->pos = 0;
	return (buf->max >= 0);
}

bool	read_buf(t_buf *buf)
{
	buf->max = read(buf->fd, buf->data, BUFFER_SIZE);
	buf->pos = 0;
	return (buf->max >= 0);
}

char	*get_next_line(int fd)
{
	static t_buf	buf = {.fd = -1};
	char			*line;


	if (buf.fd != fd)
		if (!init_buf(fd, &buf))
			return (NULL);
	line = (char *)malloc(1);
	line[0] = '\0';
	while (1)
	{
		//printf("Current line: %s\nAdding: %c\n", line, buf.data[buf.pos]);
		line = stradd(line, buf.data[buf.pos]);
		if (buf.data[buf.pos] == '\n' || buf.data[buf.pos] == '\0')
			return (line);
		if (++(buf.pos) == buf.max && !read_buf(&buf))
			break ;
	}
	//printf("b4 free\n");
	free(line);
	//printf("after free\n");
	return (NULL);
}
