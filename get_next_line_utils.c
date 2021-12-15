
#include "get_next_line.h"

t_line	*init_line()
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

void	free_line(t_line *old_line)
{
	free(old_line->text - old_line->offset);
	free(old_line);
}

t_line	*renew_line(t_line *old_line)
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
