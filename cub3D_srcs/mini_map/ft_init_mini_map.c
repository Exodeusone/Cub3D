/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_mini_map.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julien <julien@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 17:33:44 by julien            #+#    #+#             */
/*   Updated: 2022/03/22 18:33:17 by julien           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3D_include/cub3D.h"

int	ft_calcul_ratio_x(t_data *data)
{
	t_map	*tmp;

	tmp = data->map;
	while (tmp->next)
		tmp = tmp->next;
	return (ft_strlen(tmp->map[0]));
}

int	ft_calcul_ratio_y(t_data *data)
{
	t_map	*tmp;

	tmp = data->map;
	while (tmp->next)
		tmp = tmp->next;
	return (ft_strslen(tmp->map));
}

void	ft_init_mini_map(t_data *data)
{
	int	ratio_x;
	int	ratio_y;
	
	ratio_x = ft_calcul_ratio_x(data);
	ratio_y = ft_calcul_ratio_y(data);
	data->mini.size_x = 150 / ratio_x;
	data->mini.size_y = 100 / ratio_y;
	data->mini.coor.x = 1350;
	data->mini.coor.y = 900;
}