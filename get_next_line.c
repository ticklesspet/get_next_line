/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abadun <abadun@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 21:31:06 by abadun            #+#    #+#             */
/*   Updated: 2024/10/20 18:21:26 by abadun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// extracts substring from string
char	*ft_substr(char const *str, unsigned int start, size_t n)
{
	char	*substr;
	size_t	str_len;

	if (!str)
		return (NULL);
	str_len = ft_strlen(str);
	if (start > str_len - 1)
		n = 0;
	else if (start + n > str_len - 1)
		n = str_len - start;
	substr = malloc(sizeof(char) * n + 1);
	if (!substr)
		return (NULL);
	ft_memcpy(substr, str + start, n);
	substr[n] = '\0';
	return (substr);
}

// free memory 
void	ft_free(char **str)
{
	if (!str || !*str)
		return ;
	free(*str);
	*str = NULL;
}

// frees buffer and the current line (when read_size < 0)
char	*free_both(char **buffer, char **current_line)
{
	ft_free(buffer);
	ft_free(current_line);
	return (NULL);
}

// this function extracts the part of the line before the nl character
// e.g. "111111111111111111 \n aaaaaaaaaaa" -> "111111111111111111\n"
char	*ft_extract_new_line(char **str)
{
	char	*part_before_nl;
	char	*new_str;
	int		i;

	i = 0;
	if (str == NULL || *str == NULL)
		return (NULL);
	while ((*str)[i] != '\0' && (*str)[i] != '\n')
		i++;
	part_before_nl = ft_substr(*str, 0, i + 1);
	new_str = ft_substr(*str, i + 1, ft_strlen(*str));
	ft_free(str);
	*str = new_str; 
	if (!ft_strchr(part_before_nl, '\n')) 
	{
		if (ft_strlen(part_before_nl) == 0)
			ft_free(&part_before_nl);
		ft_free(str);
	}
	return (part_before_nl);
}

// main GNL logic function
char	*get_next_line(int fd)
{
	char		*buffer;
	static char	*current_line;
	int			read_size;

	if (fd == -1 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	read_size = read(fd, buffer, BUFFER_SIZE);
	if (read_size < 0)
		return (free_both(&buffer, &current_line));
	while (read_size > 0)
	{
		buffer[read_size] = '\0';
		if (!current_line)
			current_line = ft_strdup(buffer);
		else
			current_line = ft_strjoin(current_line, buffer);
		if (ft_strchr(current_line, '\n'))
			break ;
		read_size = read(fd, buffer, BUFFER_SIZE);
	}
	return (ft_free(&buffer), ft_extract_new_line(&current_line));
}

// #include <stdio.h>
// #include <fcntl.h>
// int	main(void)
// {
// 	int fd;
// 	fd = open("test", O_RDONLY);
// 	char *result = get_next_line(fd);
// 	printf(">>> GET NEXT LINE: %s\n", result);
// 	free (result);
// 	result = get_next_line(fd);
// 	printf(">>> GET NEXT LINE: %s\n", result);
// 	free (result);
// 	result = get_next_line(fd);
// 	printf(">>> GET NEXT LINE: %s\n", result);
// 	free (result);
// 	result = get_next_line(fd);
// 	printf(">>> GET NEXT LINE: %s\n", result);
// 	free (result);
// 	result = get_next_line(fd);
// 	printf(">>> GET NEXT LINE: %s\n", result);
// 	free (result);
// 	result = get_next_line(fd);
// 	printf(">>> GET NEXT LINE: %s\n", result);
// 	free (result);
// 	result = get_next_line(fd);
// 	printf(">>> GET NEXT LINE: %s\n", result);
// 	free (result);
// 	result = get_next_line(fd);
// 	printf(">>> GET NEXT LINE: %s\n", result);
// 	free (result);
// 	result = get_next_line(fd);
// 	printf(">>> GET NEXT LINE: %s\n", result);
// 	free (result);
// }
