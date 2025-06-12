#include "get_next_line.h"
#include <stdio.h>

char	*get_next_line(int fd)
{
	char	*buffer;
	char	*str;
	int		bytes_read;
	size_t		i;

	buffer = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (buffer == NULL)
		return (NULL);
	i = 0;
	while (i <= BUFFER_SIZE)
	{
		buffer[i] = '\0';
		i ++;
 	}
	str = NULL;
	i = 0;
	bytes_read = 1;
	while (bytes_read > 0)
	{
		bytes_read = read(fd, buffer + i, 1);
		if (bytes_read == -1)
		{
			if (buffer != NULL)//these checks here may be redundant because of last statements.
				free(buffer);
			if (str != NULL)
				free(str);
			return (NULL);
		}
		if (i == BUFFER_SIZE - 1 || buffer[i] == '\n')
		{
			str = new_str(buffer, str, i, 0);
			printf("str = %s\n", str);
			if (buffer[i] == '\n')
				break;
			free(buffer);
			buffer = malloc(sizeof(char) * BUFFER_SIZE + 1);
			if (buffer == NULL)
				return (NULL);
			i = 0;
			while (i <= BUFFER_SIZE)
			{
				buffer[i] = '\0';
				i ++;
			}
			i = 0;
		}
		else
		{
			i ++;
		}
	}
	str = new_str(buffer, str, i, 1);
	free(buffer);
	return (str);
}
