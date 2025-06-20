#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*storing_buffer;
	char	*line;

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
	if (!ft_strchr(storing_buffer, '\n'))//what happens without this line?
		storing_buffer = file_reader(storing_buffer, fd);
	if (!storing_buffer)
		return (free(storing_buffer), NULL);
	line = line_cutter(storing_buffer);
	storing_buffer = storage_updater(storing_buffer);
	return (line);
}
