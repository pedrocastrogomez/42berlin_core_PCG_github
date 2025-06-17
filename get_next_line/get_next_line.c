#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*storage_buffer;
	char		*newline;
	char		*temp_buffer;

	if (fd == -1)
		return (NULL);
	storage_buffer = read_file(storage_buffer, fd);
	if (storage_buffer == NULL)
		return (NULL);
	newline = cut_newline(storage_buffer);
	temp_buffer = storage_buffer;
	storage_buffer = update_storage_buffer(storage_buffer);
	free(temp_buffer);
	return (newline);
}
