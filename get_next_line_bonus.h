/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abadun <abadun@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 21:31:13 by abadun            #+#    #+#             */
/*   Updated: 2024/10/19 21:54:41 by abadun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

// define buffer size
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# define OPEN_MAX 100000

// includes
# include <unistd.h>
# include <stdlib.h>
# include <stddef.h>

// functions
char	*get_next_line(int fd);

size_t	ft_strlen(const char *str);

char	*ft_strchr(const char *str, int c);

char	*ft_strjoin(char *left_str, char *buf);

char	*ft_strdup(const char *str);

void	*ft_memcpy(void *dest, const void *src, size_t n);

#endif