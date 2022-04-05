/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: upean-de <upean-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 13:31:37 by upean-de          #+#    #+#             */
/*   Updated: 2022/04/05 16:45:14 by upean-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3D_include/cub3D.h"

void	move_up_2(t_data *data)
{
	if (data->map[(int)(data->player.pos_x + data->player.dir_x * data->player.move_speed)][(int)data->player.pos_y] == '0')
		data->player.pos_x += data->player.dir_x * data->player.move_speed;
	if (data->map[(int)data->player.pos_x][(int)(data->player.pos_y + data->player.dir_y * data->player.move_speed)] == '0')
		data->player.pos_y += data->player.dir_y * data->player.move_speed;
	draw_ray_2(data, data->map);
}

void	move_down_2(t_data *data)
{
	if (data->map[(int)(data->player.pos_x - data->player.dir_x * data->player.move_speed)][(int)data->player.pos_y] == '0')
		data->player.pos_x -= data->player.dir_x * data->player.move_speed;
	if (data->map[(int)data->player.pos_x][(int)(data->player.pos_y - data->player.dir_y * data->player.move_speed)] == '0')
		data->player.pos_y -= data->player.dir_y * data->player.move_speed;
	draw_ray_2(data, data->map);
}
