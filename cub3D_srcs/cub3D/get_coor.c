/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_coor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: upean-de <upean-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 21:02:27 by julien            #+#    #+#             */
/*   Updated: 2022/04/06 14:12:25 by upean-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3D_include/cub3D.h"

void	ft_init_start_angle(t_data *data, char c)
{
	if (c == 'N')
	{
		data->player.dir_x = -1;
		data->player.plane_y = 0.66;
	}
	if (c == 'S')
	{
		data->player.dir_x = 1;
		data->player.plane_y = -0.66;
	}
	if (c == 'W')
	{
		data->player.dir_y = -1;
		data->player.plane_x = -0.66;
	}
	if (c == 'E')
	{
		data->player.dir_y = 1;
		data->player.plane_x = 0.66;
	}
}

void	get_coor(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			if (data->map[i][j] == 'N' || data->map[i][j] == 'S'
				|| data->map[i][j] == 'E' || data->map[i][j] == 'W')
			{
				data->player.pos_x = (float)i + 0.5;
				data->player.pos_y = (float)j + 0.5;
				ft_init_start_angle(data, data->map[i][j]);
				return ;
			}
			j++;
		}
		i++;
	}
}
