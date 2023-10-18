/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnotaro <mnotaro@student.42barcelo>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 15:02:09 by mnotaro           #+#    #+#             */
/*   Updated: 2023/10/15 18:07:19 by mnotaro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"


char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned int	slen;
	char			*res;
	char			*first;

	if (!s)
		return (NULL);
	slen = ft_strlen((char *)s);
	if (start > slen)
		len = 0;
	else if (len > slen - start)
		len = slen - start;
	res = (char *)malloc((len + 1) * sizeof(char));
	if (!res)
		return (NULL);
	first = res;
	s = s + start;
	while (len--)
		*res++ = *s++;
	*(res + len + 1) = '\0';
	return (first);
}

int	ft_strlen(const char *str)

{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*res;
	int		i;
	int		l1;
	int		l2;

	l1 = ft_strlen((char *)s1);
	l2 = ft_strlen((char *)s2);
	i = 0;
	res = (char *)malloc(sizeof(char) *(l1 + l2 + 1));
	if (!res)
		return (NULL);
	while (i < l1)
	{
		res[i] = s1[i];
		i++;
	}
	while (i < (l1 + l2 +1))
	{
		res[i] = s2[i - l1];
		i++;
	}
	res[l1 + l2 + 1] = '\0';
	return (res);
}
 
char	*ft_strchr(const char *str, int c)
{
	char	ch;
	char	*res;

	res = (char *)str;
	ch = c;
	while (*res != '\0')
	{
		if (*res == ch)
		{
			res++;
			return (res);
		}
		res++;
	}
	if (ch == '\0' && *res == '\0')
		return (res);
	return (NULL);
}

