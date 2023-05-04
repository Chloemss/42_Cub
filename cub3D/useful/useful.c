/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   useful.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ceatgie <ceatgie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 10:49:32 by cmassavi          #+#    #+#             */
/*   Updated: 2023/05/03 13:15:49 by ceatgie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int	ft_error(char *str)
{
	int	i;

	i = write (2, str, ft_strlen(str));
	i = write (2, "\n", 1);
	i++;
	exit (1);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*join;

	i = -1;
	j = 0;
	if (!s1)
	{
		s1 = malloc(sizeof(char) * 1);
		s1[0] = '\0';
	}
	if (!s1 || !s2)
		return (NULL);
	join = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!join)
		return (NULL);
	if (s1)
		while (s1[++i])
			join[i] = s1[i];
	while (s2[j])
		join[i++] = s2[j++];
	join[ft_strlen(s1) + ft_strlen(s2)] = '\0';
	free(s1);
	return (join);
}

char	*free_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i] != NULL)
	{
		free (tab[i]);
		i++;
	}
	return (NULL);
}

void	print_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i] != NULL)
	{
		printf ("%s et i = %d\n", tab[i], i);
		i++;
	}
}
