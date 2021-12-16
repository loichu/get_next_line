/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhumbert <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 18:47:35 by lhumbert          #+#    #+#             */
/*   Updated: 2021/12/15 23:30:16 by lhumbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#include <stdio.h>

int	ft_strlen(char *s)
{
	int	i;

	if (!s)
		return (0);
	i = 0;
	//printf("test\n");
	while (s[i])
		i++;
	//printf("test\n");
	return (i);
}

char	*stradd(char *s, char c)
{
	char	*ret;
	int		len;
	int		i;

	//if (!s)
	//	return (NULL);
	len = ft_strlen(s);
	//printf("len: %i\n", len); 
	ret = (char *)malloc((len + 2) * sizeof(char));
	if (!ret)
		return (NULL);
	//printf("start loop\n");
	i = -1;
	while (++i < len)
		ret[i] = s[i];
	if (s)
		free(s);
	ret[i++] = c;
	ret[i] = '\0';
	return (ret);
}
