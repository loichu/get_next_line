#include "get_next_line.h"
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

static void	putline(char *l)
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

	if (argc == 1)
		fd = 0;
	else
		fd = open(argv[1], O_RDONLY);
	
	line_cnt = 1;
	while (line_cnt--)
	{
		printf("Line %i:\n", ++line_nb);
		line = get_next_line(fd);
		putline(line);
		free(line);
	}
	printf("pid: %ld, parent pid: %ld\n", (long)getpid(), (long)getppid());
	while (1)
		printf("");
	return (0);
}
