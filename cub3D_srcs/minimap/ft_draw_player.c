/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_player.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julien <julien@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 21:13:24 by julien            #+#    #+#             */
/*   Updated: 2022/04/04 21:30:06 by julien           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3D_include/cub3D.h"

void	ft_draw_player_front(t_data *data)
{
	int		i;
	int		j;
	float angle;
	float	dx;
	float	dy;

	angle = data->player.angle;
	dx = cos(angle);
	dy = sin(angle);
	i = 0;
	while (i < 3)
	{
		j = 0;
		while (j < 10)
		{
			data->asset[1].addr[(int)data->player.y * data->map_width * MAP_S + (int)data->player.x] = create_trgb(0, 0, 255, 0);
			data->player.x += dx;
			data->player.y += dy;
			j++;
		}
		data->player.x -= dx * 10;
		data->player.y -= dy * 10;
		data->player.y++;
		i++;
	}
	data->player.y -= i;
}

void	ft_draw_player_left(t_data *data)
{
	int		i;
	int		j;
	float angle;
	float	dx;
	float	dy;

	angle = data->player.angle - P2;
	if (angle < 0)
		angle += 2 * PI;
	dx = cos(angle);
	dy = sin(angle);
	i = 0;
	while (i < 3)
	{
		j = 0;
		while (j < 5)
		{
			data->asset[1].addr[(int)data->player.y * data->map_width * MAP_S + (int)data->player.x] = create_trgb(0, 0, 150, 150);
			data->player.x += dx;
			data->player.y += dy;
			j++;
		}
		data->player.x -= dx * 5;
		data->player.y -= dy * 5;
		data->player.y++;
		i++;
	}
	data->player.y -= i;
}

void	ft_draw_player_right(t_data *data)
{
	int		i;
	int		j;
	float angle;
	float	dx;
	float	dy;

	angle = data->player.angle + P2;
	if (angle > 2 * PI)
		angle -= 2 * PI;
	dx = cos(angle);
	dy = sin(angle);
	i = 0;
	while (i < 3)
	{
		j = 0;
		while (j < 5)
		{
			data->asset[1].addr[(int)data->player.y * data->map_width * MAP_S + (int)data->player.x] = create_trgb(0, 0, 150, 150);
			data->player.x += dx;
			data->player.y += dy;
			j++;
		}
		data->player.x -= dx * 5;
		data->player.y -= dy * 5;
		data->player.y++;
		i++;
	}
	data->player.y -= i;
}