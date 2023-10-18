/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnotaro <mnotaro@student.42barcelo>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 16:47:31 by mnotaro           #+#    #+#             */
/*   Updated: 2023/10/15 18:02:10 by mnotaro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef BUFFER_SIZE
#  define BUFFER_SIZE 6
#endif
#define MAX_OPEN 1024

#include <unistd.h>
#include <stdio.h>			//TEST
#include <stdlib.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

char	*get_next_line(int fd);
char    *ft_substr(char const *s, unsigned int start, size_t len);
int		ft_strlen(const char *str);
char    *ft_strjoin(char const *s1, char const *s2);
char    *ft_strchr(const char *str, int c);
