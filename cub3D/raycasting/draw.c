/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ceatgie <ceatgie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 17:48:19 by cmassavi          #+#    #+#             */
/*   Updated: 2023/05/03 13:27:26 by ceatgie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include <math.h>
#include "../cub3D.h"

/*
	Chloe : modified
	Remplacer draw line avec un point de position juste
*/

int	put_pxl(t_cub *sl, int x, int y, unsigned int c)
{
	char		*dest;

	dest = sl->pxl + sl->size_line * y + x * (sl->bpp / 8);
	*(unsigned int *)dest = c;
	return (0);
}

void	print_column(t_cub *cub, double lenght, double x, float coendx)
{
	double	scale;
	double	i;
	int		image_y;
	int		color;
	double	since;

	since = (cub -> yscreen / (double) 2) - (lenght / (double)2);
	scale = lenght / (double)cub->heighttext[cub->actualtext];
	i = -1;
	while (++i < since)
		put_pxl(cub, x, i, cub->color_c);
	i = -1;
	while (++i < lenght)
	{
		image_y = i / scale;
		color = get_pixel_color(cub, fmod(coendx, 64), image_y);
		if (x <= cub->xscreen && x >= 0 && since <= cub->yscreen && since >= 0)
			put_pxl(cub, x, since, color);
		since++;
	}
	while (since < cub-> yscreen)
	{
		put_pxl(cub, x, since, cub->color_f);
		since++;
	}
}
