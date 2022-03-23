/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: upean-de <upean-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 15:07:58 by upean-de          #+#    #+#             */
/*   Updated: 2022/03/23 16:10:02 by upean-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3D_include/cub3D.h"

void	move_up(t_data *data)
{
	erase_player(data);
	erase_direction(data);
	data->player.coor.x += data->player.coor.dx;
	data->player.coor.y += data->player.coor.dy;
	draw_player(data);
}

void	move_down(t_data *data)
{
	erase_player(data);
	erase_direction(data);
	data->player.coor.x -= data->player.coor.dx;
	data->player.coor.y -= data->player.coor.dy;
	draw_player(data);
}

void	move_right(t_data *data)
{
	erase_player(data);
	erase_direction(data);
	data->player.coor.angle += 0.1;
	if (data->player.coor.angle > 2 * PI)
		data->player.coor.angle -= 2 * PI;
	data->player.coor.dx = cos(data->player.coor.angle) * 5;
	data->player.coor.dy = sin(data->player.coor.angle) * 5;
	draw_player(data);
}

void	move_left(t_data *data)
{
	erase_player(data);
	erase_direction(data);
	data->player.coor.angle -= 0.1;
	if (data->player.coor.angle < 0)
		data->player.coor.angle += 2 * PI;
	data->player.coor.dx = cos(data->player.coor.angle) * 5;
	data->player.coor.dy = sin(data->player.coor.angle) * 5;
	draw_player(data);
}

int	key_hook(int keycode, t_data *data)
{
	if (keycode == 65307)
		ft_exit(data);
	if (keycode == 'w')
		move_up(data);
	if (keycode == 's')
		move_down(data);
	if (keycode == 'd')
		move_right(data);
	if (keycode == 'a')
		move_left(data);
	return (0);
}
