#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if ((unsigned char)s[i] == (unsigned char)c)
		{
			return (((char *)s) + i);
		}
		i ++;
	}
	if ((char)c == '\0')
	{
		return (((char *)s) + i);
	}
	return (0);
}
