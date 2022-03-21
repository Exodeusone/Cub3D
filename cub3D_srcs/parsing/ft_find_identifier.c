/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_identifier.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exodeus <exodeus@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 22:39:56 by exodeus           #+#    #+#             */
/*   Updated: 2022/03/21 22:40:06 by exodeus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3D_include/cub3D.h"

int	ft_check_rgb(char *str)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != '\n')
	{
		if ((str[i] < '0' || str[i] > '9') && str[i] != ',')
			return (1);
		i++;
	}
	return (0);
}

int	ft_find_identifier(t_data *data, char *str)
{
	if (ft_strncmp(str, "SO", 2) == 0)
	{
		if (ft_check_identifier_1(data, str) == 1)
			return (1);
	}
	if (ft_strncmp(str, "NO", 2) == 0)
	{
		if (ft_check_identifier_1(data, str) == 1)
			return (1);
	}
	if (ft_strncmp(str, "WE", 2) == 0)
	{
		if (ft_check_identifier_1(data, str) == 1)
			return (1);
	}
	if (ft_strncmp(str, "EA", 2) == 0)
	{
		if (ft_check_identifier_1(data, str) == 1)
			return (1);
	}
	if (ft_strncmp(str, "F", 1) == 0)
	{
		if (ft_check_identifier_2(data, str) == 1)
			return (1);
	}
	if (ft_strncmp(str, "C", 1) == 0)
	{
		if (ft_check_identifier_2(data, str) == 1)
			return (1);
	}
	return (0);
}