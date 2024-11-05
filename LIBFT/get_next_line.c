/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joafaust <joafaust@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 15:29:13 by joafaust          #+#    #+#             */
/*   Updated: 2024/11/05 15:44:42 by joafaust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	nl(char *buf)
{
	int	i;
	int	a;
	int	b;

	i = 0;
	a = 0;
	b = 0;
	while (buf[i])
	{
		if (b == 1)
			buf[a++] = buf[i];
		if (buf[i] == 10)
			b = 1;
		buf[i++] = 0;
	}
	return (b);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	buff[FOPEN_MAX][BUFFER_SIZE + 1];
	int			i;

	i = 0;
	if (fd < 0 || BUFFER_SIZE < 1 || fd >= FOPEN_MAX)
	{
		if (fd > 0 && fd < FOPEN_MAX)
			while (buff[fd][i])
				buff[fd][i++] = 0;
		return (NULL);
	}
	line = NULL;
	while (*(buff[fd]) || read(fd, buff[fd], BUFFER_SIZE) > 0)
	{
		line = ft_strjoin(line, buff[fd]);
		if (nl(buff[fd]) == 1)
			break ;
	}
	return (line);
}
