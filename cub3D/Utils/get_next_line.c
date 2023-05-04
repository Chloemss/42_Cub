/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmassavi <cmassavi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 10:58:33 by ceatgie           #+#    #+#             */
/*   Updated: 2023/05/02 16:18:16 by cmassavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../get_next_line.h"
#include <unistd.h>

char	*ft_read_to_backup_str(int fd, char *backup_str)
{
	int		red;
	char	*buffer;

	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	red = 1;
	while (!ft_strchr(backup_str, '\n') && red != 0)
	{
		red = read(fd, buffer, BUFFER_SIZE);
		if (red == -1)
			return (free(buffer), free(backup_str), NULL);
		buffer[red] = '\0';
		backup_str = ft_strjoin(backup_str, buffer);
		if (backup_str == NULL)
		{
			free(backup_str);
			break ;
		}
	}
	free(buffer);
	return (backup_str);
}

char	*ft_get_line(char *backup_str)
{
	int		i;
	char	*line;

	i = 0;
	if (!backup_str[i])
		return (NULL);
	while (backup_str[i] && backup_str[i] != '\n')
		i++;
	line = (char *)malloc(sizeof(char) * (i + 2));
	if (!line)
		return (NULL);
	i = 0;
	while (backup_str[i] && backup_str[i] != '\n')
	{
		line[i] = backup_str[i];
		i++;
	}
	if (backup_str[i] == '\n')
	{
		line[i] = backup_str[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*ft_new_backup_str(char *backup_str)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	while (backup_str[i] && backup_str[i] != '\n')
		i++;
	if (!backup_str[i])
	{
		free(backup_str);
		return (NULL);
	}
	str = (char *)ft_calloc(ft_strlen(backup_str) - i + 1, sizeof(char));
	if (!str)
		return (NULL);
	i++;
	j = 0;
	while (backup_str[i])
		str[j++] = backup_str[i++];
	str[j] = '\0';
	free(backup_str);
	return (str);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*backup_str;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	backup_str = ft_read_to_backup_str(fd, backup_str);
	if (!backup_str)
		return (NULL);
	line = ft_get_line(backup_str);
	backup_str = ft_new_backup_str(backup_str);
	return (line);
}
