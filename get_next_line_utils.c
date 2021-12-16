/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhumbert <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 18:47:35 by lhumbert          #+#    #+#             */
/*   Updated: 2021/12/16 12:04:56 by lhumbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(char *s)
{
	int	i;

	if (!s)
		return (0);
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

	len = ft_strlen(s);
	ret = (char *)malloc((len + 2) * sizeof(char));
	if (!ret)
		return (NULL);
	i = -1;
	while (++i < len)
		ret[i] = s[i];
	if (s)
		free(s);
	ret[i] = c;
	ret[i + 1] = '\0';
	return (ret);
}
