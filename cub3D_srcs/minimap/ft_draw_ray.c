/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julien <julien@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 15:12:43 by upean-de          #+#    #+#             */
/*   Updated: 2022/04/04 21:17:06 by julien           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3D_include/cub3D.h"

void	draw_direction(t_data *data)
{
	float	x;
	float	y;
	float	newdx;
	float	newdy;

	x = data->player.x;
	y = data->player.y;
	newdx = cos(data->player.ra);
	newdy = sin(data->player.ra);
	if (y > data->player.ry && (data->player.dy > 0.000003 || data->player.dy < -0.000003))
	{
		while (y > data->player.ry)
		{
			data->asset[1].addr[(int)y * data->map_width * MAP_S + (int)x] = create_trgb(0, 255, 0, 0);
			x += newdx;
			y += newdy;
		}
		return ;
	}
	else if (y < data->player.ry && (data->player.dy > 0.000003 || data->player.dy < -0.000003))
	{
		while (y < data->player.ry)
		{
			data->asset[1].addr[(int)y * data->map_width * MAP_S + (int)x] = create_trgb(0, 255, 0, 0);
			x += newdx;
			y += newdy;
		}
		return ;
	}
	else	
	{
		if (newdy < 0)
		{
			newdy *= -1.f;
			while (y > data->player.ry)
			{
				data->asset[1].addr[(int)y * data->map_width * MAP_S + (int)x] = create_trgb(0, 255, 0, 0);
				x += newdx;
				y -= newdy;
			}
			return ;
		}
		while (y < data->player.ry)
		{
			data->asset[1].addr[(int)y * data->map_width * MAP_S + (int)x] = create_trgb(0, 255, 0, 0);
			x += newdx;
			y += newdy;
		}
		return ;
	}
}
