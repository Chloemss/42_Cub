/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ceatgie <ceatgie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 16:14:06 by cmassavi          #+#    #+#             */
/*   Updated: 2023/05/03 12:15:28 by ceatgie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"
#include "mlx.h"
#include <math.h>

void	display(t_cub *cub)
{
	cub->img = NULL;
	if (cub->img)
		mlx_destroy_image(cub->mlx_ptr, cub->img);
	cub->img = mlx_new_image(cub->mlx_ptr, cub->xscreen, cub->yscreen);
	cub->pxl = mlx_get_data_addr(cub->img, &(cub->bpp),
			&(cub->size_line), &(cub->endian));
	draw_line_at_angle(cub);
	mlx_put_image_to_window(cub->mlx_ptr, cub->mlx_win, cub->img, 0, 0);
}
