/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: upean-de <upean-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 15:07:58 by upean-de          #+#    #+#             */
/*   Updated: 2022/04/06 13:39:50 by upean-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3D_include/cub3D.h"

void	move_up(t_data *data)
{
	if (data->move.up == 1)
	{
		if (data->map[(int)(data->player.pos_x + (data->player.dir_x * data->player.move_speed))][(int)data->player.pos_y] != '1')
			data->player.pos_x += data->player.dir_x * data->player.move_speed;
		if (data->map[(int)data->player.pos_x][(int)(data->player.pos_y + (data->player.dir_y * data->player.move_speed * 2))] != '1')
			data->player.pos_y += data->player.dir_y * data->player.move_speed;
	}
}

void	move_down(t_data *data)
{
	if (data->move.down == 1)
	{
		if (data->map[(int)(data->player.pos_x - data->player.dir_x * data->player.move_speed)][(int)data->player.pos_y] != '1')
			data->player.pos_x -= data->player.dir_x * data->player.move_speed;
		if (data->map[(int)data->player.pos_x][(int)(data->player.pos_y - data->player.dir_y * data->player.move_speed)] != '1')
			data->player.pos_y -= data->player.dir_y * data->player.move_speed;
	}
}

void	move_right(t_data *data)
{
	// printf("dirx : %f == diry : %f\n", data->player.dir_x, data->player.dir_y);
	// printf("posx : %f == posy : %f\n", data->player.pos_x, data->player.pos_y);
	if (data->move.right == 1)
	{
		if (data->map[(int)(data->player.pos_x + (data->player.dir_y * data->player.move_speed))][(int)data->player.pos_y] != '1')
			data->player.pos_x += data->player.dir_y * data->player.move_speed;
		if (data->map[(int)data->player.pos_x][(int)(data->player.pos_y + (data->player.dir_x * data->player.move_speed * 2))] != '1')
			data->player.pos_y += data->player.dir_x * data->player.move_speed;
	}
}

void	move_left(t_data *data)
{
	// printf("dirx : %f == diry : %f\n", data->player.dir_x, data->player.dir_y);
	// printf("posx : %f == posy : %f\n", data->player.pos_x, data->player.pos_y);
	if (data->move.left == 1)
	{
		if (data->map[(int)(data->player.pos_x - (data->player.dir_y * data->player.move_speed))][(int)data->player.pos_y] != '1')
			data->player.pos_x -= data->player.dir_y * data->player.move_speed;
		if (data->map[(int)data->player.pos_x][(int)(data->player.pos_y - (data->player.dir_x * data->player.move_speed * 2))] != '1')
			data->player.pos_y -= data->player.dir_x * data->player.move_speed;
	}
}

int	key_init(int keycode, t_data *data)
{
	if (keycode == 65307)
		ft_exit(data);
	if (keycode == 'w')
		data->move.up = 1;
	if (keycode == 's')
		data->move.down = 1;
	if (keycode == 'a')
		data->move.left = 1;
	if (keycode == 'd')
		data->move.right = 1;
	if (keycode == 65363)
		data->move.rr = 1;
	if (keycode == 65361)
		data->move.rl = 1;
	return (0);
}

int	key_reset(int keycode, t_data *data)
{
	if (keycode == 'w')
		data->move.up = 0;
	if (keycode == 's')
		data->move.down = 0;
	if (keycode == 'a')
		data->move.left = 0;
	if (keycode == 'd')
		data->move.right = 0;
	if (keycode == 65363)
		data->move.rr = 0;
	if (keycode == 65361)
		data->move.rl = 0;
	return (0);
}
