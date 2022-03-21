/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   garbage_collector.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exodeus <exodeus@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 13:29:15 by upean-de          #+#    #+#             */
/*   Updated: 2022/03/21 23:07:36 by exodeus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3D_include/cub3D.h"

int	init_garbage(t_data *data)
{
	data->garbage = malloc(sizeof(t_garb));
	if (!data->garbage)
		return (0);
	data->garbage->point = NULL;
	data->garbage->next = NULL;
	return (1);
}

t_garb	*last_garbage(t_garb *garbage)
{
	while (garbage)
	{
		if (garbage->next == NULL)
			return (garbage);
		garbage = garbage->next;
	}
	return (garbage);
}

int	add_garbage(t_data *data, void *new)
{
	t_garb	*last;
	t_garb	*new_garbage;

	last = NULL;
	if (data->garbage->point)
	{
		new_garbage = malloc(sizeof(t_garb));
		if (!new_garbage)
			return (0);
		new_garbage->point = new;
		new_garbage->next = NULL;
		last = last_garbage(data->garbage);
		last->next = new_garbage;
	}
	else
		data->garbage->point = new;
	return (1);
}
