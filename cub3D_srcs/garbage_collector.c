/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   garbage_collector.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbonniva <jbonniva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 13:29:15 by upean-de          #+#    #+#             */
/*   Updated: 2022/03/21 13:45:56 by jbonniva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D_include/cub3D.h"

int	init_garbage(t_data *data)
{
	data->garbage = malloc(sizeof(t_garbage));
	if (!data->garbage)
		return (0);
	data->garbage->point = NULL;
	data->garbage->next = NULL;
	return (1);
}

t_garbage	*last_garbage(t_garbage *garbage)
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
	t_garbage	*last;
	t_garbage	*new_garbage;

	last = NULL;
	if (data->garbage->point)
	{
		new_garbage = malloc(sizeof(t_garbage));
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
