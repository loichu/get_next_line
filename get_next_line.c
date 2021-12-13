#include "get_next_line.h"
#include "stdbool.h"

#include <unistd.h>
#include <stdio.h>

typedef struct	s_line  {
	char	*text;
	int	offset;
	int	size;
}	t_line;

t_line	*init_line ()
{
	t_line	*line;

	line = (t_line *)malloc(sizeof(t_line));
	if (!line)
		return (NULL);
	line->size = 0;
	line->text = (char *)malloc(sizeof(char));
	*(line->text) = '\0';
	line->offset = 0;
	return (line);
}

void	free_line (t_line *old_line)
{
	free(old_line->text);
	free(old_line);
}

t_line	*renew_line (t_line *old_line)
{
	free_line(old_line);
	return (init_line());
}

void	append_char(t_line *line, char c)
{
	char	*new_text;
	int	i;

	line->size++;
	new_text = (char *)malloc(line->size * sizeof(char));
	if (!new_text)
		return ;
	i = -1;
	while (++i < (line->size - 1))
	{
		new_text[i] = line->text[i];
	}
	new_text[i] = c;
	free(line->text - line->offset);
	line->offset = 0;
	line->text = new_text;
}

char	*cpytext(t_line *line)
{
	char	*ret;
	int	i;

	ret = (char *)malloc(line->size * sizeof(char));
	if (!ret)
		return (NULL);
	i = -1;
	while (++i < line->size)
		ret[i] = line->text[i];
	return (ret);
}

char	*get_curr_line(t_line *line)
{
	int	i;
	int	j;
	char	*ret;

	i = -1;
	while (++i < line->size)
	{
		if (line->text[i] == '\n')
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
		ret[j - i--] = line->text[0];
		line->text++;
		line->size--;
		line->offset++;
	}
	return (ret);
}

char	*get_next_line(int fd)
{
	char		*buf;
	char		*ret;
	static t_line	*next_line;
	int		i;
	bool		reading;
	char		*curr_line;

	if (!next_line)
		next_line = init_line();
	curr_line = get_curr_line(next_line);
	if (curr_line)
		return (curr_line);
	reading = true;
	while (reading)
	{
		buf = (char *)malloc(BUFFER_SIZE * sizeof(char));
		if (!buf)
			return (NULL);
		read(fd, buf, BUFFER_SIZE);
		i = -1;
		while (++i < BUFFER_SIZE)
		{
			append_char(next_line, buf[i]);
			if (buf[i] == '\n' && reading)
			{
				ret = cpytext(next_line);
				next_line = renew_line(next_line);
				reading = false;
			}
			else if (buf[i] == '\0')
				return (next_line->text);
		}
		free(buf);
	}
	return (ret);
}
