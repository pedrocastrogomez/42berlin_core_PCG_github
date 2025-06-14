#include "get_next_line.h"
#include <stdio.h>

char	*get_next_line(int fd)
{
	char	*buffer;
	char	*str;
	int		bytes_read;
	int		i;

	printf("get_new_line: BUFFER_SIZE = %i\n", BUFFER_SIZE);
	buffer = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (buffer == NULL)
		return (NULL);
	i = 0;
	while (i <= BUFFER_SIZE)
	{
		buffer[i] = '\0';
		i ++;
 	}
	printf("get_new_line: after mallocd and 0 populated, buffer is %s\n", buffer);
	str = NULL;
	i = 0;
	bytes_read = 1;
	while (bytes_read > 0)
	{
		printf("get_new_line: buffer says %s\n", buffer);
		printf("get_new_line: str says %s\n", buffer);
		bytes_read = read(fd, buffer + i, 1);
		printf("get_new_line: buffer[%i] = %c and bytes read = %i\n", i, buffer[i], bytes_read);
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
			printf("get_new_line: at this point either i == BUFFER_SIZE - 1 || buffer[%i] == '\\n'\n", i);
			str = new_str(buffer, str, i, 0);
			if (buffer[i] == '\n')
				break;
			free(buffer);
			buffer = malloc(sizeof(char) * BUFFER_SIZE);
			if (buffer == NULL)
				return (NULL);
			i = 0;
			while (i <= BUFFER_SIZE)
			{
				buffer[i] = '\0';
				printf("+++++++++++++++get_new_line: after mallocd and 0 populated, buffer[i] is %c\n", buffer[i]);
				i ++;
			}
			i = 0;
		}
		else
		{
			printf("get_new_line: buffer size is still large enough or didn't find '\\n'\n");  
			i ++;
		}
	}
	new_str(buffer, str, i, 1);
	free(buffer);
	return (str);
}
