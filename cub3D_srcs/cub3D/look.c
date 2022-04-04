/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   look.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julien <julien@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 21:15:48 by julien            #+#    #+#             */
/*   Updated: 2022/04/04 21:33:30 by julien           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3D_include/cub3D.h"

void	look_right(t_data *data)
{
	mlx_clear_window(data->mlx, data->win2);
	mlx_clear_window(data->mlx, data->win);
	data->player.angle += 0.1;
	if (data->player.angle > 2 * PI)
		data->player.angle -= 2 * PI;
	data->player.dx = cos(data->player.angle) * 5;
	data->player.dy = sin(data->player.angle) * 5;
	draw_ray(data, data->map);

}

void	look_left(t_data *data)
{
	mlx_clear_window(data->mlx, data->win2);
	mlx_clear_window(data->mlx, data->win);
	data->player.angle -= 0.1;
	if (data->player.angle < 0)
		data->player.angle += 2 * PI;
	data->player.dx = cos(data->player.angle) * 5;
	data->player.dy = sin(data->player.angle) * 5;
	draw_ray(data, data->map);
}