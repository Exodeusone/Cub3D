/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbonniva <jbonniva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 14:43:55 by jbonniva          #+#    #+#             */
/*   Updated: 2022/03/21 14:44:09 by jbonniva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D_include/cub3D.h"

void	ft_new_map(t_map *map)
{
	map->identifier = NULL;
	map->path = NULL;
	map->map = NULL;
	map->next = NULL;
	map->prev = NULL;
}

void	ft_add_map(t_data *data, char *str)
{
	t_map	*new;
	t_map	*tmp;

	tmp = data->map;
	if (tmp->identifier == NULL)
	{
		tmp->identifier = ft_strdup(data, str);
		return ;
	}
	new = ft_malloc(data, sizeof(t_map));
	ft_new_map(new);
	while (tmp->next)
		tmp = tmp->next;
	if (str)
		new->identifier = ft_strdup(data, str);
	tmp->next = new;
	new->prev = tmp;
}

void	ft_create_map(t_data *data)
{
	data->map = ft_malloc(data, sizeof(t_map));
	ft_new_map(data->map);
	ft_add_map(data, "NO");
	ft_add_map(data, "SO");
	ft_add_map(data, "WE");
	ft_add_map(data, "EA");
	ft_add_map(data, "F");
	ft_add_map(data, "C");
	ft_add_map(data, "MAP");
}
