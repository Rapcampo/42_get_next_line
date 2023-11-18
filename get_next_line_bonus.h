/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rapcampo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 12:34:51 by rapcampo          #+#    #+#             */
/*   Updated: 2023/11/18 18:00:13 by rapcampo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

// external libraries

# include <unistd.h>
# include <stdlib.h>

// maximum ammount of FOPEN_MAX is 16
// FD_LIM is defined as FOPEN_MAX in bits/stdio_lim.h 

# ifndef FD_LIM
#  define FD_LIM 16 
# endif

// defining buffer size
// can change buffer size with flag -D BUFFER_SIZE=n

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

// main function

char	*get_next_line(int fd);

// utils

size_t	ft_strlen(char *str);
char	*ft_strchr(char *str, int c);
void	*ft_calloc(size_t nmemb, size_t size);
void	fill_buffer(char *str);
char	*ft_strjoin(char *s1, char *s2);

#endif
