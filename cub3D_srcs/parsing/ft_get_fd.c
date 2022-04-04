/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_fd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julien <julien@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 23:03:40 by julien            #+#    #+#             */
/*   Updated: 2022/04/04 23:04:00 by julien           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D_include/cub3D.h"

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
