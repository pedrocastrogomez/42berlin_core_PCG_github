#include <fcntl.h>
#include <limits.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include "get_next_line.h"

int	main(int argc, char **argv) //compile with -D BUFFER_SIZE=n
{
	int		fd[3];
	char	*str;
	char	wrong_argc[] = "wrong argc. Write second argument: file name to read from file or 0 to read from stdin";
	int i = 0;
	int j = 1;
	
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
		while (i < 3)
		{
			fd[i] = open(argv[j], O_RDONLY);
			printf("main: fd is %i\n", fd[i]);
			i ++;
			j ++;
		}
	}
	if (fd[i] == -1)
	{
		perror("main: Error creating file");
		return (1);
	}
	int g = 0;
	while (g < 4)
	{
		i = 0;
		while (i < 3)
		{ 
			printf("~~~~~~~~~~~~~~~~~~~~~this is call number %i\n", g);
			str = get_next_line(fd[i]);
			if (str != NULL)
			{
				printf("~~~~~~~~~~~~~~~~~~~~~this was call number %i\n", g);
				printf("main: str = %s\n", str);
				free (str);
			}
			else
				printf("main: str == NULL\n");
			i ++;
		}
		g ++;
	}
	i = 0;
	while (i < 3)
	{
		close (fd[i]);
		i ++;
	}
	return (0);
}
