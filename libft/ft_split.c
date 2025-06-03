#include "libft.h"

static size_t	ft_count_words(char const *s, char c)
{
	size_t	words;
	int		i;

	words = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] == c)
		{
			i ++;
		}
		if (s[i] && s[i] != c)
		{
			words ++;
		}
		while (s[i] && s[i] != c)
		{
			i ++;
		}
	}
	return (words);
}

static size_t	ft_len(char *start, char c)
{
	size_t	len;

	len = 0;
	while (*start && *start == c)
	{
		start ++;
	}
	while (*start && *start != c)
	{
		start ++;
		len ++;
	}
	return (len);
}

static int	ft_alloc_protect(char **arr, char *t, char c, size_t words)
{
	int		i;
	size_t	len;

	i = 0;
	while (i < (int)words)
	{
		while (*t && *t == c)
			t ++;
		len = ft_len(t, c);
		arr[i] = ft_substr(t, 0, len);
		if (!arr[i])
		{
			i --;
			while (i >= 0)
				free(arr[i--]);
			free(arr);
			arr = (NULL);
			return (-1);
		}
		t += len;
		i ++;
	}
	arr[i] = NULL;
	return (0);
}

char	**ft_split(char const *s, char c)
{
	int		fail;
	char	**arr;
	char	*t;
	size_t	words;

	if (!s)
		return (NULL);
	words = ft_count_words(s, c);
	arr = malloc(sizeof(char *) * (words + 1));
	if (!arr)
		return (NULL);
	t = (char *)s;
	fail = ft_alloc_protect(arr, t, c, words);
	if (fail)
		return (NULL);
	return (arr);
}
