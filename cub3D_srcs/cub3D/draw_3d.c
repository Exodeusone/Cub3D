/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_3d.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: upean-de <upean-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 10:10:24 by upean-de          #+#    #+#             */
/*   Updated: 2022/04/05 17:51:09 by upean-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3D_include/cub3D.h"

int	get_color(t_data *data)
{
	int	color;

	data->display.tex_y = (int)data->display.tex_pos & 63;
	data->display.tex_pos += data->display.step;
	if (data->player.side == 0)
	{
		if (data->player.ra > PI)
			color = data->asset[2].addr[(64 * data->display.tex_y / 4 + data->display.tex_x)]; // NORD
		else
			color = data->asset[3].addr[(64 * data->display.tex_y / 4 + data->display.tex_x)]; // SUD
	}
	else
	{
		if (data->player.ra > P2 && data->player.ra < P3)
			color = data->asset[4].addr[(64 * data->display.tex_y + data->display.tex_x) / 4]; // OUEST
		else
			color = data->asset[5].addr[(64 * data->display.tex_y + data->display.tex_x) / 4]; // EST
	}
	return (color);
}

// void	draw_ceiling(t_data *data)
// {
// 	int	y;
// 	int	x;

// 	y = 0;
// 	while (y != data->display.y_start)
// 	{
// 		x = data->display.x_start;
// 		while (x != data->display.x_end)
// 		{
// 			data->asset[0].addr[y * SCREEN_H + x] = create_trgb(0, data->cell.red, data->cell.green, data->cell.blue);
// 			x++;
// 		}
// 		y++;
// 	}
// }

// void	draw_floor(t_data *data)
// {
// 	int	y;
// 	int	x;

// 	y = data->display.y_end;
// 	while (y != SCREEN_H)
// 	{
// 		x = data->display.x_start;
// 		while (x != data->display.x_end)
// 		{
// 			data->asset[0].addr[y * SCREEN_H + x] = create_trgb(0, data->floor.red, data->floor.green, data->floor.blue);
// 			x++;
// 		}
// 		y++;
// 	}
// }

// void	draw_3d(t_data *data, int r, int r_limit)
// {
// 	int	line_height;
// 	int	line_width;

// 	r--;
// 	line_height = (int)SCREEN_H / data->player.disT + 50000 / data->player.disT;
// 	data->display.y_start = ((-line_height) / 2 + SCREEN_H / 2);
// 	if (data->display.y_start < 0)
// 		data->display.y_start = 0;
// 	data->display.y_end = ((line_height) / 2 + SCREEN_H / 2);
// 	if (data->display.y_end >= SCREEN_H)
// 		data->display.y_end = SCREEN_H - 1;
// 	line_width = SCREEN_W / r_limit;
// 	data->display.x_start = r * line_width;
// 	data->display.x_end = data->display.x_start + line_width;
// 	draw_ceiling(data);
// 	draw_floor(data);
// 	data->display.x = data->display.x_start;
// 	data->display.x = data->display.x_start;
// 	data->display.y = data->display.y_start;
// 	if (data->player.side == 0)
// 		data->display.wall_x = data->player.rx;
// 	else
// 		data->display.wall_x = data->player.ry;
// 	data->display.wall_x -= floor(data->display.wall_x);
// 	data->display.tex_x = (int)(data->display.wall_x * 64.f);
// 	data->display.step = 1.0 * 64 / line_height;
// 	data->display.tex_pos = (data->display.y_start - SCREEN_H / 2 + line_height / 2) * data->display.step;
// 	while (data->display.y != data->display.y_end)
// 	{
// 		data->display.x = data->display.x_start;
// 		while (data->display.x != data->display.x_end)
// 		{
// 			data->asset[0].addr[data->display.y * SCREEN_H + data->display.x] = get_color(data);
// 			data->display.x++;
// 		}
// 		data->display.y++;
// 	}
// }
