/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhumbert <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 14:12:44 by lhumbert          #+#    #+#             */
/*   Updated: 2021/12/15 15:58:28 by lhumbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_curr_line(t_line *line)
{
	int		i;
	int		j;
	char	*ret;

	i = -1;
	while (++i < line->size)
	{
		if (line->text[line->offset + i] == '\n')
			break ;
	}
	if (i == line->size)
		return (NULL);
	ret = (char *)malloc((i + 1) * sizeof(char));
	if (!ret)
		return (NULL);
	j = i;
	while (i + 1)
	{
		ret[j - i--] = line->text[line->offset];
		line->offset++;
		line->size--;
	}
	return (ret);
}

char	*read_next_buf(int fd, t_line **next_line)
{
	char	*buf;
	char	*ret;
	int		i;

	buf = (char *)malloc(BUFFER_SIZE * sizeof(char));
	if (!buf)
		return (NULL);
	read(fd, buf, BUFFER_SIZE);
	if (!buf)
		return (NULL);
	ret = NULL;
	i = -1;
	while (++i < BUFFER_SIZE)
	{
		append_char(*next_line, buf[i]);
		if (!ret && (buf[i] == '\n' || buf[i] == '\0'))
		{
			ret = cpytext(*next_line);
			if (buf[i] == '\n')
				*next_line = renew_line(*next_line);
			else
				free_line(*next_line);
		}
	}
	free(buf);
	return (ret);
}

char	*get_next_line(int fd)
{
	char			*ret;
	static t_line	*next_line;
	char			*curr_line;

	if (!next_line)
		next_line = init_line();
	curr_line = get_curr_line(next_line);
	if (curr_line)
		return (curr_line);
	ret = NULL;
	while (!ret)
		ret = read_next_buf(fd, &next_line);
	return (ret);
}
