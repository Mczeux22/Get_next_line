/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loicpapon <loicpapon@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 18:21:58 by loicpapon         #+#    #+#             */
/*   Updated: 2024/11/18 14:00:13 by loicpapon        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_memory(char *buffer, char *buff)
{
	char	*temp;

	temp = ft_strjoin(buffer, buff);
	if (!temp)
	{
		free(buffer);
		return (NULL);
	}
	free(buffer);
	return (temp);
}

char	*ft_next_line(char *buffer)
{
	int		i;
	int		j;
	char	*tab;

	i = 0;
	j = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (!buffer[i])
	{
		free(buffer);
		return (NULL);
	}
	tab = ft_calloc(ft_strlen(buffer) - i, sizeof(char));
	if (!tab)
	{
		free(buffer);
		return (NULL);
	}
	i++;
	while (buffer[i])
		tab[j++] = buffer[i++];
	free (buffer);
	return (tab);
}

char	*ft_line(char *buffer)
{
	int		i;
	char	*tab;

	i = 0;
	if (!buffer || !buffer[i])
		return (NULL);
	while (buffer[i] && buffer[i] != '\n')
		i++;
	tab = ft_calloc(i + 2, sizeof(char));
	if (!tab)
		return (NULL);
	i = 0;
	while (buffer[i] && buffer[i] != '\n')
	{
		tab[i] = buffer[i];
		i++;
	}
	if (buffer[i] == '\n')
	{
		tab[i] = '\n';
		i++;
	}
	tab[i] = '\0';
	return (tab);
}

char	*ft_read_file(int fd, char *res)
{
	char	*buffer;
	int		i;

	if (!res)
		res = ft_calloc(1, 1);
	if (!res)
		return (NULL);
	buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!buffer)
	{
		free(res);
		return (NULL);
	}
	i = 1;
	while (i > 0)
	{
		i = read(fd, buffer, BUFFER_SIZE);
		if (i == -1)
		{
			free(buffer);
			free(res);
			return (NULL);
		}
		buffer[i] = '\0';
		res = ft_memory(res, buffer);
		if (!res)
		{
			free(buffer);
			return (NULL);
		}
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	free (buffer);
	return (res);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
	{
		if (buffer)
		{
			free (buffer);
			buffer = NULL;
		}
		return (NULL);
	}
	buffer = ft_read_file(fd, buffer);
	if (!buffer)
	{
		if (buffer)
		{
			free(buffer);
			buffer = NULL;
		}
		return (NULL);
	}
	line = ft_line(buffer);
	if (!line)
	{
		free(buffer);
		buffer = NULL;
		return (NULL);
	}
	buffer = ft_next_line(buffer);
	return (line);
}
