#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 4096 //compile with -D BUFFER_SIZE=n
#endif

char	*get_next_line(int fd);
char	*new_str(char *buffer, char *str, int i, int reset_byte_count);

#endif
