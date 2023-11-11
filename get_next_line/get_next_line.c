/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abostano <abostano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 14:12:32 by abostano          #+#    #+#             */
/*   Updated: 2023/11/11 13:53:00 by abostano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_read(int fd)
{
	char	*buf;
	int	val;
	
	val = 0;
	buf = malloc(sizeof(char) * BUFFER_SIZE + 1);
	while (val > 0)
	{
		val += read(fd, buf, BUFFER_SIZE);
	}
}

char	*get_next_line(int fd)
{
	char	*readable;
}
