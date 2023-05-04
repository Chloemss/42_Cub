/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_complete_map_tab.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ceatgie <ceatgie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 11:21:54 by hook              #+#    #+#             */
/*   Updated: 2023/05/02 08:26:39 by ceatgie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

void	ft_complete_map_tab(t_parse *data)
{
	int	i;
	int	j;
	int	k;
	int	size;

	size = data->longest_line;
	i = -1;
	j = -1;
	while (data->map_tab[++i])
	{
		while (++j < size)
		{
			if (data->map_tab[i][j] == '\0')
			{
				k = j - 1;
				while (++k < size)
					data->map_tab[i][k] = ' ';
			}
			if (ft_is_no_printable(data->map_tab[i][j]))
				data->map_tab[i][j] = '1';
		}
		data->map_tab[i][j] = '\0';
		j = -1;
	}
}
