/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clean_garbage.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbonniva <jbonniva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 21:41:52 by exodeus           #+#    #+#             */
/*   Updated: 2022/03/21 13:48:27 by jbonniva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D_include/cub3D.h"

void	ft_free_garb(t_garbage *garb)
{
	free(garb->point);
	garb->point = NULL;
	free(garb);
	garb = NULL;
}

void	clear_garbage(t_data *data)
{
	t_garbage	*garb;
	t_garbage	*tmp;

	garb = data->garbage;
	while (garb != NULL)
	{
		tmp = garb->next;
		ft_free_garb(garb);
		garb = tmp;
	}
}

void	ft_free(t_data *data, void *pointer)
{
	t_garbage	*garb;
	t_garbage	*tmp;

	garb = data->garbage;
	if (garb->point == pointer)
	{
		tmp = garb;
		data->garbage = data->garbage->next;
		ft_free_garb(tmp);
		return ;
	}
	while (garb->next != NULL)
	{
		if (garb->next->point == pointer)
		{
			tmp = garb->next;
			garb->next = tmp->next;
			ft_free_garb(tmp);
			break ;
		}
		garb = garb->next;
	}
}
