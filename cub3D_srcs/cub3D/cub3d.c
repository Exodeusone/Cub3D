/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: upean-de <upean-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 21:00:42 by julien            #+#    #+#             */
/*   Updated: 2022/04/06 11:43:33 by upean-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3D_include/cub3D.h"

void	move_init(t_data *data)
{
	data->move.up = 0;
	data->move.down = 0;
	data->move.right = 0;
	data->move.left = 0;
	data->move.rr = 0;
	data->move.rl = 0;
}

void	cub3d(t_data *data)
{
	data->mlx = mlx_init();
	if (!data->mlx)
	{
		clear_garbage(data);
		exit (0);
	}
	data->map_width -= 1;
	data->win = mlx_new_window(data->mlx, SCREEN_W, SCREEN_H, "Cub3d");
	// data->win2 = mlx_new_window(data->mlx, data->map_width
	// 		* MAP_S, data->map_height * MAP_S, "minimap");
	move_init(data);
	get_coor(data);
	init_assets(data);
	// draw_map(data, data->map);
	// draw_ray_2(data, data->map);
	mlx_hook(data->win, 2, 1L << 0, &key_init, data);
	// mlx_key_hook(data->win2, &key_hook, data);
	mlx_hook(data->win, 17, 17, &ft_exit, data);
	mlx_loop_hook(data->mlx, &draw_ray_2, data);
	mlx_hook(data->win, 3, 1L << 1, &key_reset, data);
	// mlx_hook(data->win2, 17, 17, &ft_exit, data);
	mlx_loop(data->mlx);
}
