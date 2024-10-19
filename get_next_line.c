#include "get_next_line.h"

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
	substr[n] = 0;
	return (substr);
}

void	ft_free(char **str)
{
	if (!str || !*str)
		return ;
	free(*str);
	*str = NULL;
}

char	*free_both(char **buffer, char **current_line)
{
	ft_free(buffer);
	ft_free(current_line);
	return (NULL);
}

static char	*ft_extract_line_segment(char **str)
{
	char	*segment;
	char	*temp;
	int		i;

	i = 0;
	if (!str || !*str)
		return (NULL);
	while ((*str)[i] != '\n' && (*str)[i] != '\0')
		i++;
	segment = ft_substr(*str, 0, i + 1);
	temp = ft_strdup(*str);
	ft_free(str);
	*str = ft_substr(temp, i + 1, ft_strlen(temp));
	ft_free(&temp);
	if (!ft_strchr(segment, '\n'))
	{
		if (!ft_strlen(segment))
			ft_free(&segment);
		ft_free(str);
	}
	return (segment);
}

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
		buffer[read_size] = 0;
		if (!current_line)
			current_line = ft_strdup(buffer);
		else
			current_line = ft_strjoin(current_line, buffer);
		if (ft_strchr(current_line, '\n'))
			break ;
		read_size = read(fd, buffer, BUFFER_SIZE);
	}
	return (ft_free(&buffer), ft_extract_line_segment(&current_line));
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