/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ceatgie <ceatgie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 14:15:50 by cmassavi          #+#    #+#             */
/*   Updated: 2023/05/03 13:13:54 by ceatgie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3D.h"
#include <mlx.h>
#include <math.h>

/*
	Retourne les coordonnees de la collision de la plus proche
*/
t_coord	inter_co(t_cub *cub, double angle, int compteur)
{
	t_coord	coorda;
	t_coord	coordb;
	double	dista;
	double	distb;

	(void)compteur;
	angle = correct_angle(angle);
	coorda = inter_hor(cub, angle);
	dista = sqrt(pow(cub->x_player - coorda.x, (double)2)
			+ pow(cub->y_player - coorda.y, (double)2));
	coordb = inter_ver(cub, angle);
	distb = sqrt(pow(cub->x_player - coordb.x, (double)2)
			+ pow(cub->y_player - coordb.y, (double)2));
	if (coorda.x < 0 || coorda.y < 0)
		return (coordb);
	if (coordb.x < 0 || coordb.y < 0)
		return (coorda);
	if (dista < distb)
		return (coorda);
	else
		return (coordb);
}

/*
	Retourne la distance de la collision la plus proche
*/
double	inter(t_cub *cub, double angle)
{
	t_coord	coorda;
	t_coord	coordb;
	double	dista;
	double	distb;

	angle = correct_angle(angle);
	coorda = inter_hor(cub, angle);
	dista = sqrt(pow(cub->x_player - coorda.x, (double)2)
			+ pow(cub->y_player - coorda.y, (double)2));
	coordb = inter_ver(cub, angle);
	distb = sqrt(pow(cub->x_player - coordb.x, 2)
			+ pow(cub->y_player - coordb.y, 2));
	if (coorda.x < 0 || coorda.y < 0)
		return (distb);
	if (coordb.x < 0 || coordb.y < 0)
		return (dista);
	if (dista < distb)
		return (dista);
	else
		return (distb);
}
