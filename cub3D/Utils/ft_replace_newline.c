/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_replace_newline.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hook <hook@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 11:20:35 by hook              #+#    #+#             */
/*   Updated: 2023/04/29 11:49:40 by hook             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

void	ft_replace_newline(t_parse	*data)
{
	int	i;
	int	j;

	i = ft_acces_map(data);
	j = 0;
	while (data->file_info[i])
	{
		while (data->file_info[i][j])
		{
			if (data->file_info[i][j] == '\n')
				data->file_info[i][j] = '\0';
			j++;
		}
		i++;
		j = 0;
	}
}
