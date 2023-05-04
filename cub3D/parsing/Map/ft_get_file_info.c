/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_file_info.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ceatgie <ceatgie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 12:11:03 by hook              #+#    #+#             */
/*   Updated: 2023/05/02 08:00:05 by ceatgie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3D.h"

int	ft_get_file_info(t_parse *data)
{
	int		i;
	int		fd;

	i = 0;
	data->file_info = malloc(sizeof(char *) * (data->line + 2));
	if (!data->file_info)
		return (ft_putstr_fd(RED_L, "Error\nMalloc of tab_map broke\n", 2), -1);
	fd = open(data->argv[1], O_RDONLY);
	i = 0;
	while (i < data->line)
	{
		data->file_info[i] = get_next_line(fd);
		if (!data->file_info[i])
			return (ft_putstr_fd(RED_L,
					"Error\nMalloc of tab_map using gnl broke\n", 2), -1);
		i++;
	}
	data->file_info[i] = NULL;
	close(fd);
	return (1);
}
