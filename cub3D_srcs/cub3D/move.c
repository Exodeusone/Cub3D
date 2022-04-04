/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julien <julien@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 15:07:58 by upean-de          #+#    #+#             */
/*   Updated: 2022/04/04 21:16:48 by julien           ###   ########.fr       */
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
		draw_ray(data, data->map);
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
		draw_ray(data, data->map);
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
		draw_ray(data, data->map);
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
		draw_ray(data, data->map);
	}
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
