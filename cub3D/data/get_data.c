/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_data.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ceatgie <ceatgie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 13:21:58 by ceatgie           #+#    #+#             */
/*   Updated: 2023/05/02 13:22:08 by ceatgie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

void	x_and_y_map(t_cub *cub)
{
	int	x;

	x = 0;
	cub->map_x = ft_strlen(cub->map[x]);
	cub->xscreen = cub->map_x * 64;
	while (cub->map[x] != NULL)
		x++;
	cub->map_y = x;
	cub->yscreen = cub->map_y * 64;
}
