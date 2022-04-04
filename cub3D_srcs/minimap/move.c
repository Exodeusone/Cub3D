/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: upean-de <upean-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 15:07:58 by upean-de          #+#    #+#             */
/*   Updated: 2022/04/04 14:02:26 by upean-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3D_include/cub3D.h"

void	move_up(t_data *data)
{
	if (ok_move_up(data) == 0)
	{
		mlx_clear_window(data->mlx, data->win2);
		mlx_clear_window(data->mlx, data->win);
		data->player.x += data->player.dx;
		data->player.y += data->player.dy;
		draw_player(data);
	}
}

void	move_down(t_data *data)
{
	if (ok_move_down(data) == 0)
	{
		mlx_clear_window(data->mlx, data->win2);
		mlx_clear_window(data->mlx, data->win);
		data->player.x -= data->player.dx;
		data->player.y -= data->player.dy;
		draw_player(data);
	}
}

void	move_right(t_data *data)
{
	float	angle;
	float	dx;
	float	dy;

	angle = data->player.angle + P2;
	if (angle > 2 * PI)
		angle -= 2 * PI;
	dx = cos(angle) * 5;
	dy = sin(angle) * 5;
	if (ok_move_side(data, dx, dy) == 0)
	{
		mlx_clear_window(data->mlx, data->win2);
		mlx_clear_window(data->mlx, data->win);
		data->player.x += dx;
		data->player.y += dy;
		draw_player(data);
	}
}

void	move_left(t_data *data)
{
	float	angle;
	float	dx;
	float	dy;

	angle = data->player.angle - P2;
	if (angle < 0)
		angle += 2 * PI;
	dx = cos(angle) * 5;
	dy = sin(angle) * 5;
	if (ok_move_side(data, dx, dy) == 0)
	{
		mlx_clear_window(data->mlx, data->win2);
		mlx_clear_window(data->mlx, data->win);
		data->player.x += dx;
		data->player.y += dy;
		draw_player(data);
	}
}

void	look_right(t_data *data)
{
	mlx_clear_window(data->mlx, data->win2);
	mlx_clear_window(data->mlx, data->win);
	data->player.angle += 0.1;
	if (data->player.angle > 2 * PI)
		data->player.angle -= 2 * PI;
	data->player.dx = cos(data->player.angle) * 5;
	data->player.dy = sin(data->player.angle) * 5;
	draw_player(data);

}

void	look_left(t_data *data)
{
	mlx_clear_window(data->mlx, data->win2);
	mlx_clear_window(data->mlx, data->win);
	data->player.angle -= 0.1;
	if (data->player.angle < 0)
		data->player.angle += 2 * PI;
	data->player.dx = cos(data->player.angle) * 5;
	data->player.dy = sin(data->player.angle) * 5;
	draw_player(data);
}

int	key_hook(int keycode, t_data *data)
{
	init_assets(data);
	draw_map(data, data->map);
	if (keycode == 65307)
		ft_exit(data);
	if (keycode == 'w')
		move_up(data);
	if (keycode == 's')
		move_down(data);
	if (keycode == 'a')
		move_left(data);
	if (keycode == 'd')
		move_right(data);
	if (keycode == 65363)
		look_right(data);
	if (keycode == 65361)
		look_left(data);
	return (0);
}
