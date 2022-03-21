/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exodeus <exodeus@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 09:22:50 by jbonniva          #+#    #+#             */
/*   Updated: 2022/03/21 21:24:05 by exodeus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D_include/cub3D.h"

int	main(int argc, char **argv)
{
	t_data	data;

	data.map_height = 0;
	data.map_width = 0;
	data.map_check = 0;
	data.before_map = 0;
	if (argc != 2)
		return (ft_puterr("You need to send an argument to cub3D\n"), 1);
	if (ft_check_name_map(argv[1]) == 1)
		return (1);
	init_garbage(&data);
	if (ft_parsing_map(&data, argv[1]) == 1)
	{
		clear_garbage(&data);
		return (1);
	}
	return (0);
}