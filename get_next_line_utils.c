/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhumbert <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 18:47:35 by lhumbert          #+#    #+#             */
/*   Updated: 2021/12/15 21:07:49 by lhumbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*stradd(char *s, char c)
{
	char	*ret;
	int		len;
	int		i;

	if (!s)
		return (NULL);
	len = ft_strlen(s) + 2;
	ret = (char *)malloc(len * sizeof(char));
	if (!ret)
		return (NULL);
	i = -1;
	while (s[++i])
		ret[i] = s[i];
	free(s);
	ret[i++] = c;
	ret[i] = '\0';
	return (ret);
}
