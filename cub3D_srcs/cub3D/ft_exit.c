/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: upean-de <upean-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 21:11:38 by julien            #+#    #+#             */
/*   Updated: 2022/04/05 13:48:06 by upean-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3D_include/cub3D.h"

int	ft_exit(t_data *data)
{
	int	i;

	i = 0;
	mlx_clear_window(data->mlx, data->win);
	// mlx_clear_window(data->mlx, data->win2);
	mlx_destroy_window(data->mlx, data->win);
	// mlx_destroy_window(data->mlx, data->win2);
	while (i <= 5)
	{
		if (data->asset[i].img)
			mlx_destroy_image(data->mlx, data->asset[i].img);
		else
			break ;
		i++;
	}
	mlx_destroy_display(data->mlx);
	free(data->mlx);
	clear_garbage(data);
	exit (0);
}
