/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhumbert <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 15:19:31 by lhumbert          #+#    #+#             */
/*   Updated: 2021/12/15 18:01:20 by lhumbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <unistd.h>
# include <stdlib.h>
# include <stdbool.h>

typedef struct s_buf {
	int		fd;
	int		max;
	int		pos;
	char	data[BUFFER_SIZE];
}	t_buf;

char	*get_next_line(int fd);
char	*stradd(char *s, char c);

#endif
