/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: upean-de <upean-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 09:22:50 by jbonniva          #+#    #+#             */
/*   Updated: 2022/03/28 18:22:13 by upean-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D_include/cub3D.h"

void	ft_init_data(t_data *data)
{
	data->map_height = 0;
	data->map_width = 0;
	data->map_check = 0;
	data->before_map = 0;
	data->player.x = 0;
	data->player.y = 0;
	data->cleaner = NULL;
}

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc != 2)
		return (ft_puterr("Error\n"),
			ft_puterr("You need to send an argument to cub3D\n"), 1);
	ft_init_data(&data);
	if (ft_check_name_map(argv[1]) == 1)
		return (1);
	init_garbage(&data);
	if (ft_parsing_map(&data, argv[1]) == 1)
	{
		clear_garbage(&data);
		return (1);
	}
	init_minimap(&data);
	clear_garbage(&data);
	return (0);
}
