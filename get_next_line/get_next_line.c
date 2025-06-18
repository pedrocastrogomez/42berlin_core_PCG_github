#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*storage_buffer;
	char		*line;

	if (fd < 0 || read(fd, NULL, 0) < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!storage_buffer) //what would happen if NULL was returned instead?
		storage_buffer = ft_malloc(1, sizeof(*storage_buffer));
	if (!storage_buffer)
		return (NULL);
	storage_buffer = read_file(storage_buffer, fd);
	if (!ft_strchr(storage_buffer, '\n')) //really?
		return (free(storage_buffer), NULL);
	line = cut_line(storage_buffer); //control if (!line) ?
	storage_buffer = update_storage(storage_buffer); //ownership? free where?
	return (line);
}

/*
*get_next_line; static char *storage_buffer(initialize to 1 byte), char *line; 
	read_file; char *read_buffer, int bytes_read; ...free(read_buffer)
		join_buffers; char *temp ...free(storage_buffer)
			ft_strjoin;
	cut_line; char *line, int len, int i;
		ft_strlen;
		ft_strchr;
		ft_malloc;
	update_storage; char *newline_pos, char *updated_storage_buffer, int len_newline_pos, int i; ...free)storage_buffer, return NULL;
		ft_strlen;
		ft_strchr;
		ft_malloc;
*/
