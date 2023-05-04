/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ceatgie <ceatgie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 10:09:01 by ceatgie           #+#    #+#             */
/*   Updated: 2023/05/03 11:25:21 by ceatgie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

void	init_s_cub(t_cub *cub, t_parse *data)
{
	int	i;

	i = -1;
	cub -> texture_f = NULL;
	cub -> texture_c = NULL;
	cub -> key_left = 0;
	cub -> key_right = 0;
	cub -> key_w = 0;
	cub -> key_a = 0;
	cub -> key_s = 0;
	cub -> key_d = 0;
	cub -> map = malloc(sizeof(char *) * (data->map_line + 1));
	while (++i < data->map_line)
		cub->map[i] = ft_strdup(data->map_tab[i]);
	cub->map[i] = NULL;
	ft_free(data->map_tab);
}

void	init_mlx(t_cub *cub)
{
	cub -> mlx_ptr = mlx_init();
	cub -> mlx_win = mlx_new_window(cub->mlx_ptr,
			cub->xscreen, cub->yscreen, "CUB3D");
}
