/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: upean-de <upean-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 11:41:01 by julien            #+#    #+#             */
/*   Updated: 2022/04/06 13:05:35 by upean-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3D_include/cub3D.h"

int	ft_check_char(t_data *data, char c)
{
	int		i;
	char	*check;

	i = 0;
	check = ft_strdup(data, "01NSEW");
	while (check[i])
	{
		if (check[i] == c)
		{
			ft_free(data, check);
			return (0);
		}
		i++;
	}
	return (1);
}

int	ft_check_around(t_data *data, char c)
{
	int		i;
	char	*check;

	i = 0;
	check = ft_strdup(data, "1 ");
	while (check[i])
	{
		if (check[i] == c)
		{
			ft_free(data, check);
			return (0);
		}
		i++;
	}
	return (1);
}

int	ft_parse_around(t_data *data, char **map, int i, int j)
{
	if (i != 0 && j != 0 && i != data->map_height && j != data->map_width)
	{
		if (ft_check_char(data, map[i][j + 1]) == 1)
			return (1);
		if (ft_check_char(data, map[i][j - 1]) == 1)
			return (1);
		if (ft_check_char(data, map[i - 1][j]) == 1)
			return (1);
		if (ft_check_char(data, map[i + 1][j]) == 1)
			return (1);
	}
	else
	{
		if (ft_check_around(data, map[i][j]) == 1)
			return (1);
	}
	return (0);
}

int	ft_is_in_map(t_data *data, char c)
{
	char	*around;
	int		i;
	int		ret;

	i = 0;
	ret = 0;
	around = ft_strdup(data, "0SEWN");
	while (around[i])
	{
		if (around[i] == c)
			ret++;
		i++;
	}
	ft_free(data, around);
	return (ret);
}

int	ft_check_floor(t_data *data, t_fd *map)
{
	int	i;
	int	j;

	i = 0;
	while (i < data->map_height)
	{
		j = 0;
		while (j < data->map_width)
		{
			if (ft_is_in_map(data, map->map[i][j]) > 0)
			{
				if (ft_parse_around(data, map->map, i, j) == 1)
					return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

int	ft_check_map(t_data *data)
{
	t_fd	*tmp;

	tmp = data->fd;
	while (tmp->next)
		tmp = tmp->next;
	if (ft_check_floor(data, tmp) == 1)
		return (ft_puterr("Error\nMap is not closed\n"), 1);
	if (ft_check_start(data, tmp) == 1)
		return (ft_puterr("Error\nInvalid number of start position\n"), 1);
	return (0);
}
