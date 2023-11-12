/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abostano <abostano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 14:14:07 by abostano          #+#    #+#             */
/*   Updated: 2023/11/09 14:14:17 by abostano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*new;
	size_t	slen;
	size_t	finish;

	if (!s || !*s)
		return (ft_strdup(""));
	slen = ft_strlen(s);
	finish = 0;
	if (start < slen)
		finish = slen - start;
	if (finish > len)
		finish = len;
	if (start > slen || len == 0)
		return (ft_strdup(""));
	new = (char *)malloc(sizeof(char) * (finish + 1));
	if (!new)
		return (0);
	ft_strlcpy(new, s + start, finish + 1);
	return (new);
}

size_t	ft_strlen(const char *a)
{
	size_t	i;

	i = 0;
	while (a[i] != '\0')
		i++;
	return (i);
}

size_t  ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	x;

	x = ft_strlen(src);
	i = 0;
	if (size != 0)
	{
		while (src [i] != '\0' && i < size - 1)
		{
			dest[i] = src[i];
			i++;
		}
		dest[i] = '\0';
	}
	return (x);
}

char	*ft_strdup(const char *str)
{
	size_t	a;
	char	*r;

	a = ft_strlen(str);
	r = (char *)malloc(sizeof(char) * (a + 1));
	if (!r)
		return (0);
	ft_strlcpy(r, str, a + 1);
	return (r);
}