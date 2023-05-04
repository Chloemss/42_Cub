/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_color.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ceatgie <ceatgie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 17:55:52 by ceatgie           #+#    #+#             */
/*   Updated: 2023/05/02 18:37:41 by ceatgie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

int	ft_get_color(char **buffer, t_parse *data)
{
	char	**color_f;
	char	**color_c;

	color_f = ft_split((char *)(buffer[4] + 2), ',');
	if (!color_f)
		return (ft_putstr_fd(RED_L,
				"Error\nMalloc broke convert_color\n", 2), -1);
	color_c = ft_split((char *)(buffer[5] + 2), ',');
	if (!color_c)
		return (ft_putstr_fd(RED_L,
				"Error\nMalloc broke convert_color\n", 2), -1);
	ft_convert_color(buffer, data, color_f, color_c);
	return (1);
}
