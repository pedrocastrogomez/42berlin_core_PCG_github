#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int	main(int argc, char **argv)
{
	int		fd;
	char	*buffer;
	size_t	nbyte;
	int		bytes_read;

	if (argc == 1)
	{
		fd = 0;
	}
	else
	{
		fd = open(argv[1], O_RDONLY);
		if (fd == -1)
		{
			perror("error creating file");
			return (fd);
		}
	}
	nbyte = 1;
	bytes_read = 1;
	while (bytes_read > 0)
	{
		buffer = malloc(sizeof(char) * nbyte);
		if (buffer == NULL)
		{
			break ;
		}
		bytes_read = read(fd, buffer, nbyte);
		if (bytes_read == -1)
		{
			free (buffer);
			close (fd);
			return (-1);
		}
		else if (bytes_read == 0)
		{
			write(1, "bytes_read: 0", 13);
			free (buffer);
			break ;
		}
		if (buffer[0] != '\n')
		{
			write(1, buffer, bytes_read);
		}
		else
		{
			write(1, " for you", 8);
			write(1, buffer, bytes_read);
			free (buffer);
			break ;
		}
		free(buffer);
	}
	close (fd);
	return (0);
}
