/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_3d.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: upean-de <upean-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 10:10:24 by upean-de          #+#    #+#             */
/*   Updated: 2022/03/31 16:37:33 by upean-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3D_include/cub3D.h"

void	draw_ceiling(t_data *data, int y_start, int x_start, int x_end)
{
	int	y;
	int	x;

	y = 0;
	while (y != y_start)
	{
		x = x_start;
		while (x != x_end)
		{
			data->asset[0].addr[y * SCREEN_H + x] = create_trgb(0, 0, 0, 100);
			// mlx_pixel_put(data->mlx, data->win2, x, y, create_trgb(0, 0, 0, 100));
			x++;
		}
		y++;
	}
}

void	draw_floor(t_data *data, int y_end, int x_start, int x_end)
{
	int	y;
	int	x;

	y = y_end;
	while (y != SCREEN_H)
	{
		x = x_start;
		while (x != x_end)
		{
			data->asset[0].addr[y * SCREEN_H + x] = create_trgb(0, 100, 100, 100);
			// mlx_pixel_put(data->mlx, data->win2, x, y, create_trgb(0, 100, 100, 100));
			x++;
		}
		y++;
	}
}

void	draw_3d(t_data *data, int r, int r_limit)
{
	int	line_height;
	int	line_width;
	int	y_start;
	int	y_end;
	int	x_start;
	int	x_end;
	int	x;
	int	y;

	r--;
	line_height = (int)SCREEN_H / data->player.disT + 4000 / data->player.disT;
	y_start = ((-line_height) / 2 + SCREEN_H / 2);
	if (y_start < 0)
		y_start = 0;
	y_end = ((line_height) / 2 + SCREEN_H / 2);
	if (y_end >= SCREEN_H)
		y_end = SCREEN_H - 1;
	line_width = SCREEN_W / r_limit;
	x_start = r * line_width;
	x_end = x_start + line_width;
	draw_ceiling(data, y_start, x_start, x_end);
	draw_floor(data, y_end, x_start, x_end);
	x = x_start;
	y = y_start;
	while (y != y_end)
	{
		x = x_start;
		while (x != x_end)
		{
			if (data->player.side == 0)
				data->asset[0].addr[y * SCREEN_H + x] = create_trgb(0, 255, 0, 0);
				// mlx_pixel_put(data->mlx, data->win2, x, y, create_trgb(0, 255, 0, 0));
			else
				data->asset[0].addr[y * SCREEN_H + x] = create_trgb(0, 127, 0, 0);
				// mlx_pixel_put(data->mlx, data->win2, x, y, create_trgb(0, 127, 0, 0));
			x++;
		}
		y++;
	}
}
