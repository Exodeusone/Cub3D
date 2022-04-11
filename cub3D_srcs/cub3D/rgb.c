/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rgb.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: upean-de <upean-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 21:10:46 by julien            #+#    #+#             */
/*   Updated: 2022/04/06 14:55:38 by upean-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3D_include/cub3D.h"

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

int	key_init(int keycode, t_data *data)
{
	if (keycode == 65307)
		ft_exit(data);
	if (keycode == 'w')
		data->move.up = 1;
	if (keycode == 's')
		data->move.down = 1;
	if (keycode == 'a')
		data->move.left = 1;
	if (keycode == 'd')
		data->move.right = 1;
	if (keycode == 65363)
		data->move.rr = 1;
	if (keycode == 65361)
		data->move.rl = 1;
	return (0);
}

int	key_reset(int keycode, t_data *data)
{
	if (keycode == 'w')
		data->move.up = 0;
	if (keycode == 's')
		data->move.down = 0;
	if (keycode == 'a')
		data->move.left = 0;
	if (keycode == 'd')
		data->move.right = 0;
	if (keycode == 65363)
		data->move.rr = 0;
	if (keycode == 65361)
		data->move.rl = 0;
	return (0);
}
