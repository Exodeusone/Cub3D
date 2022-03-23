/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: upean-de <upean-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 11:05:20 by upean-de          #+#    #+#             */
/*   Updated: 2022/03/23 15:54:12 by upean-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3D_include/cub3D.h"

int	ft_exit(t_data *data)
{
	mlx_clear_window(data->mlx, data->win);
	mlx_destroy_window(data->mlx, data->win);
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
	data->player.coor.angle = 0;
	data->player.coor.dx = cos(data->player.coor.angle) * 5;
	data->player.coor.dy = sin(data->player.coor.angle) * 5;
	while (tmp->map[i])
	{
		j = 0;
		while (tmp->map[i][j])
		{
			if (tmp->map[i][j] == 'N' || tmp->map[i][j] == 'S'
				|| tmp->map[i][j] == 'E' || tmp->map[i][j] == 'W')
			{
				data->player.coor.x = j * 50 + 20;
				data->player.coor.y = i * 50 + 20;
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
	data->win = mlx_new_window(data->mlx, ft_strlen(tmp->map[0]) * 50, ft_strslen(tmp->map) * 50, "Cub3d");
	get_coor(data, tmp);

	mlx_key_hook(data->win, &key_hook, data);
	mlx_hook(data->win, 17, 17, &ft_exit, data);
	draw_map(data, tmp->map);
	draw_player(data);
	mlx_loop(data->mlx);
}
