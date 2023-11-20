/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abostano <abostano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 14:12:32 by abostano          #+#    #+#             */
/*   Updated: 2023/11/20 15:13:31 by abostano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_freenjoin(char *buf, char *buffer)
{
	char	*tmp;

	tmp = ft_strjoin(buf, buffer);
	free(buf);
	return (tmp);
}

char	*ft_beforeline(char *buf, int fd)
{
	char	*buffer;
	int		a;

	if (!buf)
		buf = ft_calloc(1, 1);
	buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	a = 1;
	while (!ft_strchr(buffer, '\n') && a)
	{
		a = read(fd, buffer, BUFFER_SIZE);
		if (a == -1)
		{
			free(buffer);
			free(buf);
			return (NULL);
		}
		buffer[a] = 0;
		buf = ft_freenjoin(buf, buffer);
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	free(buffer);
	return (buf);
}

char	*ft_afterline(char *buffer)
{
	char	*afterline;
	int		a;
	int		b;

	a = 0;
	while (buffer[a] && buffer[a] != '\n')
		a++;
	if (!buffer[a])
	{
		free(buffer);
		return (NULL);
	}
	afterline = ft_calloc(ft_strlen(buffer) - a + 1, sizeof(char));
	a++;
	b = 0;
	while (buffer[a])
		afterline[b++] = buffer[a++];
	free(buffer);
	return (afterline);
}

char	*ft_line(char	*buffer)
{
	char	*line;
	int		a;

	a = 0;
	if (!buffer[a])
		return (NULL);
	while (buffer[a] && buffer[a] != '\n')
		a++;
	line = ft_calloc(a + 2, sizeof(char));
	a = 0;
	while (buffer[a] && buffer[a] != '\n')
	{
		line[a] = buffer[a];
		a++;
	}
	if (buffer[a] && buffer[a] == '\n')
		line[a++] = '\n';
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*buf;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	buffer = ft_beforeline(buffer, fd);
	if (!buffer)
		return (NULL);
	buf = ft_line(buffer);
	buffer = ft_afterline(buffer);
	return (buf);
}
