/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loicpapon <loicpapon@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 18:21:58 by loicpapon         #+#    #+#             */
/*   Updated: 2024/11/17 09:33:27 by loicpapon        ###   ########.fr       */
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

	i = 1;
	res = ft_calloc(1, 1);
	buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	
}
char	*get_next_line(int fd)
{
	int	i;

	i = 0;
}
