/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_if_player.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ceatgie <ceatgie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 12:32:12 by ceatgie           #+#    #+#             */
/*   Updated: 2023/05/02 17:15:18 by ceatgie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3D.h"

//	===================================================================
//								Commentary
//							   ------------
//	
//	- Take as parameters: pointer to parse struct
//	
//	- Puts each position presence check return in an array and checks
//		if there is only 1 type of position
//	
//	- Check if there are duplicates of this position
//	
//	- Return 0 if check has failed
//	
//	===================================================================

static bool	ft_check_if_player_else(int cpt, t_parse *data, t_cub *cub)
{
	if (cpt == 0)
		return (ft_putstr_fd(RED_L,
				"Error\nThere is no start position !\n", 2), 0);
	else if (cpt > 1)
		return (ft_putstr_fd(RED_L,
				"Error\nThere is more than 1 start position !\n", 2), 0);
	else if (!ft_is_multiple_e(data, cub) || !ft_is_multiple_n(data, cub)
		|| !ft_is_multiple_s(data, cub) || !ft_is_multiple_w(data, cub))
		return (1);
	return (ft_putstr_fd(RED_L,
			"Error\nThere is multiple same start positions !\n", 2), 0);
}

bool	ft_check_if_player(t_parse *data, t_cub *cub)
{
	int	tab[4];
	int	cpt;
	int	i;

	i = 0;
	cpt = 0;
	tab[0] = ft_is_no_e(data, cub);
	tab[1] = ft_is_no_n(data, cub);
	tab[2] = ft_is_no_s(data, cub);
	tab[3] = ft_is_no_w(data, cub);
	while (i < 4)
	{
		if (tab[i] == 0)
			cpt++;
		i++;
	}
	if (!ft_check_if_player_else(cpt, data, cub))
		return (0);
	return (1);
}
