/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_move.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: upean-de <upean-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 18:31:43 by upean-de          #+#    #+#             */
/*   Updated: 2022/03/28 18:55:28 by upean-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3D_include/cub3D.h"

int	ok_move_up(t_data *data)
{
	float	x;
	float	y;
	t_map	*tmp;

	tmp = data->map;
	while (tmp->map == NULL)
		tmp = tmp->next;
	x = (data->player.x + data->player.dx) / 64;
	y = (data->player.y + data->player.dy) / 64;
	if (x >= 0 && x < data->map_width && y >= 0 && y < data->map_height
		&& tmp->map[(int)y][(int)x] == '1')
		return (1);
	return (0);
}
