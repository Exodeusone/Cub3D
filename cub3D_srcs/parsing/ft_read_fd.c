/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_fd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julien <julien@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 22:25:35 by exodeus           #+#    #+#             */
/*   Updated: 2022/03/22 15:28:05 by julien           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3D_include/cub3D.h"

int	ft_first_check(t_data *data)
{
	if (data->map_height < 3)
		return (ft_puterr("Error\n"), ft_puterr("Invalid map\n"), 1);
	return (0);
}

void	ft_malloc_map(t_data *data)
{
	t_map	*tmp;
	int		i;
	int		j;

	i = 0;
	tmp = data->map;
	while (tmp->next)
		tmp = tmp->next;
	tmp->map = ft_malloc(data, sizeof(char *) * (data->map_height + 1));
	while (i < data->map_height)
	{
		tmp->map[i] = ft_malloc(data, sizeof(char) * data->map_width);
		j = 0;
		while (j < data->map_width - 1)
		{
			tmp->map[i][j] = ' ';
			j++;
		}
		tmp->map[i][j] = '\0';
		i++;
	}
	tmp->map[i] = NULL;
}

int	ft_get_my_size_map(t_data *data, char *str, int i)
{
	if (ft_check_line(str) == 2)
		return (1);
	if (ft_check_line(str) == 1 && data->map_height > 0)
	{
		data->map_check = 1;
		return (0);
	}
	else if (ft_check_line(str) == 1 && data->map_height == 0)
		return (0);
	if (ft_check_line(str) == 0 && data->map_check == 1)
		return (1);
	if (data->before_map == 0)
		data->before_map = i;
	data->map_height++;
	if (data->map_width < ft_strlen(str))
		data->map_width = ft_strlen(str);
	return (0);
}

int	ft_check_read(t_data *data, char *str, int j)
{
	int	i;

	i = 0;
	if (ft_check_all_identifier(data) == 0)
	{
		while (str[i] && (str[i] == ' ' || str[i] == '\t'))
			i++;
		if (!str[i] || str[i] == '\n')
			return (0);
		if (ft_find_identifier(data, &str[i]) == 1)
			return (1);
	}
	else
	{
		if (ft_get_my_size_map(data, str, j) == 1)
		{
			ft_puterr("Error\nInvalid map\n");
			return (1);
		}
	}
	return (0);
}

int	ft_read_fd(t_data *data, int fd)
{
	char	*str;
	int		i;

	i = 0;
	while (1)
	{
		str = get_next_line(data, fd);
		if (!str)
			break ;
		if (ft_check_read(data, str, i) == 1)
		{
			ft_free(data, str);
			return (1);
		}
		ft_free(data, str);
		i++;
	}
	if (ft_first_check(data) == 1)
		return (1);
	ft_malloc_map(data);
	return (0);
}
