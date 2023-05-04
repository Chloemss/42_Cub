/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ceatgie <ceatgie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 13:54:13 by ceatgie           #+#    #+#             */
/*   Updated: 2023/05/02 14:12:01 by ceatgie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../cub3D.h"

double	getay(t_cub *cub, double angle)
{
	double	ay;

	if (angle >= 0 && angle <= 180)
		ay = floor((cub->y_player / (double)64)) * (double)64 - (double)0.001;
	else
		ay = floor((cub->y_player / (double)64)) * (double)64 + (double)64;
	return (ay);
}

double	getya(double angle, double ya)
{
	if (angle >= 0 && angle <= 180)
		ya = (double)-64;
	else
		ya = (double)64;
	return (ya);
}

double	getcx(double angle, double ax, double xa)
{
	double	cx;

	if (angle >= 0 && angle <= 180)
		cx = ax + xa;
	else
		cx = ax - xa;
	return (cx);
}

double	getcx2(double angle, double cx, double xa)
{
	if (angle >= 0 && angle <= 180)
		cx += xa;
	else
		cx -= xa;
	return (cx);
}
