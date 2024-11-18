/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loicpapon <loicpapon@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 18:21:55 by loicpapon         #+#    #+#             */
/*   Updated: 2024/11/18 13:06:28 by loicpapon        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin(char const *str, char const *str2)
{
	int		i;
	int		j;
	char	*nstr;

	i = 0;
	nstr = (char *)malloc(ft_strlen(str) + ft_strlen(str2) + 1);
	if (nstr == 0)
		return (0);
	while (str[i])
	{
		nstr[i] = str[i];
		i++;
	}
	j = 0;
	while (str2[j])
	{
		nstr[i] = str2[j];
		j++;
		i++;
	}
	nstr[i] = '\0';
	return (nstr);
}

char	*ft_strchr(const char *str, int search)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if ((unsigned char)str[i] == (unsigned char)search)
			return (&((char *)str)[i]);
		i++;
	}
	if ((unsigned char)str[i] == (unsigned char)search)
		return (&((char *)str)[i]);
	return (NULL);
}

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	ft_bzero(void *s, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		((unsigned char *)s)[i] = 0;
		i++;
	}
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;

	ptr = (void *)malloc(count * size);
	if (ptr == NULL)
		return (NULL);
	ft_bzero(ptr, count);
	return (ptr);
}
