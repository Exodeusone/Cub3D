/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julien <julien@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 11:39:25 by jbonniva          #+#    #+#             */
/*   Updated: 2022/03/22 15:30:13 by julien           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3D_include/cub3D.h"

void	print_map(t_map *map)
{
	t_map	*tmp;
	int		i;

	i = 0;
	tmp = map;
	while (tmp)
	{
		if (tmp->identifier != NULL)
			printf("%s ", tmp->identifier);
		if (tmp->path != NULL)
			printf("%s", tmp->path);
		if (tmp->map != NULL)
		{
			printf("\n");
			while (tmp->map[i])
			{
				printf("%s\n", tmp->map[i]);
				i++;
			}
		}
		tmp = tmp->next;
	}
}

int	ft_parse_fd(t_data *data, int fd, char *str)
{
	ft_create_map(data);
	if (ft_read_fd(data, fd) == 1)
		return (1);
	if (ft_fill_map(data, str) == 1)
		return (1);
	if (ft_check_map(data) == 1)
		return (1);
	ft_replace_space(data);
	print_map(data->map);
	return (0);
}

int	ft_parsing_map(t_data *data, char *str)
{
	int	fd;
	int	ret;

	ret = 0;
	fd = open(str, O_RDONLY);
	if (fd < 3)
		return (ft_puterr("Error\n"),
			ft_puterr(str), ft_puterr(" can't be open\n"), 1);
	ret = ft_parse_fd(data, fd, str);
	if (close(fd) < 0)
		return (ft_puterr("Error\n"),
			ft_puterr(str), ft_puterr(" can't be close\n"), 1);
	return (ret);
}
