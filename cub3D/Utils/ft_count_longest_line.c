/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_longest_line.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ceatgie <ceatgie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 13:39:34 by hook              #+#    #+#             */
/*   Updated: 2023/05/02 08:17:12 by ceatgie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

void	ft_count_longest_line(t_parse *data)
{
	int	value1;
	int	value2;
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
	while (!ft_check_if_char(data->file_info[i]))
		i++;
	value1 = ft_strlen(data->file_info[i]);
	while (data->file_info[i])
	{
		value2 = ft_strlen(data->file_info[i]);
		if (value2 > value1)
			value1 = value2;
		i++;
		data->map_line++;
	}
	data->longest_line = value1;
}
