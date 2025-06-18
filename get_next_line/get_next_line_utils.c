#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i ++;
	return (i);
}

void	*ft_malloc(size_t nmemb, size_t size)
{
	char	*ptr;

	if (nmemb == 0 || size == 0)
		return (malloc(0));
	ptr = malloc(nmemb * size);
	if (!ptr)
		return (NULL);
	ptr[nmemb - 1] = '\0';
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
	if (!newline_pos) //makes sense: if no newline is found why bother updating? i.e. EOF
		return (free(storage_buffer), NULL);
	len_newline_pos = ft_strlen((const char *)newline_pos + 1);
	updated_storage_buffer = ft_malloc(len_newline_pos + 1, sizeof(updated_storage_buffer));
	i = 0;
	while (i < len_newline_pos)
	{
		updated_storage_buffer[i] = (newline_pos + 1)[i];
		i ++;
	}
	// updated_storage_buffer is already null terminated in ft_malloc.
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
	line = ft_malloc(len + 1, sizeof(*line));
	i = 0;
	while (i < len)
	{
		line[i] = storage_buffer[i];
		i ++;
	} //line is already null terminated with ft_malloc.
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

	if (!storage_buffer)
		return (NULL);
	bytes_read = 1;
	while (bytes_read > 0)
	{
		read_buffer = ft_malloc(BUFFER_SIZE + 1, sizeof(*read_buffer));
		if (!read_buffer)
			return (NULL);
		bytes_read = read(fd, read_buffer, BUFFER_SIZE);
		storage_buffer = join_buffers(storage_buffer, read_buffer);
		if (!storage_buffer)
			return (NULL);
		if (ft_strchr(storage_buffer, '\n'))
	  	{
	  		free (read_buffer);
			break;
	  	}
	  	free(read_buffer);
	}
	return (storage_buffer);
}
