#include "get_next_line.h"

size_t		ft_strlen(char *s)
{
	int i;

	if(s == NULL)
		return (0);
	i = 0;
	while (*(s + i) != '\0')
		i++;
	return (i);
}

size_t		ft_strlcpy(char *dst, const char *src, size_t size)
{
	int i;

	i = 0;
	if (dst == 0 || src == 0)
		return (0);
	while (*(src + i) != '\0')
		i++;
	if (size == 0)
		return (i);
	while (*src != '\0' && size - 1 > 0)
	{
		*dst = *src;
		dst++;
		src++;
		size--;
	}
	*dst = '\0';
	return (i);
}


char	*ft_strchr(const char *s, int c)
{
	char ch;
	char *s1;

	s1 = 0;
	ch = c;
	while (*s != '\0')
	{
		if (*s == ch)
			s1 = (char *)s;
		s++;
	}
	if (ch == '\0')
		return ((char *)s);
	if (s1 != 0)
		return ((char *)s1);
	return (NULL);
}

char	*ft_strdup(const char *s1)
{
	char *m;

	if(s1 == NULL)
		return(NULL);
	m = malloc(1 * ft_strlen((char *)s1) + 1);
	if (m == 0)
		return (0);
	ft_strlcpy(m, s1, ft_strlen((char *)s1) + 1);
	return (m);
}

char	*ft_strjoin(char const *s1, char const *s2) // dupjoin
{
	size_t	len;
	char	*m;
	int i;

	//if (s1 == 0 || s2 == 0)
	//	return (s2);
	len = ft_strlen((char *)s1) + ft_strlen((char *)s2);
	m = malloc(sizeof(char) * len + 1);
	if (m == 0)
		return (0);
	while ((s1 != NULL) && (*s1 != '\0'))
		*m++ = *s1++;
	while (*s2 != '\0')
		*m++ = *s2++;
	*m = '\0';
	if (s1 != NULL)
	{
		free((void*)s1);
	}
	return (m - len);
}

void ft_strchngz_zero(char *str)
{
	if (str == NULL)
		return;
	while(*str)
	{
		if (*str == '\n')
			*str = '\0';
		str++;
	}
}
