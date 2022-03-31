/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: upean-de <upean-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 15:12:43 by upean-de          #+#    #+#             */
/*   Updated: 2022/03/31 17:22:33 by upean-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3D_include/cub3D.h"

void	erase_direction(t_data *data, t_cleaner *tmp)
{
	float	x;
	float	y;
	float	newdx;
	float	newdy;

	x = tmp->x;
	y = tmp->y;
	newdx = cos(tmp->ra) * 5;
	newdy = sin(tmp->ra) * 5;
	if (y > tmp->ry && (tmp->dy > 0.000003 || tmp->dy < -0.000003))
	{
		while (y > tmp->ry)
		{
			mlx_pixel_put(data->mlx, data->win, x, y, create_trgb(0, 0, 0, 0));
			x += newdx / 5;
			y += newdy / 5;
		}
		return ;
	}
	if (y < tmp->ry && (tmp->dy > 0.000003 || tmp->dy < -0.000003))
	{
		while (y < tmp->ry)
		{
			mlx_pixel_put(data->mlx, data->win, x, y, create_trgb(0, 0, 0, 0));
			x += newdx / 5;
			y += newdy / 5;
		}
		return ;
	}
}

void	erase_player(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (i < 10)
	{
		j = 0;
		while (j < 10)
		{
			mlx_pixel_put(data->mlx, data->win, data->player.x, data->player.y, create_trgb(0, 0, 0, 0));
			data->player.x++;
			j++;
		}
		data->player.x -= j;
		data->player.y++;
		i++;
	}
	data->player.y -= j;
}

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
			// mlx_pixel_put(data->mlx, data->win, x, y, create_trgb(0, 255, 0, 0));
			x += newdx;
			y += newdy;
		}
		return ;
	}
	if (y < data->player.ry && (data->player.dy > 0.000003 || data->player.dy < -0.000003))
	{
		while (y < data->player.ry)
		{
			data->asset[1].addr[(int)y * data->map_width * MAP_S + (int)x] = create_trgb(0, 255, 0, 0);
			// mlx_pixel_put(data->mlx, data->win, x, y, create_trgb(0, 255, 0, 0));
			x += newdx;
			y += newdy;
		}
		return ;
	}
}

void	draw_player(t_data *data)
{
	int		i;
	int		j;

	t_map	*tmp;
	tmp = data->map;
	i = 0;
	while (i < 10)
	{
		j = 0;
		while (j < 10)
		{
			data->asset[1].addr[(int)data->player.y * data->map_width * MAP_S + (int)data->player.x] = create_trgb(0, 255, 0, 0);
			// mlx_pixel_put(data->mlx, data->win, data->player.x, data->player.y, create_trgb(0, 255, 0, 0));
			data->player.x++;
			j++;
		}
		data->player.x -= j;
		data->player.y++;
		i++;
	}
	data->player.y -= j;
	while (tmp->map == NULL)
		tmp = tmp->next;
	draw_ray(data, tmp->map);
}
