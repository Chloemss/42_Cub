/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_multiple_w.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ceatgie <ceatgie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 12:40:47 by ceatgie           #+#    #+#             */
/*   Updated: 2023/05/02 17:14:21 by ceatgie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3D.h"

//	===================================================================
//								Commentary
//							   ------------
//	
//	- Take as parameters: pointer to parse struct
//
//	- Check if there is w in the map
//	
//	- Then check if there is multiple w in the map
//	
//	- Return -1 if there is no w in the map
//	
//	- Return 1 if there is multiple w in the map
//	
//	- Return 0 if there is no multiple w in the map
//	
//	===================================================================

int	ft_is_multiple_w(t_parse *data, t_cub *cub)
{
	int	i;
	int	j;
	int	cpt;

	if (ft_is_no_w(data, cub))
		return (-1);
	i = 0;
	j = 0;
	cpt = 0;
	while (data->map_tab[i])
	{
		while (data->map_tab[i][j])
		{
			if (data->map_tab[i][j] == 'W')
				cpt++;
			j++;
		}
		j = 0;
		i++;
	}
	if (cpt > 1)
		return (1);
	else
		return (0);
}
