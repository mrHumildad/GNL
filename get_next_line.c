/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnotaro <mnotaro@student.42barcelo>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 16:42:40 by mnotaro           #+#    #+#             */
/*   Updated: 2023/10/15 18:09:42 by mnotaro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
//#include <unistd.h>
#include <fcntl.h>			//TEST
#include <stdio.h>          //TEST
//#include <stdlib.h>

static int find_n(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '\n')
			return (i);
		else
			i++;
	}
	//printf("find n : %d\n", i);
	return (-1);
}

char *get_next_line(int fd)
{
	char		*line;
	static char	*buff[MAX_OPEN];
	int			cread;

	line = NULL;
	if (fd < 0 || fd > MAX_OPEN || BUFFER_SIZE <= 0)
		return (line);
//	printf("executing GNL on fd [%d], buff = [%s]\n", fd, buff[fd]);
	if (!buff[fd])
	{
		buff[fd] = malloc(sizeof(char) * BUFFER_SIZE + 1);
		cread = read(fd, buff[fd], BUFFER_SIZE);	
//		printf("buff(%d) = [%s]\n", cread, buff[fd]);
	}

	while (!(ft_strchr(buff[fd], '\n')) || cread > 0)
	{
		line = ft_strjoin(line, buff[fd]);
		cread = read(fd, buff[fd], BUFFER_SIZE);
//		printf("buff(%d) = [%s]\n", cread, buff[fd]);
	}
	line = ft_strjoin(line, ft_substr(buff[fd], 0, find_n(buff[fd])));
	buff[fd] = ft_strchr(buff[fd], '\n');
	return (line);
}

int main (void)
{
	char *firstline;
	char *secondline;
	int fd = open("testfile.txt", O_RDONLY);
	
	firstline = get_next_line(fd);	
	printf("first line :  %s\n", firstline);
	secondline = get_next_line(fd);
	printf("second line :  %s\n", secondline);
	return (0);
}
