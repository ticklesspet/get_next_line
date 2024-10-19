#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

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

char	*ft_strjoin(char *str1, char *str2)
{
	char	*concat_str;
	char	*ptr;
	char 	*temp;

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
