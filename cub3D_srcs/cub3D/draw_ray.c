/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_ray.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: upean-de <upean-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 10:11:44 by upean-de          #+#    #+#             */
/*   Updated: 2022/04/05 19:14:15 by upean-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3D_include/cub3D.h"

void	draw_ceiling(t_data *data, int x)
{
	int	y;

	y = 0;
	while (y < data->display.draw_start - 1)
	{
		data->asset[0].addr[y * SCREEN_W + x] = create_trgb(0, data->cell.red, data->cell.green, data->cell.blue);
		y++;
	}
}

void	draw_floor(t_data *data, int x)
{
	int	y;

	y = data->display.draw_end + 1;
	while (y < SCREEN_H)
	{
		data->asset[0].addr[y * SCREEN_W + x] = create_trgb(0, data->floor.red, data->floor.green, data->floor.blue);
		y++;
	}
}

void	draw_ray_2(t_data *data, char **map)
{
	int 	x;
	int		y;
	float	camera_x;

	x = 0;
	data->time = 0;
	data->old_time = 0;
	data->player.move_speed = 0.1;
	data->player.rot_speed = 0.033 * 1.8;
	while (x < SCREEN_W)
	{
		camera_x = 2 * x / (float)SCREEN_W - 1;
		data->player.ray_dir_x = data->player.dir_x + data->player.plane_x * camera_x;
		data->player.ray_dir_y = data->player.dir_y + data->player.plane_y * camera_x;
		data->player.map_x = (int)data->player.pos_x;
		data->player.map_y = (int)data->player.pos_y;
		// printf("camera_x %f == raydirx %f == dirx %f == planx %f == posx %f\n", camera_x, data->player.ray_dir_x, data->player.dir_x, data->player.plane_x, data->player.pos_x);
		if (data->player.ray_dir_y == 0)
			data->player.delta_dist_x = 0;
		else if (data->player.ray_dir_x == 0)
			data->player.delta_dist_x = 1;
		else
			data->player.delta_dist_x = sqrt(1 + (data->player.ray_dir_y
			* data->player.ray_dir_y) / (data->player.ray_dir_x *
			data->player.ray_dir_x));
		if (data->player.ray_dir_x == 0)
			data->player.delta_dist_y = 0;
		else if (data->player.ray_dir_y == 0)
			data->player.delta_dist_y = 1;
		else
			data->player.delta_dist_y = sqrt(1 + (data->player.ray_dir_x
			* data->player.ray_dir_x) / (data->player.ray_dir_y *
			data->player.ray_dir_y));
		data->player.hit = 0;
		if (data->player.ray_dir_x < 0)
		{
			data->player.step_x = -1;
			data->player.side_dist_x = (data->player.pos_x - data->player.map_x) * data->player.delta_dist_x;
		}
		else
		{
			data->player.step_x = 1;
			data->player.side_dist_x = (data->player.map_x + 1.0 - data->player.pos_x) * data->player.delta_dist_x;
		}
		if (data->player.ray_dir_y < 0)
		{
			data->player.step_y = -1;
			data->player.side_dist_y = (data->player.pos_y - data->player.map_y) * data->player.delta_dist_y;
		}
		else
		{
			data->player.step_y = 1;
			data->player.side_dist_y = (data->player.map_y + 1.0 - data->player.pos_y) * data->player.delta_dist_y;
		}
		while (data->player.hit == 0)
		{
			if (data->player.side_dist_x < data->player.side_dist_y)
			{
				data->player.side_dist_x += data->player.delta_dist_x;
				data->player.map_x += data->player.step_x;
				data->player.side = 0;
			}
			else
			{
				data->player.side_dist_y += data->player.delta_dist_y;
				data->player.map_y += data->player.step_y;
				data->player.side = 1;
			}
			if (map[data->player.map_x][data->player.map_y] == '1')
				data->player.hit = 1;
		}
		if (data->player.side == 0)
			data->player.perp_wall_dist = ((float)data->player.map_x - data->player.pos_x + (1 - (float)data->player.step_x) / 2) / data->player.ray_dir_x;
		else
			data->player.perp_wall_dist = ((float)data->player.map_y - data->player.pos_y + (1 - (float)data->player.step_y) / 2) / data->player.ray_dir_y;
		data->display.line_height = (int)(SCREEN_H / data->player.perp_wall_dist);
		data->display.draw_start = -data->display.line_height / 2 + SCREEN_H / 2;
		if (data->display.draw_start < 0)
			data->display.draw_start = 0;
		data->display.draw_end = data->display.line_height / 2 + SCREEN_H / 2;
		if (data->display.draw_end >= SCREEN_H || data->display.draw_end < 0)
			data->display.draw_end = SCREEN_H - 1;
		draw_ceiling(data, x);
		y = data->display.draw_start;
		// printf("y %d == x %d == pixel %d == start %d == end %d == line_height %d\n", y, x, y * SCREEN_W + x, data->display.draw_start, data->display.draw_end, data->display.line_height);
		// printf("map_y %f == pos_y %f == step_y %f == ray_dir_y %f\n", (float)data->player.map_x, data->player.pos_y, (float)data->player.step_y, data->player.ray_dir_y);
		// printf("perpwalldist : %f\n", data->player.perp_wall_dist);
		if(data->player.side == 0)
			data->display.wall_x = data->player.pos_y + data->display.perp_wall_dist * data->display.ray_dir_y;
		else
			data->display.wall_x = data->player.pos_x + data->display.perp_wall_dist * data->display.ray_dir_x;
		data->display.wall_x -= floor((data->display.wall_x));
		data->display.tex_x = (int)(data->display.wall_x * data);
		data->display.step = 1.0 * 64 / line_height;
		data->display.tex_pos = (data->display.y_start - SCREEN_H / 2 + line_height / 2) * data->display.step;
		while (y < data->display.draw_end)
		{
			if (data->player.side == 1)
				data->asset[0].addr[y * SCREEN_W + x] = create_trgb(0, 127, 0, 0);
			else
				data->asset[0].addr[y * SCREEN_W + x] = create_trgb(0, 255, 0, 0);
			y++;
		}
		draw_floor(data, x);
		x++;
	}
	mlx_put_image_to_window(data->mlx, data->win, data->asset[0].img, 0, 0);
	mlx_destroy_image(data->mlx, data->asset[0].img);
}
