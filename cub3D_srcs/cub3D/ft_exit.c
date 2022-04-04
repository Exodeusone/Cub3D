/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julien <julien@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 21:11:38 by julien            #+#    #+#             */
/*   Updated: 2022/04/04 21:11:48 by julien           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3D_include/cub3D.h"

int	ft_exit(t_data *data)
{
	mlx_clear_window(data->mlx, data->win);
	mlx_clear_window(data->mlx, data->win2);
	mlx_destroy_window(data->mlx, data->win);
	mlx_destroy_window(data->mlx, data->win2);
	mlx_destroy_display(data->mlx);
	free(data->mlx);
	clear_garbage(data);
	exit (0);
}
