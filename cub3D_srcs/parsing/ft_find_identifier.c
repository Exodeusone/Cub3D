/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_identifier.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: upean-de <upean-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 22:39:56 by exodeus           #+#    #+#             */
/*   Updated: 2022/04/06 13:25:38 by upean-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3D_include/cub3D.h"

int	ft_ultimate_check_rgb(t_data *data, char *str, char c)
{
	char	**check;
	int		i;
	int		ret;

	i = 0;
	check = ft_split(data, str, ',');
	if (ft_strslen(check) != 3)
		return (1);
	while (check[i])
	{
		if (ft_strlen_rgb(check[i]) > 3 || ft_strlen_rgb(check[i]) < 1)
			return (1);
		ret = ft_atoi(check[i]);
		if (ret < 0 || ret > 255)
			return (1);
		else
			ft_add_rgb(data, ret, c, i);
		i++;
	}
	ft_free_strs(data, check);
	return (0);
}

int	ft_check_rgb(t_data *data, char *str, char c)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != '\n')
	{
		if ((str[i] < '0' || str[i] > '9') && str[i] != ',')
			return (1);
		i++;
	}
	if (ft_ultimate_check_rgb(data, str, c) == 1)
		return (1);
	return (0);
}

int	ft_find_identifier_1(t_data *data, char *str)
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
	return (0);
}

int	ft_find_identifier_2(t_data *data, char *str)
{
	if (ft_strncmp(str, "F", 1) == 0)
	{
		if (ft_check_identifier_2(data, str, 'F') == 1)
			return (1);
	}
	if (ft_strncmp(str, "C", 1) == 0)
	{
		if (ft_check_identifier_2(data, str, 'C') == 1)
			return (1);
	}
	return (0);
}

int	ft_find_identifier(t_data *data, char *str)
{
	if (ft_find_identifier_1(data, str) == 1)
		return (1);
	if (ft_find_identifier_2(data, str) == 1)
		return (1);
	return (0);
}
