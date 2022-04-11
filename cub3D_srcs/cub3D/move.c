/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: upean-de <upean-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 15:07:58 by upean-de          #+#    #+#             */
/*   Updated: 2022/04/06 14:33:06 by upean-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3D_include/cub3D.h"

void	move_up(t_data *data)
{
	if (data->move.up == 1)
	{
		if (data->map[(int)(data->player.pos_x + (data->player.dir_x
					* data->player.move_speed))][(int)data->player.pos_y]
						!= '1')
			data->player.pos_x += data->player.dir_x * data->player.move_speed;
		if (data->map[(int)data->player.pos_x][(int)(data->player.pos_y
			+ (data->player.dir_y * data->player.move_speed * 2))] != '1')
			data->player.pos_y += data->player.dir_y * data->player.move_speed;
	}
}

void	move_down(t_data *data)
{
	if (data->move.down == 1)
	{
		if (data->map[(int)(data->player.pos_x - data->player.dir_x
				* data->player.move_speed)][(int)data->player.pos_y] != '1')
			data->player.pos_x -= data->player.dir_x * data->player.move_speed;
		if (data->map[(int)data->player.pos_x][(int)(data->player.pos_y
			- data->player.dir_y * data->player.move_speed)] != '1')
			data->player.pos_y -= data->player.dir_y * data->player.move_speed;
	}
}

void	move_right(t_data *data)
{
	if (data->move.right == 1)
	{
		if (data->map[(int)(data->player.pos_x + (data->player.dir_y
					* data->player.move_speed))][(int)data->player.pos_y]
						!= '1')
			data->player.pos_x += data->player.dir_y * data->player.move_speed;
		if (data->map[(int)data->player.pos_x][(int)(data->player.pos_y
			- (data->player.dir_x * data->player.move_speed * 2))] != '1')
			data->player.pos_y -= data->player.dir_x * data->player.move_speed;
	}
}

void	move_left(t_data *data)
{
	if (data->move.left == 1)
	{
		if (data->map[(int)(data->player.pos_x - (data->player.dir_y
					* data->player.move_speed))][(int)data->player.pos_y]
						!= '1')
			data->player.pos_x -= data->player.dir_y * data->player.move_speed;
		if (data->map[(int)data->player.pos_x][(int)(data->player.pos_y
			+ (data->player.dir_x * data->player.move_speed * 2))] != '1')
			data->player.pos_y += data->player.dir_x * data->player.move_speed;
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
