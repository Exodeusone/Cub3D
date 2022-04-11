/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: upean-de <upean-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 14:55:50 by upean-de          #+#    #+#             */
/*   Updated: 2022/04/06 14:58:29 by upean-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3D_include/cub3D.h"

void	ft_draw_ray7(t_data *data, int y, int x)
{
	while (y < data->display.draw_end)
	{
		data->display.tex_y = (int)data->display.tex_pos
			& (data->asset[data->display.tex_dir].height - 1);
		data->display.tex_pos += data->display.step;
		if (y < SCREEN_H && x < SCREEN_W)
			data->asset[0].addr[y * SCREEN_W + x]
				= data->asset[data->display.tex_dir].addr[data->display.tex_y
				* data->asset[data->display.tex_dir].width
				+ data->display.tex_x];
		y++;
	}
}
