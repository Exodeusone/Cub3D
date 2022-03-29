/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: upean-de <upean-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 15:14:37 by upean-de          #+#    #+#             */
/*   Updated: 2022/03/29 18:22:01 by upean-de         ###   ########.fr       */
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
			mlx_pixel_put(data->mlx, data->win, x, y, create_trgb(0, 255, 255, 255));
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
	// int	i;
	// int	j;
	// int	x;
	// int	y;

	// i = (int)data->player.x / MAP_S - 2;
	// y = i * MAP_S;
	// while (i < 0 || i > data->map_width)
	// {
	// 	if (i < 0)
	// 	{
	// 		i += 1;
	// 		y += MAP_S;
	// 	}
	// 	else if (i > data->map_width)
	// 	{
	// 		i -= 1;
	// 		y -= MAP_S;
	// 	}
	// }
	// while (i < (int)data->player.x / MAP_S + 2)
	// {
	// 	j = (int)data->player.y / MAP_S - 2;
	// 	x = j * MAP_S;
	// 	while (j < 0 || j > data->map_height)
	// 	{
	// 		if (j < 0)
	// 		{
	// 			j += 1;
	// 			x += MAP_S;
	// 		}
	// 		else if (j > data->map_height)
	// 		{
	// 			j -= 1;
	// 			x -= MAP_S;
	// 		}
	// 	}
	// 	while (j < (int)data->player.y / MAP_S + 2)
	// 	{
	// 		if (map[i][j] == '1')
	// 			draw_wall(data, x, y);
	// 		x += MAP_S;
	// 		j++;
	// 	}
	// 	y += MAP_S;
	// 	i++;
	// }
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
