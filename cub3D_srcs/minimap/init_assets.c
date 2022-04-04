/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_assets.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: upean-de <upean-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 14:39:01 by upean-de          #+#    #+#             */
/*   Updated: 2022/04/04 15:40:29 by upean-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3D_include/cub3D.h"

void	init_assets(t_data *data)
{
	data->asset[0].img = mlx_new_image(data->mlx, SCREEN_W, SCREEN_H);
	data->asset[1].img = mlx_new_image(data->mlx, data->map_width * MAP_S, data->map_height * MAP_S);
	data->asset[2].img = mlx_xpm_file_to_image(data->mlx,
						data->path.north,
						&data->asset[2].width, &data->asset[2].height);
	data->asset[3].img = mlx_xpm_file_to_image(data->mlx,
						data->path.south,
						&data->asset[3].width, &data->asset[3].height);
	data->asset[4].img = mlx_xpm_file_to_image(data->mlx,
						data->path.west,
						&data->asset[4].width, &data->asset[4].height);
	data->asset[5].img = mlx_xpm_file_to_image(data->mlx,
						data->path.east,
						&data->asset[5].width, &data->asset[5].height);
	data->asset[0].addr = (int *)mlx_get_data_addr(data->asset[0].img,
							&data->asset[0].bits_per_pixel,
							&data->asset[0].size_line, &data->asset[0].endian);
	data->asset[1].addr = (int *)mlx_get_data_addr(data->asset[1].img,
							&data->asset[1].bits_per_pixel,
							&data->asset[1].size_line, &data->asset[1].endian);
	data->asset[2].addr = (int *)mlx_get_data_addr(data->asset[2].img,
							&data->asset[2].bits_per_pixel,
							&data->asset[2].size_line, &data->asset[2].endian);
	data->asset[3].addr = (int *)mlx_get_data_addr(data->asset[3].img,
							&data->asset[3].bits_per_pixel,
							&data->asset[3].size_line, &data->asset[3].endian);
	data->asset[4].addr = (int *)mlx_get_data_addr(data->asset[4].img,
							&data->asset[4].bits_per_pixel,
							&data->asset[4].size_line, &data->asset[4].endian);
	data->asset[5].addr = (int *)mlx_get_data_addr(data->asset[5].img,
							&data->asset[5].bits_per_pixel,
							&data->asset[5].size_line, &data->asset[5].endian);
	// printf("img : %p\naddr : %s\nbits : %d\nsize_line : %d\nendian : %d\n", data->asset[0].img, data->asset[0].addr, data->asset[0].bits_per_pixel, data->asset[0].size_line, data->asset[0].endian);
	// int y = 0;
	// int	x;
	// while (y < SCREEN_H / 2)
	// {
	// 	x = 0;
	// 	while (x < SCREEN_W)
	// 	{
	// 		data->asset[0].addr[(y * (SCREEN_H)) + x] = create_trgb(0, 255, 0, 0);
	// 		x++;
	// 	}
	// 	y++;
	// }
	// while (y < SCREEN_H)
	// {
	// 	x = 0;
	// 	while (x < SCREEN_W)
	// 	{
	// 		data->asset[0].addr[(y * (SCREEN_H)) + x] = create_trgb(0, 0, 0, 100);
	// 		x++;
	// 	}
	// 	y++;
	// }
	// mlx_put_image_to_window(data->mlx, data->win2, data->asset[0].img, 0, 0);
}
