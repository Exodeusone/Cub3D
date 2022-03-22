/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cub3d.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julien <julien@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 17:09:46 by julien            #+#    #+#             */
/*   Updated: 2022/03/22 18:55:22 by julien           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3D_include/cub3D.h"

int	ft_detect_img(t_data *data, char c)
{
	char	*check;
	int		ret;

	ret = 0;
	check = ft_strdup(data, "10NWES");
	while (check[ret])
	{
		if (check[ret] == c)
			return (ret);
		ret++;
	}
	return (0);
}

void	ft_mini_wall(t_data data)
{
	mlx_pixel_put(data.mlx, data.win, data.mini.coor.x, , 0x00F55550);
}

void	ft_putimg_ret(t_data *data, int ret)
{
	if (ret == 0)
		ft_mini_wall(*data);
	// else
	// 	ft_mini_floor(data);
}

void	ft_draw_mini_map(t_data *data)
{
	t_map	*map;
	int	i;
	int	j;
	int	ret;

	i = 0;
	map = data->map;
	while (map->next)
		map = map->next;
	while (map->map[i])
	{
		j = 0;
		while (map->map[i][j])
		{
			ret = ft_detect_img(data, map->map[i][j]);
			ft_putimg_ret(data, ret);
			data->mini.coor.x += data->mini.size_x;
			j++;
		}
		data->mini.coor.x = 1350;
		data->mini.coor.y += data->mini.size_y;
		i++;
	}
	data->mini.coor.x = 1350;
	data->mini.coor.y = 900;
}

void	ft_cub3d(t_data data)
{
	data.mlx = mlx_init();
	if (!data.mlx)
	{
		ft_puterr("Error\nNo environement\n");
		exit (1);
	}
	data.win = (mlx_new_window(data.mlx, 1500, 1000, "cub3D"));
	ft_draw_mini_map(&data);
	mlx_loop(data.mlx);
}