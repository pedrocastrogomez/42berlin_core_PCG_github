#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i] != '\0')
		i ++;
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char			*ptr;
	unsigned int	i;
	unsigned int	j;

	if (!s1 || !s2)
		return (NULL);
	ptr = malloc(sizeof(*ptr) * ((ft_strlen((const char *)s1))
				+ ft_strlen((const char *)s2) + 1));
	if (!ptr)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		ptr[i] = s1[i];
		i ++;
	}
	j = 0;
	while (s2[j])
	{
		ptr[i + j] = s2[j];
		j ++;
	}
	ptr[i + j] = '\0';
	return (ptr);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	void			*ptr;
	unsigned int	i;

	if (nmemb == 0 || size == 0)
		return (malloc(0));
	if ((nmemb * size) > 2147483647)
		return (NULL);
	ptr = malloc(nmemb * size);
	if (ptr == NULL)
		return (NULL);
	i = 0;
	while (i < (nmemb * size))
	{
		((unsigned char *)ptr)[i] = 0;
		i ++;
	}
	return (ptr);
}

char	*ft_substr_new(const char *s, unsigned int start, size_t len)
{
	char			*ptr;
	unsigned int	i;

	i = 0;
	if (s == NULL)
		return (NULL);
	if (start >= ft_strlen(s))
	{
		ptr = malloc(1);
		if (!ptr)
			return (NULL);
		return (*ptr = '\0', ptr);
	}
	if (len >= (ft_strlen(s) - start))
		len = ft_strlen(s) - start;
	ptr = malloc(sizeof(char) * (len + 1));
	if (ptr == NULL)
		return (NULL);
	while (s[start + i] && (i < len))
	{
		ptr[i] = s[start + i];
		i ++;
	}
	ptr[i] = '\0';
	return (ptr);
}

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if ((unsigned char)s[i] == (unsigned char)c)
			return (((char *)s) + i);
		i ++;
	}
	if ((char)c == '\0')
		return (((char *)s) + i);
	return (NULL);
}
