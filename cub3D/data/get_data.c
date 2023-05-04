/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_data.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: massavie <massavie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 13:21:58 by ceatgie           #+#    #+#             */
/*   Updated: 2023/05/04 17:58:04 by massavie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

void	x_and_y_map(t_cub *cub)
{
	int	x;

	x = 0;
	cub->map_x = ft_strlen(cub->map[x]);
	cub->xscreen = 720;
	while (cub->map[x] != NULL)
		x++;
	cub->map_y = x;
	cub->yscreen = 1024;
}
