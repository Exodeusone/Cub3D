/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julien <julien@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 11:05:20 by upean-de          #+#    #+#             */
/*   Updated: 2022/04/01 00:35:48 by julien           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3D_include/cub3D.h"

int	ft_exit(t_data *data)
{
	mlx_clear_window(data->mlx, data->win);
	mlx_clear_window(data->mlx, data->win2);
	mlx_destroy_window(data->mlx, data->win);
	mlx_destroy_window(data->mlx, data->win2);
	mlx_destroy_display(data->mlx);
	free(data->mlx);
	clear_garbage(data);
	exit (0);
}

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

void	ft_init_start_angle(t_data *data, char c)
{
	if (c == 'N')
		data->player.angle = P3;
	if (c == 'S')
		data->player.angle = P2;
	if (c == 'W')
		data->player.angle = PI;
	if (c == 'E')
		data->player.angle = 0;
}

void	get_coor(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	data->player.angle = 0;
	data->player.dx = cos(data->player.angle) * 5;
	data->player.dy = sin(data->player.angle) * 5;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			if (data->map[i][j] == 'N' || data->map[i][j] == 'S'
				|| data->map[i][j] == 'E' || data->map[i][j] == 'W')
			{
				data->player.x = j * MAP_S + 20;
				data->player.y = i * MAP_S + 20;
				ft_init_start_angle(data, data->map[i][j]);
				return ;
			}
			j++;
		}
		i++;
	}
}

void	init_minimap(t_data *data)
{
	data->mlx = mlx_init();
	if (!data->mlx)
	{
		clear_garbage(data);
		exit (0);
	}
	data->map_width -= 1;
	data->win2 = mlx_new_window(data->mlx, SCREEN_W, SCREEN_H, "Cub3d");
	data->win = mlx_new_window(data->mlx, data->map_width * MAP_S, data->map_height * MAP_S, "minimap");
	get_coor(data);
	init_assets(data);
	draw_map(data, data->map);
	draw_player(data);
	mlx_key_hook(data->win, &key_hook, data);
	mlx_key_hook(data->win2, &key_hook, data);
	mlx_hook(data->win, 17, 17, &ft_exit, data);
	mlx_hook(data->win2, 17, 17, &ft_exit, data);
	mlx_loop(data->mlx);
}
