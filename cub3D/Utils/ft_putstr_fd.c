/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ceatgie <ceatgie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 09:51:02 by ceatgie           #+#    #+#             */
/*   Updated: 2023/05/03 13:26:11 by ceatgie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

void	ft_putstr_fd(char *color, char *str, int fd)
{
	int	i;

	i = write(fd, color, ft_strlen(color));
	i = write(fd, str, ft_strlen(str));
	i = write(fd, RESET, ft_strlen(RESET));
	i++;
}
