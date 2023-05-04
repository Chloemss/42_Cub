/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   useful.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmassavi <cmassavi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 14:15:48 by cmassavi          #+#    #+#             */
/*   Updated: 2023/05/02 16:09:14 by cmassavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"
#include <mlx.h>
#include <math.h>

void	dist_map(t_cub *cub)
{
	double	resdist;
	double	deux;
	double	centq;
	double	trente;

	deux = 2;
	centq = 180;
	trente = 30;
	resdist = (cub->xscreen / deux) / tan(trente * (M_PI / centq));
	cub -> dist = resdist;
}

double	find_dist_x(int x, int x2, double angle)
{
	double	dist;

	dist = abs(x - x2) / cos(angle * (M_PI / 180));
	return (dist);
}
