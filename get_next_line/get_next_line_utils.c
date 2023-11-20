/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abostano <abostano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 14:14:07 by abostano          #+#    #+#             */
/*   Updated: 2023/11/20 14:53:46 by abostano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin(const char *str1, const char *str2)
{
	char	*r;
	int		a;
	int		b;

	a = 0;
	b = 0;
	r = malloc((ft_strlen(str1) + ft_strlen(str2)) * sizeof(char) + 1);
	if (!r || !str1 || !str2)
		return (0);
	while (str1[a])
	{
		r[a] = str1[a];
		a++;
	}
	while (str2[b])
	{
		r[a] = str2[b];
		a++;
		b++;
	}
	r[a] = '\0';
	return (r);
}

char	*ft_strchr(const char *str, int c)
{
	while (*str != (unsigned char)c)
		if (!*str++)
			return (0);
	return ((char *)str);
}

void	*ft_calloc(size_t num, size_t size)
{
	size_t	sz;
	void	*n;

	if (num == 0 || size == 0)
	{
		num = 1;
		size = 1;
	}
	sz = num * size;
	n = malloc(sz);
	if (n == NULL)
		return (0);
	else
		ft_bzero(n, sz);
	return (n);
}

size_t	ft_strlen(const char *a)
{
	size_t	i;

	i = 0;
	while (a[i] != '\0')
		i++;
	return (i);
}

void	ft_bzero(void *s, size_t n)
{
	char	*str;
	size_t	i;

	str = (char *)s;
	i = 0;
	while (i < n)
	{
		str[i] = '\0';
		i++;
	}
}
