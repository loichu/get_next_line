#include "get_next_line.h"
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

void	putline(char *l)
{
	int	i;

	i = 0;
	while (l[i] != '\0' && l[i] != '\n')
		write(1, &(l[i++]), 1);
	write(1, &(l[i]), 1);
}

int	main(int argc, char **argv)
{
	int		fd;
	char		*line;
	int		line_cnt;
	static int	line_nb;
	//int	bcnt;

	if (argc == 1)
		fd = 0;
	else
		fd = open(argv[1], O_RDONLY);
	
	line_cnt = 5;
	while (line_cnt--)
	{
		printf("Line %i:\n", ++line_nb);
		line = get_next_line(fd);
		putline(line);
		free(line);
		//printf("%s", get_next_line(fd));
	}
	//buf = get_next_line(fd);
	//bcnt = BUFFER_SIZE;
	//while (bcnt--)
	//{
	//	write(1, buf++, 1);
	//}
	return (0);
}
