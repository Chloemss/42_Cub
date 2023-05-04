/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ceatgie <ceatgie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 14:01:49 by cmassavi          #+#    #+#             */
/*   Updated: 2023/05/03 13:14:51 by ceatgie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"
#include <mlx.h>
#include <math.h>

int	get_pixel_color(t_cub *cub, int x, int y)
{
	char	*dst;

	dst = NULL;
	dst = cub->ptr_text[cub->actualtext]
		+ (y * cub->size_line_text[cub->actualtext]
			+ x * (cub->bpp_text[cub->actualtext] / 8));
	return (*(unsigned int *)dst);
}
	//Chloe : modified
	// Free correctement tout et quitter proprement
	//Cedric

int	error_loadtexture(t_cub *cub, int i)
{
	if (!cub->text[i])
	{
		printf ("load texture fail\n");
		return (-1);
	}
	return (1);
}

int	loadtexture(t_cub *cub)
{
	cub->text[0] = mlx_xpm_file_to_image(cub->mlx_ptr, cub->texture_tab[0],
			&cub->widthtext[0], &cub->heighttext[0]);
	error_loadtexture(cub, 0);
	cub->ptr_text[0] = mlx_get_data_addr(cub->text[0],
			&(cub->bpp_text[0]), &(cub->size_line_text[0]),
			&(cub->endian_text[0]));
	cub->text[1] = mlx_xpm_file_to_image(cub->mlx_ptr, cub->texture_tab[1],
			&cub->widthtext[1], &cub->heighttext[1]);
	error_loadtexture(cub, 1);
	cub->ptr_text[1] = mlx_get_data_addr(cub->text[1],
			&(cub->bpp_text[1]), &(cub->size_line_text[1]),
			&(cub->endian_text[1]));
	cub->text[2] = mlx_xpm_file_to_image(cub->mlx_ptr, cub->texture_tab[2],
			&cub->widthtext[2], &cub->heighttext[2]);
	error_loadtexture(cub, 2);
	cub->ptr_text[2] = mlx_get_data_addr(cub->text[2],
			&(cub->bpp_text[2]), &(cub->size_line_text[2]),
			&(cub->endian_text[2]));
	cub->text[3] = mlx_xpm_file_to_image(cub->mlx_ptr, cub->texture_tab[3],
			&cub->widthtext[3], &cub->heighttext[3]);
	error_loadtexture(cub, 3);
	cub->ptr_text[3] = mlx_get_data_addr(cub->text[3],
			&(cub->bpp_text[3]), &(cub->size_line_text[3]),
			&(cub->endian_text[3]));
	return (0);
}

void	which_texture(t_cub *cub, double hauteur, double x, t_coord co_end)
{
	if (fmod(co_end.x, 64) == 0)
	{
		cub->actualtext = 1;
		print_column(cub, hauteur, x, co_end.y);
	}
	else if (fmod(co_end.y, 64) == 0)
	{
		cub->actualtext = 3;
		print_column(cub, hauteur, x, co_end.x);
	}
	else if (fmod(co_end.y, 64) >= (double)63.998)
	{
		cub->actualtext = 2;
		print_column(cub, hauteur, x, co_end.x);
	}
	else
	{
		cub->actualtext = 0;
		print_column(cub, hauteur, x, co_end.y);
	}
}
/*
	Fonction main pour le display
*/

void	draw_line_at_angle(t_cub *cub)
{
	double	length;
	double	angle2;
	double	x;
	t_coord	co_end;
	double	hauteur;

	dist_map(cub);
	angle2 = correct_angle(cub -> pov - 30);
	x = 0;
	while (x < cub->xscreen)
	{
		angle2 += (double)60 / (double)cub->xscreen;
		length = inter(cub, angle2);
		co_end = inter_co(cub, angle2, x);
		length = (double)roundf(length
				*(cos(((cub-> pov - angle2) * M_PI) / (double)180)));
		hauteur = (double)64 / length * cub->dist;
		which_texture(cub, hauteur, x, co_end);
		x++;
	}
}
