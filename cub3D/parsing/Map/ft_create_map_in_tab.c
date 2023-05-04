/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_map_in_tab.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ceatgie <ceatgie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 10:28:24 by ceatgie           #+#    #+#             */
/*   Updated: 2023/05/02 08:26:19 by ceatgie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3D.h"

static void	ft_create_map_in_tab_else(int i, int j, int c, t_parse *data)
{
	int	k;

	k = 0;
	while (i < ft_acces_map(data) + data->map_line)
	{
		while (data->file_info[i][j])
		{
			if (ft_is_no_printable(data->file_info[i][j]))
				data->map_tab[k][c] = '1';
			else
				data->map_tab[k][c] = data->file_info[i][j];
			c++;
			j++;
		}
		data->map_tab[k][c] = '\0';
		i++;
		k++;
		c = 0;
		j = 0;
	}
	data->map_tab[k] = NULL;
}

int	ft_create_map_in_tab(t_parse *data)
{
	int		i;
	int		j;

	j = 0;
	i = ft_acces_map(data);
	ft_replace_newline(data);
	ft_count_longest_line(data);
	data->map_tab = malloc(sizeof(char *) * (data->map_line + 1));
	if (!data->map_tab)
		return (ft_putstr_fd(RED_L, "Error\nMalloc broke in maptab\n", 2), -1);
	while (j < data->map_line)
	{
		data->map_tab[j] = malloc(sizeof(char) * (data->longest_line + 1));
		if (!data->map_tab[j])
			return (ft_putstr_fd(RED_L,
					"Error\nMalloc broke in maptab\n", 2), -1);
		j++;
	}
	data->map_tab[j] = NULL;
	j = 0;
	ft_create_map_in_tab_else(i, j, 0, data);
	ft_complete_map_tab(data);
	return (1);
}
