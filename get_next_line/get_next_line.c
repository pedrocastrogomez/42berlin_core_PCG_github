#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*storage_buffer;
	char		*newline;
	char		*temp_buffer;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, NULL, 0) < 0)
	{
		if (storage_buffer)
		{
			free(storage_buffer);
			storage_buffer = NULL;
		}
		return (NULL);
	}
	temp_buffer = storage_buffer;
	storage_buffer = read_file(storage_buffer, fd);
	if (storage_buffer == NULL)
		return (NULL);
	if (*storage_buffer == '\0')
	{
		free(storage_buffer);
		storage_buffer = NULL;
		return (NULL);
	}
	newline = cut_newline(storage_buffer);
	if (newline == NULL)
	{
		if (storage_buffer)
		{
			free(storage_buffer);
			storage_buffer = NULL;
		}
		return (NULL);
	}
	temp_buffer = storage_buffer;
	storage_buffer = update_storage_buffer(storage_buffer);
	free(temp_buffer);
	return (newline);
}
