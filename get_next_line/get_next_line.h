#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 4096 //compile with -D BUFFER_SIZE=n
#endif

char	*get_next_line(int fd);
char	*read_file(char *storage_buffer, int fd);
char	*join_buffers(char *storage_buffer, char *read_buffer);
char	*cut_line(char *storage_buffer);
char	*update_storage(char *storage_buffer);
char	*ft_strchr(const char *s, int c);
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlen(const char *s);
void	*ft_malloc(size_t nmemb, size_t size);

#endif
