/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_data.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ceatgie <ceatgie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 13:22:29 by ceatgie           #+#    #+#             */
/*   Updated: 2023/05/03 11:22:15 by ceatgie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

void	print_cub(t_cub *cub)
{
	printf("cub -> texture_so =  %s", cub -> texture_tab[1]);
	printf("cub -> texture_no =  %s", cub -> texture_tab[0]);
	printf("cub -> texture_we = %s", cub -> texture_tab[2]);
	printf("cub -> texture_ea = %s", cub -> texture_tab[3]);
	printf("cub -> texture_f = %s", cub -> texture_f);
	printf("cub -> texture_c %s", cub -> texture_c);
}
