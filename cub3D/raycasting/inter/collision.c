/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collision.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmassavi <cmassavi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 15:12:34 by cmassavi          #+#    #+#             */
/*   Updated: 2023/05/02 15:13:04 by cmassavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3D.h"
#include <mlx.h>
#include <math.h>

/*
	Fonction pour verifier si il y a un mur
	aux coordonnees x et y donnees
*/
int	find_wall(t_cub *cub, double x, double y)
{
	int	y_check;
	int	x_check;

	y_check = (int) y / 64;
	x_check = (int) x / 64;
	if (!cub->map)
		return (1);
	if (y_check >= cub->map_y || x_check >= cub->map_x)
		return (1);
	if (!cub->map[(int)(y / 64)][(int)(x / 64)])
		return (1);
	if (cub->map[(int)(y / 64)][(int)(x / 64)] == '1')
		return (1);
	else
		return (0);
}
