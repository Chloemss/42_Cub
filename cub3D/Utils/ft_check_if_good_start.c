/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_if_good_start.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ceatgie <ceatgie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 14:49:02 by hook              #+#    #+#             */
/*   Updated: 2023/05/03 13:16:07 by ceatgie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

bool	ft_check_if_good_start(char **buffer)
{
	if (buffer[0][0] != 'N' || buffer[0][1] != 'O')
		return (ft_putstr_fd(RED_L, "Error\nNo NO written\n", 2), 0);
	if (buffer[1][0] != 'S' || buffer[1][1] != 'O')
		return (ft_putstr_fd(RED_L, "Error\nNo SO written\n", 2), 0);
	if (buffer[2][0] != 'W' || buffer[2][1] != 'E')
		return (ft_putstr_fd(RED_L, "Error\nNo WE written\n", 2), 0);
	if (buffer[3][0] != 'E' || buffer[3][1] != 'A')
		return (ft_putstr_fd(RED_L, "Error\nNo EA written\n", 2), 0);
	if (buffer[4][0] != 'F')
		return (ft_putstr_fd(RED_L, "Error\nNo F written\n", 2), 0);
	if (buffer[5][0] != 'C')
		return (ft_putstr_fd(RED_L, "Error\nNo C written\n", 2), 0);
	return (1);
}
