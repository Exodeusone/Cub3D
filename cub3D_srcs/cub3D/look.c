/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   look.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: upean-de <upean-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 21:15:48 by julien            #+#    #+#             */
/*   Updated: 2022/04/06 11:40:12 by upean-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3D_include/cub3D.h"

void	look_right(t_data *data)
{
	float	old_dir_x;
	float	old_plane_x;

	if (data->move.rr == 1)
	{
		old_dir_x = data->player.dir_x;
		old_plane_x = data->player.plane_x;
		data->player.dir_x = data->player.dir_x * cos(-data->player.rot_speed) - data->player.dir_y * sin(-data->player.rot_speed);
		data->player.dir_y = old_dir_x * sin(-data->player.rot_speed) + data->player.dir_y * cos(-data->player.rot_speed);
		data->player.plane_x = data->player.plane_x * cos(-data->player.rot_speed) - data->player.plane_y * sin(-data->player.rot_speed);
		data->player.plane_y = old_plane_x * sin(-data->player.rot_speed) + data->player.plane_y * cos(-data->player.rot_speed);
	}
}

void	look_left(t_data *data)
{
	float	old_dir_x;
	float	old_plane_x;

	if (data->move.rl == 1)
	{
		old_dir_x = data->player.dir_x;
		old_plane_x = data->player.plane_x;
		data->player.dir_x = data->player.dir_x * cos(data->player.rot_speed) - data->player.dir_y * sin(data->player.rot_speed);
		data->player.dir_y = old_dir_x * sin(data->player.rot_speed) + data->player.dir_y * cos(data->player.rot_speed);
		data->player.plane_x = data->player.plane_x * cos(data->player.rot_speed) - data->player.plane_y * sin(data->player.rot_speed);
		data->player.plane_y = old_plane_x * sin(data->player.rot_speed) + data->player.plane_y * cos(data->player.rot_speed);
	}
}

void	move(t_data *data)
{
	move_up(data);
	move_down(data);
	move_right(data);
	move_left(data);
	look_right(data);
	look_left(data);
}
