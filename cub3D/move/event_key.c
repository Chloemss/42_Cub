/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_key.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ceatgie <ceatgie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 17:58:53 by bfiguet           #+#    #+#             */
/*   Updated: 2023/05/03 11:40:23 by ceatgie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"
#include <math.h>

static int	render_next_frame(t_cub *cub)
{
	display(cub);
	mlx_destroy_image(cub->mlx_ptr, cub->img);
	cub->img = NULL;
	return (1);
}

static int	main_loop(t_cub *cub)
{
	if (cub->key_left)
		pov_move(cub, -1);
	if (cub->key_right)
		pov_move(cub, 1);
	if (cub->key_w)
		x_y_move(cub, 3, 1);
	if (cub->key_d)
		x_y_move(cub, 3, 3);
	if (cub->key_s)
		x_y_move(cub, 3, 2);
	if (cub->key_a)
		x_y_move(cub, 3, 4);
	render_next_frame(cub);
	return (0);
}

void	event_hook(t_cub *cub)
{
	mlx_hook(cub->mlx_win, 2, 1L << 1, key_press, cub);
	mlx_hook(cub->mlx_win, 3, 1L << 0, key_release, cub);
	mlx_hook(cub->mlx_win, 17, 0, close_hook, cub);
	mlx_loop_hook(cub->mlx_ptr, main_loop, cub);
}

int	close_hook(t_cub *cub)
{
	mlx_clear_window(cub->mlx_ptr, cub->mlx_win);
	mlx_destroy_window(cub->mlx_ptr, cub->mlx_win);
	mlx_destroy_image(cub->mlx_ptr, cub->text[0]);
	mlx_destroy_image(cub->mlx_ptr, cub->text[1]);
	mlx_destroy_image(cub->mlx_ptr, cub->text[2]);
	mlx_destroy_image(cub->mlx_ptr, cub->text[3]);
	if (cub->img)
		mlx_destroy_image(cub->mlx_ptr, cub->img);
	mlx_destroy_display(cub->mlx_ptr);
	ft_free(cub->map);
	free(cub->mlx_ptr);
	ft_free(cub->texture_tab);
	exit (0);
}
