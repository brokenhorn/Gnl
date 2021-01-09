/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmaricru <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 17:40:01 by vmaricru          #+#    #+#             */
/*   Updated: 2020/11/27 18:29:28 by vmaricru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"



char *ft_rmd(char *buffer)
{
	char *m;
	int len;
	int i;

	i = 0;
	while(*buffer != '\n') // или 0?
		buffer++;
	m = (char *)malloc(sizeof(char) * ft_strlen(buffer) );
	len = ft_strlen(buffer);
	buffer++;
	while(buffer[i] != '\0')
	{
		m[i] = buffer[i];
		i++;
	}
	m[i] = '\0';
	return(m);
}

int		ft_read_line(char **rmd, int fd, char **line)
{
	int rd;
	char buffer[BUFFER_SIZE +1];
	char *str;
	int flag;

	flag = 1;
	str = *rmd;
	while ((flag != 0) && (rd = read(fd, buffer, BUFFER_SIZE)))
	{
		if (rd == -1) // переделать обработку
		{
			if(str)
				free(str);
			return (rd);
		}
		buffer[rd] = '\0';
		str = ft_strjoin(str, buffer);
		if (ft_strchr(buffer, '\n'))
		{
			*rmd = ft_rmd(buffer);
			flag = 0;
			ft_strchngz_zero(str);
			rd = 1;
		}
	}
	*line = ft_strdup(str); // delete dub
	free(str);
	return (rd);
}

int ft_check_rmd(char **rmd, char **line)// end of a file?
{
	char *str = ft_strdup(*rmd); // delete dub
	if (ft_strchr(*rmd, '\n'))
	{
		ft_strchngz_zero(str);
		*rmd = ft_rmd(*rmd);
		*line = ft_strdup(str); // delete dub
		free(str);
		return(1);
	}
	return(0);
}

int		get_next_line(int fd, char **line)
{
	static char *rmd = NULL;
	int check;

	check = 0;
	char *c = rmd;
	if(rmd)
		check = ft_check_rmd(&rmd, line);
	if(check == 1)
		return (1);
	int f = ft_read_line(&rmd, fd, line);
	c = rmd;
	return (f);
}
