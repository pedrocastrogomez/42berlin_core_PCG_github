#include <fcntl.h>
#include <limits.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include "get_next_line.h"

int	main(int argc, char **argv) //compile with -D BUFFER_SIZE=n
{
	int		fd;
	char	*str;
	char	wrong_argc[] = "wrong argc. Write second argument: file name to read from file or 0 to read from stdin";
	if (argc < 2)
	{
		write(1, wrong_argc, strlen(wrong_argc));
	 	return (1);
	}
	if (argv[1][0] == '0')
	{
		fd = 0;
		printf("main: fd is %i\n", fd);
	}
	else
	{
		fd = open(argv[1], O_RDONLY);
		printf("main: fd is %i\n", fd);
	}
	if (fd == -1)
	{
		perror("main: Error creating file");
		return (1);
	}
	int g = 0;
	while (1)
	{
		printf("~~~~~~~~~~~~~~~~~~~~~this is call number %i\n", g);
		str = get_next_line(fd);
		if (str == NULL)
		{
			printf("main: str == NULL\n");
			break;
		}
		printf("main: str = %s\n", str);
		free (str);
		str = NULL;
		g ++;
	}
	close (fd);
	return (0);
}
