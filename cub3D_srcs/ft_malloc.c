/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbonniva <jbonniva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 11:20:43 by jbonniva          #+#    #+#             */
/*   Updated: 2022/03/21 13:47:40 by jbonniva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D_include/cub3D.h"

void	*ft_malloc(t_data *data, size_t size)
{
	void	*elem;

	elem = malloc(size);
	if (!elem)
	{
		clear_garbage(data);
		exit(0);
	}
	if (!add_garbage(data, elem))
	{
		clear_garbage(data);
		exit(0);
	}
	return (elem);
}
