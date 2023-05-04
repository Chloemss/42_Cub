/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_if_good_color_range.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hook <hook@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 14:54:57 by hook              #+#    #+#             */
/*   Updated: 2023/04/28 16:40:23 by hook             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

bool	ft_check_if_good_color_range(char **buffer)
{
	char	**color;
	char	*tmp1;
	char	*tmp2;
	int		i;

	i = -1;
	tmp1 = buffer[4] + 2;
	color = ft_split(tmp1, ',');
	if (!color)
		return (ft_putstr_fd(RED_L, "Error\nMalloc on split\n", 2), 0);
	while (color[++i])
		if (ft_atoi(color[i]) > 255)
			return (ft_free(color),
				ft_putstr_fd(RED_L, "Error\nColor is over 255\n", 2), 0);
	ft_free(color);
	tmp2 = buffer[5] + 2;
	i = -1;
	color = ft_split(tmp2, ',');
	if (!color)
		return (ft_putstr_fd(RED_L, "Error\nMalloc on split\n", 2), 0);
	while (color[++i])
		if (ft_atoi(color[i]) > 255)
			return (ft_free(color),
				ft_putstr_fd(RED_L, "Error\nColor is over 255\n", 2), 0);
	return (ft_free(color), 1);
}
