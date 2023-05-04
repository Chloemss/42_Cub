/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmassavi <cmassavi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 13:44:57 by ceatgie           #+#    #+#             */
/*   Updated: 2023/05/02 15:06:11 by cmassavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

int	key_press(int key, t_cub *cub)
{
	if (key == ESC)
		close_hook(cub);
	if (key == LEFT)
		cub->key_left = 1;
	if (key == RIGHT)
		cub->key_right = 1;
	if (key == W)
		cub->key_w = 1;
	if (key == D)
		cub->key_d = 1;
	if (key == S)
		cub->key_s = 1;
	if (key == A)
		cub->key_a = 1;
	return (0);
}

int	key_release(int key, t_cub *cub)
{
	if (key == LEFT)
		cub->key_left = 0;
	if (key == RIGHT)
		cub->key_right = 0;
	if (key == W)
		cub->key_w = 0;
	if (key == D)
		cub->key_d = 0;
	if (key == S)
		cub->key_s = 0;
	if (key == A)
		cub->key_a = 0;
	return (0);
}
