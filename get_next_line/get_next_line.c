#include "get_next_line.h"

char	*storage_updater(char *storing_buffer)
{
	char	*updated_storing;
	char	*start_updated;
	int		length_updated;

	if (!storing_buffer || *storing_buffer == '\0')
		return (free(storing_buffer), NULL);
	start_updated = ft_strchr(storing_buffer, '\n');
	if (!start_updated)
		return (free(storing_buffer), NULL);
	length_updated = ft_strlen(start_updated + 1);
	if (length_updated == 0)
		return (free(storing_buffer), NULL);
	updated_storing = ft_substr_new(storing_buffer, ft_strlen(storing_buffer)
			- ft_strlen(start_updated + 1), length_updated);
	if (!updated_storing || *updated_storing == 0)
		return (free(storing_buffer), NULL);
	free(storing_buffer);
	return (updated_storing);
}

char	*line_cutter(char *storing_buffer)
{
	char	*line;
	int		i;

	if (!storing_buffer || *storing_buffer == '\0')
		return (NULL);
	i = 0;
	while (storing_buffer[i] && storing_buffer[i] != '\n')
		i ++;
	if (storing_buffer[i] == '\n')
		i ++;
	line = ft_substr_new(storing_buffer, 0, i);
	if (!line)
		return (NULL);
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

	byte_count = 1;
	while (byte_count > 0)
	{
		reading_buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(*reading_buffer));
		byte_count = read(fd, reading_buffer, BUFFER_SIZE);
		reading_buffer[byte_count] = '\0';
		storing_buffer = buffer_joiner(storing_buffer, reading_buffer);
		if (ft_strchr(storing_buffer, '\n'))
			break ;
		if (byte_count > 0)
			free(reading_buffer);
	}
	free (reading_buffer);
	return (storing_buffer);
}

char	*get_next_line(int fd)
{
	static char	*storing_buffer;
	char		*line;

	if (fd < 0 || read(fd, NULL, 0) < 0 || BUFFER_SIZE <= 0)
	{
		if (storing_buffer)
		{
			free(storing_buffer);
			storing_buffer = NULL;
		}
		return (NULL);
	}
	if (!storing_buffer)
		storing_buffer = ft_calloc(1, sizeof(*storing_buffer));
	if (!ft_strchr(storing_buffer, '\n'))
		storing_buffer = file_reader(storing_buffer, fd);
	if (!storing_buffer)
		return (free(storing_buffer), NULL);
	line = line_cutter(storing_buffer);
	storing_buffer = storage_updater(storing_buffer);
	return (line);
}
