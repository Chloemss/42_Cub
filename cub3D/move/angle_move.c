/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   angle_move.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ceatgie <ceatgie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 13:43:56 by ceatgie           #+#    #+#             */
/*   Updated: 2023/05/03 13:09:38 by ceatgie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"
#include <math.h>

/*
	Les fonctions opposite angle permetttent de trouver
	le bonne angle de deplacement WASD
*/
double	opposite_angle_back(double angle)
{
	double	res_angle;

	res_angle = 0;
	if ((angle + 180) > 360)
		res_angle = angle - 180;
	else
		res_angle += angle + 180;
	return (res_angle);
}

double	opposite_angle_right(double angle)
{
	double	res_angle;
	double	tmp;

	res_angle = 0;
	if (angle - 90 < 0)
	{
		tmp = fabs(angle - 90);
		res_angle = 360 - tmp;
	}
	else
		res_angle = angle - 90;
	return (res_angle);
}

double	opposite_angle_left(double angle)
{
	double	res_angle;
	double	tmp;

	res_angle = 0;
	if (angle + 90 > 360)
	{
		tmp = angle + 90;
		res_angle = tmp - 360;
	}
	else
		res_angle = angle + 90;
	return (res_angle);
}

double	find_angle(double angle, int which)
{
	if (which == 1)
		return (angle);
	else if (which == 2)
		return (opposite_angle_back(angle));
	else if (which == 3)
		return (opposite_angle_left(angle));
	else if (which == 4)
		return (opposite_angle_right(angle));
	return (0);
}

/*
	Fonction qui permet de pas avoir un fov
	negative ou > a 360
*/
double	correct_angle(double angle)
{
	double	ret_angle;

	if (angle < 0)
	{
		ret_angle = 360 + angle;
		return (ret_angle);
	}
	else if (angle > 360)
	{
		ret_angle = angle - 360;
		return (ret_angle);
	}
	else
		return (angle);
}
