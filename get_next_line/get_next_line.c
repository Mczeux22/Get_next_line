/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loicpapon <loicpapon@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 18:21:58 by loicpapon         #+#    #+#             */
/*   Updated: 2024/11/17 22:11:46 by loicpapon        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_memory(char *buffer, char *buff)
{
	char	*temp;

	temp = ft_strjoin(buffer, buff);
	free (buffer);
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
		free (buffer);
		return (NULL);
	}
	tab = ft_calloc((ft_strlen(buffer) - i + 1), sizeof(char));
	i += 1;
	while (buffer[i])
	{
		tab[j] = buffer[i];
		i++;
		j++;
	}
	free (buffer);
	return (tab);
}

char	*ft_line(char *buffer)
{
	int		i;
	char	*tab;

	i = 0;
	if (!buffer[i])
		return (NULL);
	while (buffer[i] && buffer[i] != '\n')
		i++;
	tab = ft_calloc(i + 2, sizeof(char));
	i = 0;
	while (buffer[i] && buffer[i] != '\n')
	{
		tab[i] = buffer[i];
		i++;
	}
	if (buffer[i] == '\n' && buffer[i] == '\0')
		tab[i + 1] = '\n';
	return (tab);
}

char	*ft_read_file(int fd, char *res)
{
	char	*buffer;
	int		i;

	if (res == NULL)
		res = ft_calloc(1, 1);
	buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (buffer == NULL)
		return (NULL);
	i = 1;
	while (i > 0)
	{
		i = read(fd, buffer, BUFFER_SIZE);
		if (i == -1)
		{
			free (buffer);
			return (NULL);
		}
		buffer[i] = 0;
		res = ft_memory(res, buffer);
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
		return (NULL);
	buffer = ft_read_file(fd, buffer);
	if (buffer == 0)
		return (NULL);
	line = ft_line(buffer);
	buffer = ft_line(buffer);
	return (line);
}
