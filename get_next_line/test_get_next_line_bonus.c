#include <fcntl.h>
#include <limits.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include "get_next_line.h"

int	main(int argc, char **argv) //compile with -D BUFFER_SIZE=n
{
	int		fd[1048576];
	char	*str;
	char	wrong_argc[] = "wrong argc. Write arguments: files names to read from file or 0 to read from stdin";
	int	i;
	
	i = 0;
	if (argc < 2)
	{
		write(1, wrong_argc, strlen(wrong_argc));
	 	return (1);
	}
	if (argv[1][0] == '0')
	{
		fd[0] = 0;
		printf("main: fd is %i\n", fd[0]);
	}
	else
	{
		while (i < argc - 1)
		{
			fd[i] = open(argv[i + 1], O_RDONLY);
			if (fd[i] == -1)
				return (perror("main: Error creating file"), 1);
			printf("main: fd is %i\n", fd[i]);
			i ++;
		}
	}
	i = 0;
	while (i < argc - 1)
	{
		while (1)
		{
			printf("~~~~~~~~~~~~~~~~~~~~~this is call number %i\n", i);
			str = get_next_line(fd[i]);
			if (str == NULL)
			{
				printf("main: str == NULL\n");
				break;
			}
			printf("main: str = %s\n", str);
			free (str);
			str = NULL;
		}
		close (fd[i]);
		i ++;
	}
	return (0);
}
