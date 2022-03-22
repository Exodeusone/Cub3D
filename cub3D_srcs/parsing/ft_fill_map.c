/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julien <julien@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 22:29:34 by exodeus           #+#    #+#             */
/*   Updated: 2022/03/22 14:01:39 by julien           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3D_include/cub3D.h"

int	ft_check_line(char *str)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != '\n')
	{
		if (str[i] == '1' || str[i] == '0' || str[i] == ' '
			|| str[i] == 'N' || str[i] == 'E' || str[i] == 'S' || str[i] == 'W')
			i++;
		else
			return (2);
	}
	i = 0;
	while (str[i] && str[i] != '\n')
	{
		if (str[i] == '0' || str[i] == '1')
			return (0);
		i++;
	}
	return (1);
}

void	ft_put_in_area(t_data *data, char *str, int i)
{
	t_map	*tmp;
	int		j;

	j = 0;
	tmp = data->map;
	while (tmp->next)
		tmp = tmp->next;
	while (str[j] && str[j] != '\n')
	{
		tmp->map[i][j] = str[j];
		j++;
	}
}

void	ft_create_area(t_data *data, int fd)
{
	char	*str;
	int		i;

	i = 0;
	while (i < data->before_map)
	{
		str = get_next_line(data, fd);
		ft_free(data, str);
		i++;
	}
	i = 0;
	while (i < data->map_height)
	{
		str = get_next_line(data, fd);
		ft_put_in_area(data, str, i);
		ft_free(data, str);
		i++;
	}
}

int	ft_fill_map(t_data *data, char *str)
{
	int	fd;

	fd = open(str, O_RDONLY);
	if (fd < 3)
		return (ft_puterr(str), ft_puterr(" can't be open\n"), 1);
	ft_create_area(data, fd);
	if (close(fd) < 0)
		return (ft_puterr(str), ft_puterr(" can't be close\n"), 1);
	return (0);
}
