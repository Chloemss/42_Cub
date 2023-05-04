/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_if_forbidden_char.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hook <hook@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 13:37:45 by ceatgie           #+#    #+#             */
/*   Updated: 2023/04/28 16:47:39 by hook             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3D.h"

//	===================================================================
//								Commentary
//							   ------------
//	
//	- Take as parameters: pointer to parse struct
//	
//	- Check if there are not forbidden char in the map
//	
//	- Return 1 if there are forbidden char
//
//	- Return 0 if there are not forbidden char
//	
//	===================================================================

bool	ft_check_if_forbidden_char(t_parse *data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (data->map_tab[i])
	{
		while (data->map_tab[i][j])
		{
			if (!(data->map_tab[i][j] == '1' || data->map_tab[i][j] == '0'
				|| data->map_tab[i][j] == 'S' || data->map_tab[i][j] == 'W'
				|| data->map_tab[i][j] == 'E' || data->map_tab[i][j] == 'N'))
				return (ft_putstr_fd(RED_L,
						"Error\nForbidden char in map detected\n", 2), 1);
			j++;
		}
		i++;
		j = 0;
	}
	return (0);
}
