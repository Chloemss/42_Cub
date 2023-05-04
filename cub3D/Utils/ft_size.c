/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_size.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hook <hook@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 10:38:08 by ceatgie           #+#    #+#             */
/*   Updated: 2023/04/26 13:08:36 by hook             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

//	===================================================================
//								Commentary
//							   ------------
//	
//	- Take as parameters: pointer to cub struct
//	
//	- Calculate the size of one line in File Descriptor
//	
//	- Return the size of one line in File Descriptor
//	
//	===================================================================

int	ft_size(t_parse *data)
{
	char	buffer[1024];
	int		i;
	int		fd;
	int		red;

	i = 0;
	fd = open(data->argv[1], O_RDONLY);
	red = read(fd, buffer, 1024);
	if (red == -1)
		return (ft_putstr_fd(RED_L, "Error\nRead fonction return -1\n", 2), -1);
	buffer[red] = '\0';
	if (!buffer[0])
		return (ft_putstr_fd(RED_L, "Error\nMap is empty !\n", 2), -1);
	while (buffer[i] != '\n')
		i++;
	close(fd);
	return (i);
}
