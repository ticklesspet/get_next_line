/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abadun <abadun@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 21:30:53 by abadun            #+#    #+#             */
/*   Updated: 2024/10/20 18:22:58 by abadun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// string len
size_t	ft_strlen(const char *str)
{
	size_t	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

// search for a character inside a string, return pointer with its 1st occurence
char	*ft_strchr(const char *str, int c)
{
	while (*str)
	{
		if (*str == (char)c)
			return ((char *)str);
		str++;
	}
	if ((char)c == '\0')
		return ((char *)str);
	return (NULL);
}

// join strings (concatenate), return the joined string
char	*ft_strjoin(char *str1, char *str2)
{
	char	*concat_str;
	char	*ptr;
	char	*temp;

	temp = str1;
	concat_str = malloc(ft_strlen(str1) + ft_strlen(str2) + 1);
	if (concat_str == NULL)
		return (NULL);
	ptr = concat_str;
	while (*str1)
		*ptr++ = *str1++;
	while (*str2)
		*ptr++ = *str2++;
	*ptr = '\0';
	if (str1)
		free(temp);
	return (concat_str);
}

// duplicate string, return the duplicate
char	*ft_strdup(const char *str)
{
	char	*duplicated_str;
	char	*ptr;

	duplicated_str = malloc(sizeof(char) * (ft_strlen(str) + 1));
	if (!duplicated_str)
		return (NULL);
	ptr = duplicated_str;
	while (*str)
		*ptr++ = *str++;
	*ptr = '\0';
	return (duplicated_str);
}

// copy memory block
void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;

	if (!dst && !src)
		return (NULL);
	i = 0;
	while (i < n)
	{
		((unsigned char *)dst)[i] = ((unsigned char *)src)[i];
		i++;
	}
	return (dst);
}
