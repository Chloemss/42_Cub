/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_cub.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hook <hook@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 09:44:01 by ceatgie           #+#    #+#             */
/*   Updated: 2023/04/28 14:47:04 by hook             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3D.h"

//	===================================================================
//								Commentary
//							   ------------
//	
//	- Take as parameters: argc, argv
//	
//	- Orient the error message according to argc
//	
//	- Exit with error 0 if something is going wrong
//	
//	===================================================================

void	ft_check_cub(int argc, char *argv[])
{
	if (argc < 2)
	{
		ft_putstr_fd(RED_L, "Error\nPlease use programm like this:\n", 2);
		ft_putstr_fd(RED_L, "./cubtroisd <path_to_.cub_file>\n\n", 2);
		exit(0);
	}
	if (argc > 2)
	{
		ft_putstr_fd(RED_L,
			"Error\nPlease enter a .cub file & nothing more\n", 2);
		exit(0);
	}
	if (argc == 2)
	{
		if (ft_check_cub_format(argv[1]))
		{
			ft_putstr_fd(RED_L, "Error\nPlease put .cub file\n", 2);
			exit(0);
		}
	}
}
