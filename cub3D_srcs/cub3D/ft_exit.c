/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: upean-de <upean-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 21:11:38 by julien            #+#    #+#             */
/*   Updated: 2022/04/06 13:56:39 by upean-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3D_include/cub3D.h"

int	ft_exit(t_data *data)
{
	int	i;

	i = 0;
	mlx_clear_window(data->mlx, data->win);
	mlx_destroy_window(data->mlx, data->win);
	while (i <= 4)
	{
		if (data->asset[i].img)
			mlx_destroy_image(data->mlx, data->asset[i].img);
		i++;
	}
	mlx_destroy_display(data->mlx);
	free(data->mlx);
	if (data->err)
		ft_puterr(data->err);
	clear_garbage(data);
	exit (0);
}
