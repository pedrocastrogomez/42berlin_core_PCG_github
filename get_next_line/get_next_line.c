#include "get_next_line.h"
#include <stdio.h>

char	*new_str(char *buffer, char *str, int i)
{
	char		*new_str;
	int			j;
	int			k;
	static int	byte_count = 0;

	byte_count = byte_count + i;
	printf("new_str: byte_count is %i\n", byte_count);
	new_str = malloc(sizeof(char) * byte_count);
	if (new_str == NULL)
		return (NULL);
	j = 0;
	if (str != NULL)
	{
		while (str[j])
		{
			new_str[j] = str[j];
			j ++;
		}
		printf("new_str: str = %s\n", str);
		printf("new_str: new_str = %s\n", new_str);
		free (str);
	}
	k = 0;
	printf("new_str: buffer = %s\n", buffer);
	while (buffer[k])
	{
		new_str[j + k] = buffer[k];
		printf("new_str: new_str[%i + %i] = %c\n", j, k, new_str[j + k]);
		k ++;
	}
	printf("new_str: new_str = %s\n", new_str);
	return (new_str);
}

char	*get_next_line(int fd)
{
	char	*buffer;
	char	*str;
	int		bytes_read;
	int		i;

	printf("get_new_line: first line of code\n");
	printf("BUFFER_SIZE = %i\n", BUFFER_SIZE);
	buffer = malloc(sizeof(char) * BUFFER_SIZE);
	if (buffer == NULL)
		return (NULL);
	i = 0;
	while (i < BUFFER_SIZE)
	{
		buffer[i] = '\0';
		i ++;
 	}
	printf("get_new_line: buffer succesfully allocated\n");
	str = NULL;
	i = 0;
	bytes_read = 1;
	while (bytes_read > 0)
	{
		printf("buffer says %s\n", buffer);
		printf("str says %s\n", buffer);
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
		printf("get_new_line: buffer[%i] = %c and bytes read = %i\n", i, buffer[i], bytes_read); 
		if (i == BUFFER_SIZE - 1 || buffer[i] == '\n')
		{
			printf("get_new_line: at this point either i == BUFFER_SIZE - 1 || buffer[%i] == '\\n'\n", i);
			str = new_str(buffer, str, i);
			if (buffer[i] == '\n')
				break;
			free(buffer);
			buffer = malloc(sizeof(char) * BUFFER_SIZE);
			i = 0;
		}
		else
		{
			printf("get_new_line: buffer size is still large enough or didn't find '\\n'\n");  
			i ++;
		}
	}
	free(buffer);
	return (str);
}
