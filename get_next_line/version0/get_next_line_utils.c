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
		return (str);
	}
	byte_count = byte_count + i + 1;
	new_str = malloc(sizeof(char) * byte_count + 1);
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
		free (str);
	}
	k = 0;
	while (buffer[k])
	{
		new_str[j + k] = buffer[k];
		k ++;
	}
	new_str[j + k] = '\0';
	return (new_str);
}
