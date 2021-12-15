#include "get_next_line.h"

#include <stdio.h>

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

//static void	putline(t_line *l)
//{
//	int	i;
//
//	i = -1;
//	while (++i < l->size)
//		write(1, &(l->text[i]), 1);
//	//write(1, &(l[i]), 1);
//}

char	*read_next_buf(int fd, t_line **next_line)
{
	char	*buf;
	char	*ret;
	int	i;

	buf = (char *)malloc(BUFFER_SIZE * sizeof(char));
	if (!buf)
		return (NULL);
	read(fd, buf, BUFFER_SIZE);
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
	char		*ret;
	static t_line	*next_line;
	char		*curr_line;

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
