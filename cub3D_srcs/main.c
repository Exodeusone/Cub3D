/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: upean-de <upean-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 09:22:50 by jbonniva          #+#    #+#             */
/*   Updated: 2022/04/05 12:05:06 by upean-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D_include/cub3D.h"

void	ft_init_data(t_data *data)
{
	data->map_height = 0;
	data->map_width = 0;
	data->map_check = 0;
	data->before_map = 0;
	data->player.pos_x = 0;
	data->player.pos_y = 0;
	data->cell.red = 0;
	data->cell.green = 0;
	data->cell.blue = 0;
	data->floor.red = 0;
	data->floor.green = 0;
	data->floor.blue = 0;
	data->path.north = NULL;
	data->path.south = NULL;
	data->path.east = NULL;
	data->path.west = NULL;
	data->map = NULL;
}

void	ft_print_data(t_data *data)
{
	printf("NORTH = %s\n", data->path.north);
	printf("SOUTH = %s\n", data->path.south);
	printf("WEST = %s\n", data->path.west);
	printf("EAST = %s\n", data->path.east);
	printf("RGB FLOOR = red : %d | green : %d | blue %d\n", data->floor.red, data->floor.green, data->floor.blue);
	printf("RGB CELL = red : %d | green : %d | blue %d\n", data->cell.red, data->cell.green, data->cell.blue);
	printf("MAP dans la structure data :\n\n");
	for (int i = 0; data->map[i]; i++)
		printf("%s\n", data->map[i]);
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
	ft_get_fd(&data);
	ft_print_data(&data);
	cub3d(&data);
	clear_garbage(&data);
	return (0);
}
