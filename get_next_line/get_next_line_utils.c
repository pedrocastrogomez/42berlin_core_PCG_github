#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i] != '\0')
		i ++;
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char			*ptr;
	unsigned int	i;
	unsigned int	j;

	if (!s1 || !s2)
		return (NULL);
	ptr = malloc(sizeof(*ptr) * ((ft_strlen((const char *)s1)) + ft_strlen((const char *)s2) + 1));
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

void	*ft_calloc(size_t nmemb, size_t size)
{
	void			*ptr;
	unsigned int	i;

	if (nmemb == 0 || size == 0)
		return (malloc(0)); //what if return NULL ?
	if ((nmemb * size) > 2147483647)
		return (NULL);
	ptr = malloc(nmemb * size);
	if (ptr == NULL)
		return (NULL);
	i = 0;
	while (i < (nmemb * size))
	{
		((unsigned char *)ptr)[i] = 0;
		i ++;
	}
	return (ptr);
}

char	*ft_strdup(const char *s)
{
	char	*ptr;
	int		i;

	ptr = malloc(sizeof(char) * (ft_strlen((const char *)s) + 1));
	if (ptr == NULL)
		return (NULL);
	i = 0;
	while (s[i])
	{
		ptr[i] = s[i];
		i ++;
	}
	ptr[i] = '\0';
	return (ptr);
}

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	char			*ptr;
	unsigned int	i;

	i = 0;
	if (s == NULL)
		return (NULL);
	if (start >= ft_strlen(s))
		return (ft_strdup(""));
	if (len >= (ft_strlen(s) - start))
		len = ft_strlen(s) - start;
	ptr = malloc(sizeof(char) * (len + 1));
	if (ptr == NULL)
		return (NULL);
	while (s[start + i] && (i < len))
	{
		ptr[i] = s[start + i];
		i ++;
	}
	ptr[i] = '\0';
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
	return (NULL);
}

char	*storage_updater(char *storing_buffer)
{
	char	*updated_storing;
	char	*start_updated;
	int		length_updated;

	if (!storing_buffer || *storing_buffer == '\0')//is this really necessary? because already in get_new_line theres !storing_buffer before calling this
		return (free(storing_buffer), NULL);
	start_updated = ft_strchr(storing_buffer, '\n');
	if (!start_updated)
		return (free(storing_buffer), NULL);
	length_updated = ft_strlen(start_updated + 1);
	if (length_updated == 0)
		return (free(storing_buffer), NULL);
	updated_storing = ft_substr(storing_buffer, ft_strlen(storing_buffer) - ft_strlen(start_updated + 1), length_updated); 
	if (!updated_storing || *updated_storing == '\0')
		return (free(storing_buffer), NULL);
	free(storing_buffer);
	return (updated_storing);
}

char	*line_cutter(char *storing_buffer)
{
	char	*line;
	int		line_length;
	int		i;

	if (!storing_buffer || *storing_buffer == '\0')//is this really necessary? because already in get_new_line theres !storing_buffer before calling this
		return (NULL);
	i = 0;
	while (storing_buffer[i] && storing_buffer[i] != '\n')
		i ++;
	if (storing_buffer[i] == '\n')
		i ++;
	line_length = i;
	line = ft_calloc(line_length + 1, sizeof(*line));
	i = 0;
	while (i < line_length)
	{
		line[i] = storing_buffer[i];
		i ++;
	}
	line[i] = '\0';
	return (line);
}

char	*buffer_joiner(char *storing_buffer, char *reading_buffer)
{
	char	*joined_buffers;

	joined_buffers = ft_strjoin(storing_buffer, reading_buffer);
	free (storing_buffer);
	return (joined_buffers);
}

char	*file_reader(char *storing_buffer, int fd)
{
	char	*reading_buffer;
	int		byte_count;
	
	reading_buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(*reading_buffer));
	if (!reading_buffer)
	{
		if (storing_buffer)
		{
			free(storing_buffer);
			storing_buffer = NULL;
		}
		return (NULL);
	}
	byte_count = 1;
	while (byte_count > 0)
	{
		byte_count = read(fd, reading_buffer, BUFFER_SIZE);
		if (byte_count < 0)
			return (free(reading_buffer), NULL);//if byte_count < 0 check necessary?
		reading_buffer[byte_count] = '\0';
		storing_buffer = buffer_joiner(storing_buffer, reading_buffer);
		if (ft_strchr(storing_buffer, '\n'))
			break;
	}
	free (reading_buffer);
	return (storing_buffer);
}
