/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julien <julien@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 21:00:42 by julien            #+#    #+#             */
/*   Updated: 2022/04/04 22:56:57 by julien           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3D_include/cub3D.h"

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
	data->win2 = mlx_new_window(data->mlx, data->map_width
			* MAP_S, data->map_height * MAP_S, "minimap");
	get_coor(data);
	init_assets(data);
	draw_map(data, data->map);
	draw_ray(data, data->map);
	mlx_key_hook(data->win, &key_hook, data);
	mlx_key_hook(data->win2, &key_hook, data);
	mlx_hook(data->win, 17, 17, &ft_exit, data);
	mlx_hook(data->win2, 17, 17, &ft_exit, data);
	mlx_loop(data->mlx);
}
