/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing_manager.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ceatgie <ceatgie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 13:49:39 by ceatgie           #+#    #+#             */
/*   Updated: 2023/05/03 13:24:50 by ceatgie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

static void	ft_parsing_manager_else(t_parse *data, t_cub *cub)
{
	if (!ft_check_if_player(data, cub))
	{
		ft_free(data->map_tab);
		ft_free(data->file_info);
		exit(-1);
	}
	if (ft_check_wall(data))
	{
		ft_free(data->map_tab);
		ft_free(data->file_info);
		exit(-1);
	}
}

void	ft_parsing_manager(t_parse *data, t_cub *cub,
	char **env)
{
	if (ft_get_file_info(data) == -1)
	{
		ft_free(data->file_info);
		exit(-1);
	}
	if (ft_check_if_wrong_map_arg(data, cub, env) == -1)
	{
		ft_free(data->file_info);
		exit(-1);
	}
	if (ft_create_map_in_tab(data) == -1)
	{
		ft_free(data->map_tab);
		ft_free(data->file_info);
		exit(-1);
	}
	if (ft_check_if_forbidden_char(data))
	{
		ft_free(data->map_tab);
		ft_free(data->file_info);
		exit(-1);
	}
	ft_parsing_manager_else(data, cub);
}
