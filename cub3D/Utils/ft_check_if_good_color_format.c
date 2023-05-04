/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_if_good_color_format.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hook <hook@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 14:53:59 by hook              #+#    #+#             */
/*   Updated: 2023/04/29 12:03:45 by hook             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

bool	ft_check_if_good_color_format(char **buffer)
{
	int	i;

	i = 2;
	if (buffer[4][1] != ' ')
		return (ft_putstr_fd(RED_L, "Error\nNot valid F color format\n", 2), 0);
	if (buffer[5][1] != ' ')
		return (ft_putstr_fd(RED_L, "Error\nNot valid C color format\n", 2), 0);
	while ((buffer[4][i] >= '0' && buffer [4][i] <= '9')
		|| (buffer[4][i] == ','))
		i++;
	if (i != ft_strlen(buffer[4]) - 1)
		return (ft_putstr_fd(RED_L, "Error\nNot valid F color format\n", 2), 0);
	i = 2;
	while ((buffer[5][i] >= '0' && buffer [5][i] <= '9')
		|| (buffer[5][i] == ','))
		i++;
	if (i != ft_strlen(buffer[5]) - 1)
		return (ft_putstr_fd(RED_L, "Error\nNot valid C color format\n", 2), 0);
	return (1);
}
