/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_coor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julien <julien@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 21:02:27 by julien            #+#    #+#             */
/*   Updated: 2022/04/04 21:32:13 by julien           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3D_include/cub3D.h"

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
