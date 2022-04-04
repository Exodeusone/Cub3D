/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_rgb.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julien <julien@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 22:49:39 by julien            #+#    #+#             */
/*   Updated: 2022/04/04 22:50:23 by julien           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3D_include/cub3D.h"

void	ft_add_rgb(t_data *data, int color, char c, int i)
{
	if (c == 'F')
	{
		if (i == 0)
			data->floor.red = color;
		else if (i == 1)
			data->floor.green = color;
		else if (i == 2)
			data->floor.blue = color;
	}
	else
	{
		if (i == 0)
			data->cell.red = color;
		else if (i == 1)
			data->cell.green = color;
		else if (i == 2)
			data->cell.blue = color;
	}
}
