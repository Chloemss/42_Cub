/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   horizontal.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ceatgie <ceatgie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 13:55:25 by cmassavi          #+#    #+#             */
/*   Updated: 2023/05/03 13:13:10 by ceatgie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../cub3D.h"
#include <mlx.h>
#include <math.h>

t_coord	setcoor(double x, double y)
{
	t_coord	coord;

	coord.x = x;
	coord.y = y;
	return (coord);
}

static t_coord	inter_hor_else(t_cub *cub, double angle, t_coord coord)
{
	double	xa;
	double	ya;

	ya = getya(angle, 0);
	coord.y = coord.y + ya;
	xa = (double)64 / tan(angle * (M_PI / (double)180));
	coord.x = getcx(angle, coord.x, xa);
	if (coord.x <= (double)0 || coord.x >= cub->xscreen || coord.y <= (double)0
		|| coord.y >= cub->yscreen
		|| find_wall(cub, coord.x, coord.y) == (double)1)
		return (coord);
	while (((coord.x >= (double)0 && coord.x <= cub->xscreen)
			&& (coord.y >= (double)0 || coord.y <= cub->yscreen))
		&& find_wall(cub, coord.x, coord.y) != (double)1)
		coord = setcoor(getcx2(angle, coord.x, xa), coord.y + ya);
	return (coord);
}

t_coord	inter_hor(t_cub *cub, double angle)
{
	t_coord	coord;

	coord.y = getay(cub, angle);
	coord.x = cub->x_player + (cub->y_player - coord.y)
		/ tan(angle * (M_PI / (double)180));
	if (coord.x < (double)0 || coord.x > cub->xscreen
		|| coord.y < (double)0 || coord.y > cub->yscreen)
		return (setcoor((double)-1, (double)-1));
	if (coord.x <= (double)0 || coord.x >= cub->xscreen
		|| coord.y <= (double)0
		|| coord.y >= cub->yscreen
		|| find_wall(cub, coord.x, coord.y) == (double)1)
		return (coord);
	coord = inter_hor_else(cub, angle, coord);
	return (coord);
}
