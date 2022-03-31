/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: upean-de <upean-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 11:05:20 by upean-de          #+#    #+#             */
/*   Updated: 2022/03/31 16:33:24 by upean-de         ###   ########.fr       */
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

void	get_coor(t_data *data, t_map *tmp)
{
	int	i;
	int	j;

	i = 0;
	data->player.angle = 0;
	data->player.dx = cos(data->player.angle) * 5;
	data->player.dy = sin(data->player.angle) * 5;
	while (tmp->map[i])
	{
		j = 0;
		while (tmp->map[i][j])
		{
			if (tmp->map[i][j] == 'N' || tmp->map[i][j] == 'S'
				|| tmp->map[i][j] == 'E' || tmp->map[i][j] == 'W')
			{
				data->player.x = j * MAP_S + 20;
				data->player.y = i * MAP_S + 20;
				return ;
			}
			j++;
		}
		i++;
	}
}

void	init_minimap(t_data *data)
{
	t_map	*tmp;

	tmp = data->map;
	data->mlx = mlx_init();
	if (!data->mlx)
	{
		clear_garbage(data);
		exit (0);
	}
	while (tmp->map == NULL)
		tmp = tmp->next;
	data->map_width -= 1;
	data->win2 = mlx_new_window(data->mlx, SCREEN_W, SCREEN_H, "Cub3d");
	data->win = mlx_new_window(data->mlx, data->map_width * MAP_S, data->map_height * MAP_S, "minimap");
	get_coor(data, tmp);
	mlx_key_hook(data->win, &key_hook, data);
	mlx_key_hook(data->win2, &key_hook, data);
	mlx_hook(data->win, 17, 17, &ft_exit, data);
	mlx_hook(data->win2, 17, 17, &ft_exit, data);
	init_assets(data);
	draw_map(data, tmp->map);
	draw_player(data);
	mlx_loop(data->mlx);
}
