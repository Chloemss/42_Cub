/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_if_can_acces.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ceatgie <ceatgie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 16:10:21 by hook              #+#    #+#             */
/*   Updated: 2023/05/03 13:10:58 by ceatgie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3D.h"

static char	**ft_for_not_absolute_path(char **buffer_bis, char **env)
{
	int		i;
	char	*path;
	char	**tmp;

	i = 0;
	while (ft_strncmp(env[i], "PWD=", 4))
		i++;
	path = ft_strdup(env[i] + 4);
	tmp = malloc(sizeof(char *) * 5);
	i = 0;
	while (i < 4)
	{
		tmp[i] = ft_strjoin_classic(path, buffer_bis[i]);
		i++;
	}
		tmp[i] = NULL;
	return (free(path), tmp);
}

static int	ft_get_texture_in_tab(char **buffer_bis, char **tmp,
	t_cub *cub, int i)
{
	if (!cub->texture_tab)
		return (ft_free(tmp), -1);
	cub -> texture_tab[4] = NULL;
	if (cub->cpt == 0)
	{
		cub->texture_tab[i] = ft_strdup(buffer_bis[i]);
		if (!cub->texture_tab[i])
			return (ft_free(tmp), -1);
	}
	else
	{
		cub->texture_tab[i] = ft_strdup(tmp[i]);
		if (!cub->texture_tab[i])
			return (ft_free(tmp), -1);
	}
	return (1);
}

static int	ft_check_if_can_access_else_else(char **buffer_bis, char **tmp,
	t_cub *cub, int i)
{
	if (access(buffer_bis[i], R_OK))
	{
		if (access(tmp[i], R_OK))
			return (ft_putstr_fd(RED_L,
					"Error\nNo Read Access\n", 2), ft_free(buffer_bis),
				ft_free(tmp), ft_free(cub->texture_tab), 0);
	}
	return (1);
}

static int	ft_check_if_can_acces_else(char **buffer_bis, char **env,
	t_cub *cub)
{
	int		i;
	char	**tmp;

	i = 0;
	cub->cpt = 0;
	cub -> texture_tab = malloc(sizeof(char *) * 5);
	tmp = ft_for_not_absolute_path(buffer_bis, env);
	while (buffer_bis[i])
	{
		if (access(buffer_bis[i], F_OK))
		{
			cub->cpt++;
			if (access(tmp[i], F_OK))
				return (ft_putstr_fd(RED_L,
						"Error\nTexture Path doesn't exist\n", 2),
					ft_free(buffer_bis),
					ft_free(tmp), ft_free(cub->texture_tab), 0);
		}
		ft_check_if_can_access_else_else(buffer_bis, tmp, cub, i);
		ft_get_texture_in_tab(buffer_bis, tmp, cub, i);
		cub->cpt = 0;
		i++;
	}
	return (ft_free(tmp), 1);
}

int	ft_check_if_can_acces(char **buffer, char **env, t_cub *cub)
{
	char	**buffer_bis;
	int		i;

	i = 0;
	buffer_bis = malloc(sizeof(char *) * 5);
	if (!buffer_bis)
		return (ft_putstr_fd(RED_L, "Error\nMalloc broke\n", 2), -1);
	while (i < 4)
	{
		buffer_bis[i] = ft_strdup(buffer[i] + 4);
		if (!buffer_bis[i])
			return (ft_putstr_fd(RED_L,
					"Error\nMalloc broke using strdup\n", 2), -1);
		i++;
	}
	buffer_bis[i] = NULL;
	if (!ft_check_if_can_acces_else(buffer_bis, env, cub))
		return (0);
	return (ft_free(buffer_bis), 1);
}
