/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: upean-de <upean-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 15:07:58 by upean-de          #+#    #+#             */
/*   Updated: 2022/04/05 18:30:52 by upean-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3D_include/cub3D.h"

void	move_up(t_data *data)
{
	int	i;

	i = 0;
	mlx_clear_window(data->mlx, data->win);
	if (data->map[(int)(data->player.pos_x + (data->player.dir_x * data->player.move_speed))][(int)data->player.pos_y] != '1')
		data->player.pos_x += data->player.dir_x * data->player.move_speed;
	if (data->map[(int)data->player.pos_x][(int)(data->player.pos_y + (data->player.dir_y * data->player.move_speed * 2))] != '1')
		data->player.pos_y += data->player.dir_y * data->player.move_speed;
	draw_ray_2(data, data->map);
}

void	move_down(t_data *data)
{
	mlx_clear_window(data->mlx, data->win);
	if (data->map[(int)(data->player.pos_x - data->player.dir_x * data->player.move_speed)][(int)data->player.pos_y] != '1')
		data->player.pos_x -= data->player.dir_x * data->player.move_speed;
	if (data->map[(int)data->player.pos_x][(int)(data->player.pos_y - data->player.dir_y * data->player.move_speed)] != '1')
		data->player.pos_y -= data->player.dir_y * data->player.move_speed;
	draw_ray_2(data, data->map);
}

void	move_right(t_data *data)
{
	// printf("dirx : %f == diry : %f\n", data->player.dir_x, data->player.dir_y);
	mlx_clear_window(data->mlx, data->win);
	if (data->map[(int)(data->player.pos_x + (data->player.dir_y * data->player.move_speed))][(int)data->player.pos_y] != '1')
		data->player.pos_x += data->player.dir_y * data->player.move_speed;
	if (data->map[(int)data->player.pos_x][(int)(data->player.pos_y + (data->player.dir_x * data->player.move_speed * 2))] != '1')
		data->player.pos_y += data->player.dir_x * data->player.move_speed;
	draw_ray_2(data, data->map);
}

void	move_left(t_data *data)
{
	// printf("dirx : %f == diry : %f\n", data->player.dir_x, data->player.dir_y);
	// printf("posx : %f == posy : %f\n", data->player.pos_x, data->player.pos_y);
	mlx_clear_window(data->mlx, data->win);
	if (data->map[(int)(data->player.pos_x - (data->player.dir_y * data->player.move_speed))][(int)data->player.pos_y] != '1')
		data->player.pos_x -= data->player.dir_y * data->player.move_speed;
	if (data->map[(int)data->player.pos_x][(int)(data->player.pos_y - (data->player.dir_x * data->player.move_speed * 2))] != '1')
		data->player.pos_y -= data->player.dir_x * data->player.move_speed;
	draw_ray_2(data, data->map);
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
