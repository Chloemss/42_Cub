/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ceatgie <ceatgie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 13:38:39 by cmassavi          #+#    #+#             */
/*   Updated: 2023/05/03 13:09:57 by ceatgie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"
#include <math.h>

void	pov_move(t_cub *cub, double x)
{
	double	mod;
	double	tmp;
	double	trois;

	mod = cub->pov;
	trois = 360;
	if ((cub->pov + x) < 0)
	{
		tmp = mod + x;
		tmp = fabs(tmp);
		tmp = 360 - tmp;
		cub->pov = tmp;
	}
	else if ((cub->pov + x) > 360)
	{
		mod += x;
		mod -= trois;
		cub->pov = mod;
	}
	else
		cub->pov += x;
}

void	x_y_move(t_cub *cub, double length, int which)
{
	double	angle;
	double	x_end;
	double	y_end;
	double	x_end_check;
	double	y_end_check;

	angle = find_angle(cub->pov, which) * M_PI / 180;
	x_end_check = cub->x_player + (length + 32) * cos(angle);
	y_end_check = cub->y_player - (length + 32) * sin(angle);
	x_end = cub->x_player + length * cos(angle);
	y_end = cub->y_player - length * sin(angle);
	if (cub->map[(int)(y_end_check / 64)][(int)(x_end_check / 64)] != '1'
		&& cub->map[(int)(y_end / 64)][(int)(x_end / 64)] != '1')
	{
		cub->x_player = x_end;
		cub->y_player = y_end;
	}
}
