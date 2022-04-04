/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julien <julien@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 09:22:50 by jbonniva          #+#    #+#             */
/*   Updated: 2022/04/04 22:48:54 by julien           ###   ########.fr       */
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

void	ft_get_data_map(t_data *data, t_fd *fd)
{
	int	i;

	i = 0;
	data->map = ft_malloc(data, (sizeof(char *) * (ft_strslen(fd->map) + 1)));
	while (fd->map[i])
	{
		data->map[i] = ft_strdup(data, fd->map[i]);
		i++;
	}
	data->map[i] = NULL;
}

void	ft_clear_fd(t_data *data)
{
	t_fd	*tmp;

	while (data->fd->next)
	{
		tmp = data->fd;
		data->fd = data->fd->next;
		ft_free(data, tmp->identifier);
		tmp->identifier = NULL;
		ft_free(data, tmp->path);
		tmp->path = NULL;
		ft_free(data, tmp);
		tmp = NULL;
	}
	ft_free(data, data->fd->identifier);
	data->fd->identifier = NULL;
	ft_free_strs(data, data->fd->map);
	ft_free(data, data->fd);
	data->fd = NULL;
}

void	ft_get_fd(t_data *data)
{
	t_fd	*fd;
	int		i;

	i = 0;
	fd = data->fd;
	while (fd->next)
	{
		if (i == 0)
			data->path.north = ft_strdup_path(data, fd->path);
		if (i == 1)
			data->path.south = ft_strdup_path(data, fd->path);
		if (i == 2)
			data->path.west = ft_strdup_path(data, fd->path);
		if (i == 3)
			data->path.east = ft_strdup_path(data, fd->path);
		fd = fd->next;
		i++;
	}
	ft_get_data_map(data, fd);
	ft_clear_fd(data);
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
