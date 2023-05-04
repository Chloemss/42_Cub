/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_texture_format.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hook <hook@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 15:30:06 by hook              #+#    #+#             */
/*   Updated: 2023/05/01 16:54:35 by hook             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3D.h"

bool	ft_check_texture_format(char **buffer)
{
	int	i;
	int	j;

	i = 0;
	while (i < 4)
	{
		j = ft_strlen(buffer[i]) - 1;
		if (!(buffer[i][j] == 'm' && buffer[i][j - 1] == 'p'
			&& buffer[i][j - 2] == 'x' && buffer[i][j - 3] == '.'))
			return (ft_putstr_fd(RED_L,
					"Error\nWrong texture format\nPlease use .XPM only\n", 2), 0);
		i++;
	}
	return (1);
}
