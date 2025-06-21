#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 4096 //compile with -D BUFFER_SIZE=n
# endif

char	*get_next_line(int fd);
char	*file_reader(char *storing_buffer, int fd);
char	*buffer_joiner(char *storing_buffer, char *reading_buffer);
char	*line_cutter(char *storing_buffer);
char	*storage_updater(char *storing_buffer);
char	*ft_strchr(const char *s, int c);
char	*ft_substr_new(const char *s, unsigned int start, size_t len);
void	*ft_calloc(size_t nmemb, size_t size);
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlen(const char *s);

#endif
