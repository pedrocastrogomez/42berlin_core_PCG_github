#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*storage_buffer;
	char		*line;

	if (fd < 0 || read(fd, NULL, 0) < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!storage_buffer)
		storage_buffer = ft_calloc(1, sizeof(*storage_buffer));
	if (!ft_strchr(storage_buffer, '\n'))
		storage_buffer = read_file(storage_buffer, fd);
	if (!storage_buffer)
		return (free(storage_buffer), NULL);
	line = cut_line(storage_buffer);
	storage_buffer = update_storage(storage_buffer);
	return (line);
}
