/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: upean-de <upean-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 10:18:22 by upean-de          #+#    #+#             */
/*   Updated: 2022/04/06 14:58:21 by upean-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3D_include/cub3D.h"

void	draw_ceiling(t_data *data, int x)
{
	int	y;

	y = 0;
	while (y < data->display.draw_start - 1)
	{
		data->asset[0].addr[y * SCREEN_W + x] = create_trgb(0, data->cell.red,
				data->cell.green, data->cell.blue);
		y++;
	}
}

void	draw_floor(t_data *data, int x)
{
	int	y;

	y = data->display.draw_end + 1;
	while (y < SCREEN_H)
	{
		data->asset[0].addr[y * SCREEN_W + x] = create_trgb(0, data->floor.red,
				data->floor.green, data->floor.blue);
		y++;
	}
}

int	ft_init_draw_ray(t_data *data)
{
	data->player.move_speed = 0.1 / 1.5;
	data->player.rot_speed = 0.033 * 1.8 / 1.3;
	return (0);
}

void	ft_init_loop_ray(t_data *data, int x)
{
	float	camera_x;

	camera_x = 2 * x / (float)SCREEN_W - 1;
	data->player.ray_dir_x = data->player.dir_x + data->player.plane_x
		* camera_x;
	data->player.ray_dir_y = data->player.dir_y + data->player.plane_y
		* camera_x;
	data->player.map_x = (int)data->player.pos_x;
	data->player.map_y = (int)data->player.pos_y;
}

int	draw_ray(t_data *data)
{
	int		x;
	int		y;

	x = ft_init_draw_ray(data);
	while (x < SCREEN_W)
	{
		ft_init_loop_ray(data, x);
		data->player.hit = ft_draw_ray2(data);
		ft_draw_ray3(data);
		ft_draw_ray4(data);
		ft_draw_ray5(data);
		draw_ceiling(data, x);
		y = ft_draw_ray6(data);
		ft_draw_ray7(data, y, x);
		draw_floor(data, x);
		x++;
	}
	mlx_put_image_to_window(data->mlx, data->win, data->asset[0].img, 0, 0);
	move(data);
	return (0);
}
