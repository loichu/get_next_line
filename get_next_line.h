/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhumbert <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 15:19:31 by lhumbert          #+#    #+#             */
/*   Updated: 2021/12/15 15:31:45 by lhumbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <unistd.h>
# include <stdlib.h>
# include <stdbool.h>

typedef struct s_line {
	char	*text;
	int		offset;
	int		size;
}	t_line;

char	*get_next_line(int fd);
t_line	*init_line(void);
void	free_line(t_line *old_line);
t_line	*renew_line(t_line *old_line);
void	append_char(t_line *line, char c);
char	*cpytext(t_line *line);

#endif
