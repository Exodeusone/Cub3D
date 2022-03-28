/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleaner.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: upean-de <upean-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 18:01:21 by upean-de          #+#    #+#             */
/*   Updated: 2022/03/28 18:17:33 by upean-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3D_include/cub3D.h"


void	ft_clean_cleaner(t_data *data)
{
	t_cleaner	*tmp;

	while (data->cleaner)
	{
		tmp = data->cleaner;
		data->cleaner = data->cleaner->next;
		erase_direction(data, tmp);
		ft_free(data, tmp);
		tmp = NULL;
	}
}

void	ft_set_cleaner(t_cleaner *new)
{
	new->x = 0.00000000;
	new->y = 0.00000000;
	new->ra = 0.00000000;
	new->ry = 0.00000000;
	new->dy = 0.00000000;
	new->next = NULL;
	new->prev = NULL;
}

void	ft_add_cleaner(t_data *data, t_cleaner *new)
{
	t_cleaner	*tmp;

	tmp = data->cleaner;
	while (tmp->next)
		tmp = tmp->next;
	new->x = data->player.x;
	new->y = data->player.y;
	new->ra = data->player.ra;
	new->ry = data->player.ry;
	new->dy = data->player.dy;
	tmp->next = new;
	new->prev = tmp;
}

void	ft_first_clean(t_data *data, t_cleaner *new)
{
	new->x = data->player.x;
	new->y = data->player.y;
	new->ra = data->player.ra;
	new->ry = data->player.ry;
	new->dy = data->player.dy;
	data->cleaner = new;
}

void	add_cleaner(t_data *data)
{
	t_cleaner	*new;

	new = ft_malloc(data, sizeof(t_cleaner));
	ft_set_cleaner(new);
	if (data->cleaner == NULL)
		ft_first_clean(data, new);
	else
		ft_add_cleaner(data, new);
}
