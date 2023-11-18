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

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	char		*line;
	int			len;

	line = NULL;
	if (fd < 0 || BUFFER_SIZE < 1 || read(fd, buffer, 0) < 0)
		return (NULL);
	len = read(fd, buffer, BUFFER_SIZE);
	if (len < 0)
	{
		if (line)
			free(line);
		len = read(fd, buffer, BUFFER_SIZE);
	}
	return (line);
}
/*
#include <stdio.h>
#include <fcntl.h>

int	main(void)
{
	auto char	*path = "example.txt";
	auto int	 fd = open(path, O_RDONLY);
	char	*line;

	line = get_next_line(fd);
	printf("%s", line);
	free(line);

	close(fd);
	return (0);
}*/
