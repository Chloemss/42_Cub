/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_access_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hook <hook@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 11:19:44 by hook              #+#    #+#             */
/*   Updated: 2023/04/29 11:19:59 by hook             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

int	ft_acces_map(t_parse *data)
{
	int	i;
	int	cpt;

	i = 0;
	cpt = 0;
	while (cpt < 6 && data->file_info[i])
	{
		if (ft_check_if_char(data->file_info[i]))
			cpt++;
		i++;
	}
	while (data->file_info[i])
	{
		if (!ft_check_if_char(data->file_info[i]))
			i++;
		else
			return (i);
	}
	return (i);
}
