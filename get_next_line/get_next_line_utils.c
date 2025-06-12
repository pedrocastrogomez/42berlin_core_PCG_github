#include "get_next_line.h"
#include <stdio.h>

char	*new_str(char *buffer, char *str, int i, int reset_byte_count)
{
	char		*new_str;
	int			j;
	int			k;
	static int	byte_count = 0;

	if (reset_byte_count > 0)
	{
		byte_count = 0;
		return (NULL);
	}
	byte_count = byte_count + i + 1;
	printf("new_str: ********************byte_count is %i\n", byte_count);
	new_str = malloc(sizeof(char) * byte_count + 1);
	if (new_str == NULL)
		return (NULL);
	j = 0;
	while (j <= byte_count)
	{
		new_str[j] = '\0';
		j ++;
	}
	j = 0;
	if (str != NULL)
	{
		while (str[j])
		{
			new_str[j] = str[j];
			j ++;
		}
		printf("new_str: when copying str into new_str, str = %s\n", str);
		printf("new_str: when copying str into new_str, new_str = %s\n", new_str);
		free (str);
	}
	k = 0;
	printf("new_str: when copying buffer into new_str, buffer = %s\n", buffer);
	while (buffer[k])
	{
		new_str[j + k] = buffer[k];
		printf("new_str: when copying buffer into new_str, new_str[%i + %i] = %c\n", j, k, new_str[j + k]);
		k ++;
	}
	printf("new_str: complete new string after copying str + buffer, new_str = %s\n", new_str);
	return (new_str);
}
