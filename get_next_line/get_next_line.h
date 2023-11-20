/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abostano <abostano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 14:13:33 by abostano          #+#    #+#             */
/*   Updated: 2023/11/20 14:29:39 by abostano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42

# endif

# include <unistd.h>
# include <stdlib.h>

char	*get_next_line(int fd);
char	*ft_strjoin(const char *str1, const char *str2);
char	*ft_strchr(const char *str, int c);
void	*ft_calloc(size_t num, size_t size);
size_t	ft_strlen(const char *a);
void	ft_bzero(void *s, size_t n);

#endif