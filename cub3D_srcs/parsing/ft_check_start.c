/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_start.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julien <julien@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 14:04:51 by julien            #+#    #+#             */
/*   Updated: 2022/03/31 21:16:06 by julien           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3D_include/cub3D.h"

int	ft_start_char(t_data *data, char c)
{
	char	*check;
	int		i;

	i = 0;
	check = ft_strdup(data, "NSEW");
	while (check[i])
	{
		if (check[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int	ft_nb_start(t_data *data, char **map)
{
	int	i;
	int	j;

	i = 0;
	while (i < data->map_height)
	{
		j = 0;
		while (j < data->map_width)
		{
			if (ft_start_char(data, map[i][j]) == 1)
			{
				if (data->player.x == 0 && data->player.y == 0)
				{
					data->player.x = i;
					data->player.y = j;
				}
				else
					return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

int	ft_check_start(t_data *data, t_fd *tmp)
{
	if (ft_nb_start(data, tmp->map) == 1)
		return (1);
	if (data->player.x == 0 && data->player.y == 0)
		return (1);
	return (0);
}
