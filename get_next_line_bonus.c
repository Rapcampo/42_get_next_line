/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rapcampo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 12:34:43 by rapcampo          #+#    #+#             */
/*   Updated: 2023/11/03 12:34:47 by rapcampo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_next_line(int fd)
{
	static char	buffer[FD_LIM][BUFFER_SIZE + 1];
	char		*line;
	ssize_t		len;

	line = NULL;
	if (fd < 0 || fd >= FD_LIM || BUFFER_SIZE < 1)
		return (NULL);
	len = 1;
	if (!buffer[fd][0])
		len = read(fd, buffer[fd], BUFFER_SIZE);
	while (len > 0)
	{
		line = ft_strjoin(line, buffer[fd]);
		if (ft_strchr(line, '\n'))
			break ;
		len = read(fd, buffer[fd], BUFFER_SIZE);
	}
	if (len < 0)
	{
		if (line)
			free(line);
		return (NULL);
	}
	return (line);
}
/*
#include <stdio.h>
#include <fcntl.h>

int	main(void)
{
	auto int	 fd = open("example.txt", O_RDONLY);
	auto int	 fd2 = open("example2.txt", O_RDONLY);
	auto int	 fd3 = open("example3.txt", O_RDONLY);
	char	*line;

	line = get_next_line(fd);
	printf("%s", line);
	free(line);
	
	line = get_next_line(fd2);
	printf("%s", line);
	free(line);

	line = get_next_line(fd);
	printf("%s", line);
	free(line);

	line = get_next_line(fd3);
	printf("%s", line);
	free(line);

	line = get_next_line(fd3);
	printf("%s", line);
	free(line);

	line = get_next_line(fd3);
	printf("%s", line);
	free(line);

	line = get_next_line(fd3);
	printf("%s", line);
	free(line);

	line = get_next_line(fd3);
	printf("%s", line);
	free(line);

	close(fd);
	return (0);
}*/
