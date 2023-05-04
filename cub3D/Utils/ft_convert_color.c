/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_color.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ceatgie <ceatgie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 17:57:33 by ceatgie           #+#    #+#             */
/*   Updated: 2023/05/03 13:25:33 by ceatgie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

static void	ft_free_convert_color(char *hexa, char *buf, char **color_f,
	char **color_c)
{
	free(hexa);
	free(buf);
	ft_free(color_f);
	ft_free(color_c);
}

static void	ft_convert_color_f(char **buffer, t_parse *data, char **color_f,
	char **color_c)
{
	char	*hexa;
	char	*buf;
	int		i;
	int		j;

	i = -1;
	j = -1;
	(void)color_c;
	(void)buffer;
	buf = malloc(sizeof(char) * 10);
	if (!buf)
		return ;
	hexa = ft_strdup("0123456789ABCDEF");
	if (!hexa)
		return ;
	while (++i < 3)
	{
		buf[++j] = hexa[ft_atoi(color_f[i]) / 16];
		buf[++j] = hexa[ft_atoi(color_f[i]) % 16];
	}
	buf[++j] = '\0';
	data->color_f = ft_convert_to_hex(buf);
	free(buf);
	free(hexa);
}

void	ft_convert_color(char **buffer, t_parse *data, char **color_f,
	char **color_c)
{
	char	*hexa;
	char	*buf;
	int		i;
	int		j;

	i = -1;
	j = -1;
	buf = malloc(sizeof(char) * 10);
	if (!buf)
		return ;
	hexa = ft_strdup("0123456789ABCDEF");
	if (!hexa)
		return ;
	ft_convert_color_f(buffer, data, color_f, color_c);
	while (++i < 3)
	{
		buf[++j] = hexa[ft_atoi(color_c[i]) / 16];
		buf[++j] = hexa[ft_atoi(color_c[i]) % 16];
	}
	buf[++j] = '\0';
	data->color_c = ft_convert_to_hex(buf);
	ft_free_convert_color(hexa, buf, color_f, color_c);
}
