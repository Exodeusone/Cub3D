/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julien <julien@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 09:22:50 by jbonniva          #+#    #+#             */
/*   Updated: 2022/03/22 14:22:59 by julien           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D_include/cub3D.h"

void	ft_init_data(t_data *data)
{
	data->map_height = 0;
	data->map_width = 0;
	data->map_check = 0;
	data->before_map = 0;
	data->player.coor.x = 0;
	data->player.coor.y = 0;
}

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc != 2)
		return (ft_puterr("You need to send an argument to cub3D\n"), 1);
	ft_init_data(&data);
	if (ft_check_name_map(argv[1]) == 1)
		return (1);
	init_garbage(&data);
	if (ft_parsing_map(&data, argv[1]) == 1)
	{
		clear_garbage(&data);
		return (1);
	}
	clear_garbage(&data);
	return (0);
}
