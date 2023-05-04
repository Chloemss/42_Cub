/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vertical.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmassavi <cmassavi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 13:55:23 by cmassavi          #+#    #+#             */
/*   Updated: 2023/05/02 16:10:41 by cmassavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../cub3D.h"
#include <mlx.h>
#include <math.h>

t_coord	first_ver(t_cub *cub, double angle)
{
	t_coord	coord;

	if (angle > 90 && angle < 270)
		coord.x = floor((cub->x_player / (double)64))
			* (double)64 - (double)0.001;
	else
		coord.x = floor((cub->x_player / (double)64))
			* (double)64 + (double)64;
	coord.y = cub->y_player + (cub->x_player - coord.x)
		* tan(angle * (M_PI / (double)180));
	return (coord);
}

double	second_ver(double angle, double ay, double ya2)
{
	if (angle > 90 && angle < 270)
		ay = ay + ya2;
	else
		ay = ay - ya2;
	return (ay);
}

t_coord	last_ver(double angle, t_coord coord, double xa2, double ya2)
{
	if (angle > 90 && angle < 270)
		coord.y += ya2;
	else
		coord.y -= ya2;
	coord.x += xa2;
	return (coord);
}

t_coord	middle_inter_ver(double angle, double xa2, t_coord coord, double ya2)
{
	xa2 = getxa2(angle);
	coord.x = coord.x + xa2;
	ya2 = (double)64 * tan(angle * (M_PI / (double)180));
	coord.y = second_ver(angle, coord.y, ya2);
	return (coord);
}

t_coord	inter_ver(t_cub *cub, double angle)
{
	double	xa2;
	double	ya2;
	t_coord	coord;

	coord = first_ver(cub, angle);
	if (coord.x < 0 || coord.x > cub->xscreen || coord.y < (double)0
		|| coord.y > cub->yscreen)
		return (setcoor(-1, -1));
	if (((coord.x <= (double)0 && coord.x >= cub->xscreen)
			&& (coord.y <= (double)0 && coord.y >= cub->yscreen))
		|| (((coord.x >= (double)0 && coord.x <= cub->xscreen)
				&& (coord.y >= (double)0 && coord.y <= cub->yscreen))
			&& find_wall(cub, coord.x, coord.y) == (double)1))
		return (coord);
	coord = middle_inter_ver(angle, xa2, coord, ya2);
	if (coord.x <= (double)0 || coord.x >= cub->xscreen
		|| coord.y <= (double)0 || coord.y >= cub->yscreen
		|| find_wall(cub, coord.x, coord.y) == (double)1)
		return (coord);
	while (((coord.x >= (double)0 && coord.x <= cub->xscreen)
			&& (coord.y >= (double)0 && coord.y <= cub->yscreen))
		&& find_wall(cub, coord.x, coord.y) != (double)1)
		coord = last_ver(angle, coord, getxa2(angle), getya2(angle));
	return (coord);
}
