/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: upean-de <upean-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 15:12:43 by upean-de          #+#    #+#             */
/*   Updated: 2022/03/23 15:31:45 by upean-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3D_include/cub3D.h"

void	erase_direction(t_data *data)
{
	float	x;
	float	y;
	int		i;

	i = 0;
	x = data->player.coor.x + 5;
	y = data->player.coor.y + 5;
	while (i < 30)
	{
		mlx_pixel_put(data->mlx, data->win, x, y, create_trgb(0, 0, 0, 0));
		x += data->player.coor.dx / 5;
		y += data->player.coor.dy / 5;
		i++;
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
			mlx_pixel_put(data->mlx, data->win, data->player.coor.x, data->player.coor.y, create_trgb(0, 0, 0, 0));
			data->player.coor.x++;
			j++;
		}
		data->player.coor.x -= j;
		data->player.coor.y++;
		i++;
	}
	data->player.coor.y -= j;
}

void	draw_direction(t_data *data)
{
	float	x;
	float	y;
	int		i;

	x = data->player.coor.x + 5;
	y = data->player.coor.y + 5;
	i = 0;
	while (i < 30)
	{
		mlx_pixel_put(data->mlx, data->win, x, y, create_trgb(0, 255, 0, 0));
		x += data->player.coor.dx / 5;
		y += data->player.coor.dy / 5;
		i++;
	}
}

void	draw_player(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (i < 10)
	{
		j = 0;
		while (j < 10)
		{
			mlx_pixel_put(data->mlx, data->win, data->player.coor.x, data->player.coor.y, create_trgb(0, 255, 0, 0));
			data->player.coor.x++;
			j++;
		}
		data->player.coor.x -= j;
		data->player.coor.y++;
		i++;
	}
	data->player.coor.y -= j;
	draw_direction(data);
}
