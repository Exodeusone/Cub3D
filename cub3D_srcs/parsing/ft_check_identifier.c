/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_identifier.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exodeus <exodeus@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 22:35:26 by exodeus           #+#    #+#             */
/*   Updated: 2022/03/21 23:12:58 by exodeus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3D_include/cub3D.h"

char	*ft_get_my_path(char *str)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != ' ')
	{
		if (str[i] == '\n')
			return (NULL);
		i++;
	}
	i++;
	if (str[i] != '.')
		return (NULL);
	return (&str[i]);
}

char	*ft_get_my_path_2(char *str)
{
	int	i;

	i = 1;
	while (str[i] && str[i] == ' ')
	{
		i++;
	}
	if (str[i] == '\n')
		return (NULL);
	i++;
	if (ft_check_rgb(&str[i]) == 1)
		return (NULL);
	return (&str[i]);
}

int	ft_check_identifier_1(t_data *data, char *str)
{
	t_map	*tmp;

	tmp = data->map;
	while (tmp)
	{
		if (ft_strncmp(tmp->identifier, str, 2) == 0)
		{
			if (tmp->path == NULL)
			{
				tmp->path = ft_strdup(data, ft_get_my_path(str));
				if (tmp->path == NULL)
					return (ft_puterr
						("You need to put some path in all orientation"), 1);
			}
			else
				return (ft_puterr("Too many same orientation\n"), 1);
			break ;
		}
		tmp = tmp->next;
	}
	return (0);
}

int	ft_check_identifier_2(t_data *data, char *str)
{
	t_map	*tmp;

	tmp = data->map;
	while (tmp)
	{
		if (ft_strncmp(tmp->identifier, str, 1) == 0)
		{
			if (tmp->path == NULL)
			{
				tmp->path = ft_strdup(data, ft_get_my_path_2(str));
				if (tmp->path == NULL)
					return (ft_puterr("You need to put some valid rgb\n"), 1);
			}
			else
				return (ft_puterr("Too many same orientation\n"), 1);
			break ;
		}
		tmp = tmp->next;
	}
	return (0);
}

int	ft_check_all_identifier(t_data *data)
{
	t_map	*tmp;
	int		i;

	i = 0;
	tmp = data->map;
	while (i < 6)
	{
		if (tmp->path == NULL)
			return (0);
		tmp = tmp->next;
		i++;
	}
	return (1);
}
