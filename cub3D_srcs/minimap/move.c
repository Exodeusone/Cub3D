/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: upean-de <upean-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 15:07:58 by upean-de          #+#    #+#             */
/*   Updated: 2022/03/28 18:41:38 by upean-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3D_include/cub3D.h"

void	move_up(t_data *data)
{
	if (ok_move_up(data) == 0)
	{
		ft_clean_cleaner(data);
		erase_player(data);
		data->player.x += data->player.dx;
		data->player.y += data->player.dy;
		draw_player(data);
	}
}

void	move_down(t_data *data)
{
	ft_clean_cleaner(data);
	erase_player(data);
	data->player.x -= data->player.dx;
	data->player.y -= data->player.dy;
	draw_player(data);
}

void	move_right(t_data *data)
{
	ft_clean_cleaner(data);
	erase_player(data);
	data->player.angle += 0.1;
	if (data->player.angle > 2 * PI)
		data->player.angle -= 2 * PI;
	data->player.dx = cos(data->player.angle) * 5;
	data->player.dy = sin(data->player.angle) * 5;
	draw_player(data);

}

void	move_left(t_data *data)
{
	ft_clean_cleaner(data);
	erase_player(data);
	data->player.angle -= 0.1;
	if (data->player.angle < 0)
		data->player.angle += 2 * PI;
	data->player.dx = cos(data->player.angle) * 5;
	data->player.dy = sin(data->player.angle) * 5;
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
