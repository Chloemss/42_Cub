/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_no_s.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ceatgie <ceatgie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 12:22:34 by ceatgie           #+#    #+#             */
/*   Updated: 2023/05/02 18:02:20 by ceatgie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3D.h"

//	===================================================================
//								Commentary
//							   ------------
//	
//	- Take as parameters: pointer to parse struct
//	
//	- Check if there is no s in the map
//	
//	- Return 1 if there is no s
//	
//	- Return 0 if there is s
//	
//	===================================================================

bool	ft_is_no_s(t_parse *data, t_cub *cub)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (data->map_tab[i])
	{
		while (data->map_tab[i][j])
		{
			if (data->map_tab[i][j] == 'S')
			{
				cub->x_player = (double)j * (double)64 + (double) 32;
				cub->y_player = (double)i * (double)64 + (double) 32;
				cub->pov = 270;
				return (0);
			}
			j++;
		}
		i++;
		j = 0;
	}
	return (1);
}
