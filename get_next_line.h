#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <unistd.h>
# include <stdlib.h>
# include "stdbool.h"

typedef struct	s_line  {
	char	*text;
	int	offset;
	int	size;
}	t_line;

char	*get_next_line(int fd);
t_line	*init_line();
void	free_line(t_line *old_line);
t_line	*renew_line(t_line *old_line);
void	append_char(t_line *line, char c);
char	*cpytext(t_line *line);


//void	putline(char *l);

#endif
