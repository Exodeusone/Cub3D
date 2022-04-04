/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julien <julien@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 15:14:37 by upean-de          #+#    #+#             */
/*   Updated: 2022/04/04 22:52:52 by julien           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3D_include/cub3D.h"

void	draw_wall(t_data *data, int x, int y)
{
	int	i;
	int	j;

	i = 0;
	while (i < MAP_S - 1)
	{
		j = 0;
		while (j < MAP_S - 1)
		{
			data->asset[1].addr[y * data->map_width
				* MAP_S + x] = create_trgb(0, 255, 255, 255);
			x++;
			j++;
		}
		x -= j;
		y++;
		i++;
	}
}

void	draw_map(t_data *data, char **map)
{
	int	i;
	int	j;
	int	x;
	int	y;

	i = 0;
	y = 0;
	while (map[i])
	{
		j = 0;
		x = 0;
		while (map[i][j])
		{
			if (map[i][j] == '1')
				draw_wall(data, x, y);
			x += MAP_S;
			j++;
		}
		y += MAP_S;
		i++;
	}
}