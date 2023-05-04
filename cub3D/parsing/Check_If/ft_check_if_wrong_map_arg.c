/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_if_wrong_map_arg.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ceatgie <ceatgie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 15:54:12 by hook              #+#    #+#             */
/*   Updated: 2023/05/03 12:36:24 by ceatgie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3D.h"

int	ft_convert_to_hex(char *buf)
{
	int		hex_value;
	char	c;
	int		digit;
	int		i;

	i = 0;
	digit = 0;
	hex_value = 0;
	while (buf[i])
	{
		c = buf[i];
		if (c >= '0' && c <= '9')
			digit = c - '0';
		else if (c >= 'A' && c <= 'F')
			digit = (c - 'A') + 10;
		else
			return (-1);
		hex_value += digit * pow(16, ft_strlen(buf) - i - 1);
		i++;
	}
	return (hex_value);
}

static int	ft_check_if_wrong_map_arg_else(char **buffer, t_parse *data,
	t_cub *cub, char **env)
{
	if (!ft_check_if_good_start(buffer))
		return (ft_free(buffer), -1);
	if (!ft_check_texture_format(buffer))
		return (ft_free(buffer), -1);
	if (!ft_check_if_good_path(buffer))
		return (ft_free(buffer), -1);
	if (!ft_check_if_can_acces(buffer, env, cub))
		return (ft_free(buffer), -1);
	if (!ft_check_if_good_color_format(buffer))
		return (ft_free(buffer), -1);
	if (!ft_check_if_good_color_range(buffer))
		return (ft_free(buffer), -1);
	ft_get_color(buffer, data);
	cub->color_f = data->color_f;
	cub->color_c = data->color_c;
	return (1);
}

static void	ft_delete_newline_in_buffer(char **buffer)
{
	int	cpt;
	int	i;

	cpt = 0;
	i = 0;
	while (cpt < 4)
	{
		while (buffer[cpt][i])
		{
			if (buffer[cpt][i] == '\n')
				buffer[cpt][i] = '\0';
			i++;
		}
		i = 0;
		cpt++;
	}
}

int	ft_check_if_wrong_map_arg(t_parse *data, t_cub *cub, char **env)
{
	char	**buffer;
	int		i;
	int		cpt;

	i = -1;
	cpt = 0;
	buffer = malloc(sizeof(char *) * 7);
	if (!buffer)
		return (ft_putstr_fd(RED_L, "Error\nMalloc issue", 2), -1);
	while (cpt < 6 && data->file_info[++i])
	{
		if (ft_check_if_char(data->file_info[i]))
		{
			buffer[cpt] = ft_strdup(data->file_info[i]);
			buffer[cpt][ft_strlen(buffer[cpt])] = '\0';
			if (!buffer[cpt])
				return (ft_putstr_fd(RED_L, "Error\nMalloc issue", 2), -1);
			cpt++;
		}
	}
	buffer[cpt] = NULL;
	ft_delete_newline_in_buffer(buffer);
	if (ft_check_if_wrong_map_arg_else(buffer, data, cub, env) == -1)
		return (-1);
	return (ft_free(buffer), 1);
}
