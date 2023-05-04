/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmassavi <cmassavi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 15:11:15 by cmassavi          #+#    #+#             */
/*   Updated: 2023/05/02 15:11:16 by cmassavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../cub3D.h"
#include <mlx.h>
#include <math.h>

double	getxa2(double angle)
{
	double	xa2;

	if (angle > 90 && angle < 270)
		xa2 = (double)-64;
	else
		xa2 = (double)64;
	return (xa2);
}

double	getya2(double angle)
{
	double	ya2;

	ya2 = (double)64 * tan(angle * (M_PI / (double)180));
	return (ya2);
}
