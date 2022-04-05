/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_move.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: upean-de <upean-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 18:31:43 by upean-de          #+#    #+#             */
/*   Updated: 2022/04/05 12:05:41 by upean-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3D_include/cub3D.h"

int	ok_move_up(t_data *data)
{
	float	x;
	float	y;

	x = (data->player.pos_x + data->player.dx) / 64;
	y = (data->player.pos_y + data->player.dy) / 64;
	if (x >= 0 && x < data->map_width && y - 0.1 >= 0 && y < data->map_height
		&& data->map[(int)y][(int)x] == '1')
		return (1);
	return (0);
}

int	ok_move_down(t_data *data)
{
	float	x;
	float	y;

	x = (data->player.pos_x - data->player.dx) / 64;
	y = (data->player.pos_y - data->player.dy) / 64;
	if (x >= 0 && x < data->map_width && y >= 0 && y < data->map_height
		&& data->map[(int)y][(int)x] == '1')
		return (1);
	return (0);
}

int	ok_move_side(t_data *data, float dx, float dy)
{
	float	x;
	float	y;

	x = (data->player.pos_x + dx) / 64;
	y = (data->player.pos_y + dy) / 64;
	if (x >= 0 && x < data->map_width && y >= 0 && y < data->map_height
		&& data->map[(int)y][(int)x] == '1')
		return (1);
	return (0);
}
