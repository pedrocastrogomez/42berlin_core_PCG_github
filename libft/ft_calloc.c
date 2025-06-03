#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void			*ptr;
	unsigned int	i;

	if (nmemb == 0 || size == 0)
	{
		return (malloc(0));
	}
	if ((nmemb * size) > 2147483647)
	{
		return (NULL);
	}
	ptr = malloc(nmemb * size);
	if (ptr == NULL)
	{
		return (NULL);
	}
	i = 0;
	while (i < (nmemb * size))
	{
		((unsigned char *)ptr)[i] = 0;
		i ++;
	}
	return (ptr);
}
