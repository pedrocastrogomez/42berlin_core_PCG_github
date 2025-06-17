#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*storage_buffer;
	char		*newline;
	char		*updated_storage_buffer;

	if (fd == -1)
		return (NULL);
	storage_buffer = read_file(storage_buffer, fd);
	if (storage_buffer == NULL)
		return (NULL);
	newline = cut_newline(storage_buffer);
	updated_storage_buffer = update_storage_buffer(storage_buffer);
	return (newline);
}
