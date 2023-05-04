/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ceatgie <ceatgie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 11:14:04 by cmassavi          #+#    #+#             */
/*   Updated: 2023/05/03 13:11:59 by ceatgie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"
#include <mlx.h>
#include <math.h>

int	main(int ac, char **av, char **env)
{
	t_cub	cub;
	t_parse	data;

	(void)ac;
	ft_check_cub(ac, av);
	ft_init_struct(ac, av, &data);
	ft_parsing_manager(&data, &cub, env);
	ft_free(data.file_info);
	init_s_cub(&cub, &data);
	x_and_y_map(&cub);
	init_mlx(&cub);
	loadtexture(&cub);
	event_hook(&cub);
	mlx_loop(cub.mlx_ptr);
	return (ft_free(data.file_info), 0);
}
