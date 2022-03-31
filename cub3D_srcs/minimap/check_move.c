/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_move.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julien <julien@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 18:31:43 by upean-de          #+#    #+#             */
/*   Updated: 2022/03/31 22:16:14 by julien           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3D_include/cub3D.h"

int	ok_move_up(t_data *data)
{
	float	x;
	float	y;

	x = (data->player.x + data->player.dx) / 64;
	y = (data->player.y + data->player.dy) / 64;
	if (x >= 0 && x < data->map_width && y - 0.1 >= 0 && y < data->map_height
		&& data->map[(int)y][(int)x] == '1')
		return (1);
	return (0);
}

int	ok_move_down(t_data *data)
{
	float	x;
	float	y;

	x = (data->player.x - data->player.dx) / 64;
	y = (data->player.y - data->player.dy) / 64;
	if (x >= 0 && x < data->map_width && y >= 0 && y < data->map_height
		&& data->map[(int)y][(int)x] == '1')
		return (1);
	return (0);
}

int	ok_move_side(t_data *data, float dx, float dy)
{
	float	x;
	float	y;

	x = (data->player.x + dx) / 64;
	y = (data->player.y + dy) / 64;
	if (x >= 0 && x < data->map_width && y >= 0 && y < data->map_height
		&& data->map[(int)y][(int)x] == '1')
		return (1);
	return (0);
}
