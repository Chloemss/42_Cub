/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_wall.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ceatgie <ceatgie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 13:25:04 by ceatgie           #+#    #+#             */
/*   Updated: 2023/05/02 08:13:56 by ceatgie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3D.h"

//	===================================================================
//								Commentary
//							   ------------
//	
//	Check if there are only '1's in the first and last line of the map
//	
//	- Check if the other lines start with '1' and end with '1'
//	
//	- Return 1 if the map isn't surrounded by wall
//	
//	- Return 0 if the map is surrounded by wall 
//	
//	===================================================================

bool	ft_check_wall(t_parse *data)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	while (data->map_tab[i])
		i++;
	while (j < data->longest_line)
	{
		if (data->map_tab[0][j] != '1' || data->map_tab[i - 1][j] != '1')
			return (ft_putstr_fd(RED_L,
					"Error\nMap is not surronded by wall\n", 2), 1);
		j++;
	}
	i = 0;
	while (data->map_tab[i])
	{
		if (data->map_tab[i][0] != '1' ||
			data->map_tab[i][data->longest_line - 1] != '1')
			return (ft_putstr_fd(RED_L,
					"Error\nMap is not surronded by wall\n", 2), 1);
		i++;
	}
	return (0);
}
