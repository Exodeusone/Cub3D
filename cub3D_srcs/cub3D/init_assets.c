/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_assets.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: upean-de <upean-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 21:03:43 by julien            #+#    #+#             */
/*   Updated: 2022/04/06 13:50:17 by upean-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3D_include/cub3D.h"

void	ft_get_xpm(t_data *data)
{
	data->asset[1].img = mlx_xpm_file_to_image(data->mlx,
			data->path.north,
			&data->asset[1].width, &data->asset[1].height);
	data->asset[2].img = mlx_xpm_file_to_image(data->mlx,
			data->path.east,
			&data->asset[2].width, &data->asset[2].height);
	data->asset[3].img = mlx_xpm_file_to_image(data->mlx,
			data->path.south,
			&data->asset[3].width, &data->asset[3].height);
	data->asset[4].img = mlx_xpm_file_to_image(data->mlx,
			data->path.west,
			&data->asset[4].width, &data->asset[4].height);
	if (!data->asset[0].img || !data->asset[1].img || !data->asset[2].img
		|| !data->asset[3].img || !data->asset[4].img)
	{
		data->err = ft_strdup(data, "Error\nInvalid asset path\n");
		ft_exit(data);
	}
}

void	ft_get_addr(t_data *data)
{
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
	if (!data->asset[0].addr || !data->asset[1].addr || !data->asset[2].addr
		|| !data->asset[3].addr || !data->asset[4].addr)
	{
		data->err = ft_strdup(data, "Error\nInvalid initiaton address\n");
		ft_exit(data);
	}
}

void	init_assets(t_data *data)
{
	data->asset[0].img = mlx_new_image(data->mlx, SCREEN_W, SCREEN_H);
	ft_get_xpm(data);
	ft_get_addr(data);
}
