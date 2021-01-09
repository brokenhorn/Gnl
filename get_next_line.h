#ifndef BUFFER_SIZE
# define BUFFER_SIZE 128
#endif
#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stdlib.h>
# include <unistd.h>

int		get_next_line(int fd, char **line);
size_t		ft_strlen(char *s);
size_t		ft_strlcpy(char *dst, const char *src, size_t size);
char	*ft_strchr(const char *s, int c);
char	*ft_strdup(const char *s1);
char	*ft_strjoin(char const *s1, char const *s2);
void ft_strchngz_zero(char *str);
size_t		ft_strlenn(char *s);
#endif