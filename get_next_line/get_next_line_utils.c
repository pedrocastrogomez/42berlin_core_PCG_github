#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
	{
		i ++;
	}
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
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

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if ((unsigned char)s[i] == (unsigned char)c)
		{
			return (((char *)s) + i);
		}
		i ++;
	}
	if ((char)c == '\0')
	{
		return (((char *)s) + i);
	}
	return (0);
}

char	*update_storage_buffer(char	*storage_buffer)
{
	char	*position_newline;
	size_t	updated_length;
	char	*updated_storage_buffer;
	int		i;

	position_newline = ft_strchr(storage_buffer, '\n');
	if (position_newline == NULL)
		return (NULL);
	updated_length = ft_strlen(position_newline + 1);
	if (updated_length == 0)
	{
		updated_storage_buffer = malloc(sizeof(char) * 1);
		if (!updated_storage_buffer)
			return(NULL);
		updated_storage_buffer[0] = '\0';
		return (updated_storage_buffer);
	}
	updated_storage_buffer = malloc(sizeof(char) * (updated_length + 1));
	if (!updated_storage_buffer)
		return (NULL);
	i = 0;
	while ((position_newline + 1)[i])
	{
		updated_storage_buffer[i] = (position_newline + 1)[i];
		i ++;
	}
	updated_storage_buffer[i] = '\0';
	return (updated_storage_buffer);
}

char	*cut_newline(char *storage_buffer)
{
	char	*position_newline;
	size_t	newline_length;
	char	*newline;
	int		i;

	if (storage_buffer == NULL)
		return (NULL);
	position_newline = ft_strchr(storage_buffer, '\n');
	if (position_newline != NULL)
	{
		newline_length = (ft_strlen(storage_buffer) - ft_strlen(position_newline + 1));
		newline = malloc(sizeof(char) * (newline_length + 1));
	}
	else
	{
		newline = malloc(sizeof(char) * (ft_strlen(storage_buffer) + 1));
	}
	if (!newline)
		return (NULL);
	i = 0;
	while (storage_buffer[i] && storage_buffer[i] != '\n')
	{
		newline[i] = storage_buffer[i];
		i ++;
	}
	if (storage_buffer[i] == '\n')
		newline[i++] = '\n';
	newline[i] = '\0';
	return (newline);
}

char	*join_buffers(char *storage_buffer, char *read_buffer)
{
	char	*new_storage_buffer;
	char	*temp;

	if (!storage_buffer)
	{
		temp = malloc(sizeof(char) * 1);
		if (temp == NULL)
			return (NULL);
		temp[0] = '\0';
	}
	else
	{
		temp = storage_buffer;
	}
	new_storage_buffer = ft_strjoin(temp, read_buffer);
	if (new_storage_buffer == NULL)
	{
		free(temp);
		return (NULL);
	}
	free(temp);
	return (new_storage_buffer);
}

char	*read_file(char *storage_buffer, int fd)
{
	char	*read_buffer;
	int		bytes_read;

	read_buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!read_buffer)
	{
		return (NULL);
	}
	bytes_read = 1;
	while (bytes_read > 0)
	{
		bytes_read = read(fd, read_buffer, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			free(read_buffer);
			return (NULL);
		}
		read_buffer[bytes_read] = '\0';
		if (bytes_read == 0 && (storage_buffer == NULL || *storage_buffer == '\0'))
		{
			free(read_buffer);
			return (NULL);
		}
		storage_buffer = join_buffers(storage_buffer, read_buffer);
		if (storage_buffer == NULL)
		{
			free(read_buffer);
			return (NULL);
		}
		if (ft_strchr(storage_buffer, '\n') || bytes_read == 0)
			break;
	}
	free (read_buffer);
	return (storage_buffer);
}
