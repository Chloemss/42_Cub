/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_if_good_path.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hook <hook@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 14:51:35 by hook              #+#    #+#             */
/*   Updated: 2023/05/01 16:00:27 by hook             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

bool	ft_check_if_good_path(char **buffer)
{
	if (buffer[0][2] != ' ' || buffer[0][3] != '.' || buffer[0][4] != '/')
		return (ft_putstr_fd(RED_L, "Error\nNot valid NO path\n", 2), 0);
	if (buffer[1][2] != ' ' || buffer[1][3] != '.' || buffer[1][4] != '/')
		return (ft_putstr_fd(RED_L, "Error\nNot valid SO path\n", 2), 0);
	if (buffer[2][2] != ' ' || buffer[2][3] != '.' || buffer[2][4] != '/')
		return (ft_putstr_fd(RED_L, "Error\nNot valid WE path\n", 2), 0);
	if (buffer[3][2] != ' ' || buffer[3][3] != '.' || buffer[3][4] != '/')
		return (ft_putstr_fd(RED_L, "Error\nNot valid EA path\n", 2), 0);
	return (1);
}
