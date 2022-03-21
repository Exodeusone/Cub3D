/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_name_map.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exodeus <exodeus@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 09:26:50 by jbonniva          #+#    #+#             */
/*   Updated: 2022/03/21 22:03:36 by exodeus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3D_include/cub3D.h"

int	ft_check_extention_name(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	i--;
	if (str[i] != 'b')
		return (1);
	i--;
	if (str[i] != 'u')
		return (1);
	i--;
	if (str[i] != 'c')
		return (1);
	i--;
	if (str[i] != '.')
		return (1);
	return (0);
}

int	ft_check_beggin_name(char *str)
{
	if (str[0] == '.')
	{
		if (ft_strncmp(str, "./cub3D_maps/", (ft_strlen("./cub3D_map/") + 1)) != 0)
			return (1);
	}
	if (str[0] == 'c')
	{
		if (ft_strncmp(str, "cub3D_maps/", (ft_strlen("cub3D_map/") + 1)) != 0)
			return (1);
	}
	if (str[0] != 'c' && str[0] != '.')
		return (1);
	return (0);
}

int	ft_check_name_map(char *str)
{
	if (ft_strlen(str) == 0)
		return (ft_puterr("You need to use map in arguments\n"), 1);
	if (ft_check_extention_name(str) == 1)
		return (ft_puterr("Map extension need to be .cub\n"), 1);
	if (ft_check_beggin_name(str) == 1)
		return (ft_puterr("Map need to be in cub3D_maps\n"), 1);
	return (0);
}