#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != '\0')
		i ++;
	return (i);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	void			*ptr;
	unsigned int	i;

	if (nmemb == 0 || size == 0)
	{
		return (malloc(0));
	}
	if ((nmemb * size) > 2147483647)
	{
		return (NULL);
	}
	ptr = malloc(nmemb * size);
	if (ptr == NULL)
	{
		return (NULL);
	}
	i = 0;
	while (i < (nmemb * size))
	{
		((unsigned char *)ptr)[i] = 0;
		i ++;
	}
	return (ptr);
}

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if ((unsigned char)s[i] == (unsigned char)c)
			return (((char *)s) + i);
		i ++;
	}
	if ((char)c == '\0')
		return (((char *)s) + i);
	return (0);
}

char	*ft_strjoin(const char *s1, const char *s2)
{
	char			*ptr;
	unsigned int	i;
	unsigned int	j;

	if (!s1 || !s2)
		return (NULL);
	ptr = malloc(sizeof(char) * ((ft_strlen((const char *)s1))
			  + ft_strlen((const char *)s2) + 1));
	if (!ptr)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		ptr[i] = s1[i];
		i ++;
	}
	j = 0;
	while (s2[j])
	{
		ptr[i + j] = s2[j];
		j ++;
	}
	ptr[i + j] = '\0';
	return (ptr);
}

char	*update_storage(char *storage_buffer)
{
	char	*newline_pos;
	char	*updated_storage_buffer;
	int		len_newline_pos;
	int		i;

	if (!storage_buffer || *storage_buffer == '\0')
		return (free(storage_buffer), NULL);
	newline_pos = ft_strchr(storage_buffer, '\n');
	if (!newline_pos)
		return (free(storage_buffer), NULL);
	len_newline_pos = ft_strlen((const char *)newline_pos + 1);
	if (len_newline_pos == 0)
		return (free(storage_buffer), NULL);
	updated_storage_buffer = ft_calloc(len_newline_pos + 1, sizeof(*updated_storage_buffer));
	if (!updated_storage_buffer)
		return (free(storage_buffer), NULL);
	i = 0;
	while (i < len_newline_pos)
	{
		updated_storage_buffer[i] = (newline_pos + 1)[i];
		i ++;
	}
	free (storage_buffer);
	return (updated_storage_buffer);
}

char	*cut_line(char *storage_buffer)
{
	char	*line;
	int		len;
	int		i;

	if (!storage_buffer || *storage_buffer == '\0')
		return (NULL);
	i = 0;
	while (storage_buffer[i] && storage_buffer[i] != '\n')
		i ++;
	len = i;
	if (storage_buffer[i] == '\n')
		len ++;
	line = ft_calloc(len + 1, sizeof(*line));
	i = 0;
	while (i < len)
	{
		line[i] = storage_buffer[i];
		i ++;
	}
	return (line);
}

char	*join_buffers(char *storage_buffer, char *read_buffer)
{
	char	*joint_buffer;

	joint_buffer = ft_strjoin(storage_buffer, read_buffer);
	free (storage_buffer);
	return (joint_buffer);
}

char	*read_file(char *storage_buffer, int fd)
{
	char	*read_buffer;
	int		bytes_read;

	bytes_read = 1;
	while (bytes_read > 0)
	{
		read_buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(*read_buffer));
		if (!read_buffer)
			return (NULL);
		bytes_read = read(fd, read_buffer, BUFFER_SIZE);
		storage_buffer = join_buffers(storage_buffer, read_buffer);
		if (!storage_buffer)
			return (free(read_buffer), (NULL));
		if (ft_strchr(storage_buffer, '\n'))
	  	{
	  		free (read_buffer);
			break;
	  	}
	  	free(read_buffer);
	}
	return (storage_buffer);
}
