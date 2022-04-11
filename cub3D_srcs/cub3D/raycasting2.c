/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: upean-de <upean-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 14:37:22 by upean-de          #+#    #+#             */
/*   Updated: 2022/04/06 14:55:02 by upean-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3D_include/cub3D.h"

int	ft_draw_ray2(t_data *data)
{
	if (data->player.ray_dir_y == 0)
		data->player.delta_dist_x = 0;
	else if (data->player.ray_dir_x == 0)
		data->player.delta_dist_x = 1;
	else
		data->player.delta_dist_x = sqrt(1 + (data->player.ray_dir_y
					* data->player.ray_dir_y) / (data->player.ray_dir_x
					* data->player.ray_dir_x));
	if (data->player.ray_dir_x == 0)
		data->player.delta_dist_y = 0;
	else if (data->player.ray_dir_y == 0)
		data->player.delta_dist_y = 1;
	else
		data->player.delta_dist_y = sqrt(1 + (data->player.ray_dir_x
					* data->player.ray_dir_x) / (data->player.ray_dir_y
					* data->player.ray_dir_y));
	return (0);
}

void	ft_draw_ray3(t_data *data)
{
	if (data->player.ray_dir_x < 0)
	{
		data->player.step_x = -1;
		data->player.side_dist_x = (data->player.pos_x - data->player.map_x)
			* data->player.delta_dist_x;
	}
	else
	{
		data->player.step_x = 1;
		data->player.side_dist_x = (data->player.map_x + 1.0
				- data->player.pos_x) * data->player.delta_dist_x;
	}
	if (data->player.ray_dir_y < 0)
	{
		data->player.step_y = -1;
		data->player.side_dist_y = (data->player.pos_y
				- data->player.map_y) * data->player.delta_dist_y;
	}
	else
	{
		data->player.step_y = 1;
		data->player.side_dist_y = (data->player.map_y
				+ 1.0 - data->player.pos_y) * data->player.delta_dist_y;
	}
}

void	ft_draw_ray4(t_data *data)
{
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
		if (data->map[data->player.map_x][data->player.map_y] == '1')
			data->player.hit = 1;
	}
}

void	ft_draw_ray5(t_data *data)
{
	if (data->player.side == 0)
		data->player.perp_wall_dist = ((float)data->player.map_x
				- data->player.pos_x + (1 - (float)data->player.step_x) / 2)
			/ data->player.ray_dir_x;
	else
		data->player.perp_wall_dist = ((float)data->player.map_y
				- data->player.pos_y + (1 - (float)data->player.step_y) / 2)
			/ data->player.ray_dir_y;
	data->display.line_height = (int)(SCREEN_H / data->player.perp_wall_dist);
	data->display.draw_start = -data->display.line_height / 2 + SCREEN_H / 2;
	if (data->display.draw_start < 0)
		data->display.draw_start = 0;
	data->display.draw_end = data->display.line_height / 2 + SCREEN_H / 2;
	if (data->display.draw_end >= SCREEN_H || data->display.draw_end < 0)
		data->display.draw_end = SCREEN_H - 1;
}

int	ft_draw_ray6(t_data *data)
{
	if (data->player.side == 0 && data->player.ray_dir_x < 0)
		data->display.tex_dir = 1;
	if (data->player.side == 0 && data->player.ray_dir_x >= 0)
		data->display.tex_dir = 2;
	if (data->player.side == 1 && data->player.ray_dir_y < 0)
		data->display.tex_dir = 3;
	if (data->player.side == 1 && data->player.ray_dir_y >= 0)
		data->display.tex_dir = 4;
	if (data->player.side == 0)
		data->display.wall_x = data->player.pos_y
			+ data->player.perp_wall_dist * data->player.ray_dir_y;
	else
		data->display.wall_x = data->player.pos_x
			+ data->player.perp_wall_dist * data->player.ray_dir_x;
	data->display.wall_x -= floor((data->display.wall_x));
	data->display.tex_x = (int)(data->display.wall_x
			* (float)data->asset[data->display.tex_dir].width);
	data->display.step = 1.0
		* data->asset[data->display.tex_dir].height
		/ data->display.line_height;
	data->display.tex_pos = (data->display.draw_start
			- SCREEN_H / 2 + data->display.line_height / 2)
		* data->display.step;
	return (data->display.draw_start);
}
