/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_identifier.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: upean-de <upean-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 22:35:26 by exodeus           #+#    #+#             */
/*   Updated: 2022/04/06 13:28:30 by upean-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3D_include/cub3D.h"

char	*ft_get_my_path(char *str)
{
	int	i;

	i = 2;
	while (str[i] && str[i] == ' ')
	{
		if (str[i] == '\n')
			return (NULL);
		i++;
	}
	if (str[i] != '.')
		return (NULL);
	return (&str[i]);
}

char	*ft_get_my_path_2(t_data *data, char *str, char c)
{
	int	i;

	i = 1;
	while (str[i] && str[i] == ' ')
		i++;
	if (str[i] == '\n')
		return (NULL);
	if (str[i] < '0' || str[i] > '9')
		return (NULL);
	if (ft_check_rgb(data, &str[i], c) == 1)
		return (NULL);
	return (&str[i]);
}

int	ft_check_identifier_1(t_data *data, char *str)
{
	t_fd	*tmp;

	tmp = data->fd;
	while (tmp)
	{
		if (ft_strncmp(tmp->identifier, str, 2) == 0)
		{
			if (tmp->path == NULL)
			{
				tmp->path = ft_strdup(data, ft_get_my_path(str));
				if (tmp->path == NULL)
					return (ft_puterr("Error\n"), ft_puterr
						("You need to put some path in all orientation\n"), 1);
			}
			else
				return (ft_puterr("Error\n"),
					ft_puterr("Too many same orientation\n"), 1);
			break ;
		}
		tmp = tmp->next;
	}
	return (0);
}

int	ft_check_identifier_2(t_data *data, char *str, char c)
{
	t_fd	*tmp;

	tmp = data->fd;
	while (tmp)
	{
		if (ft_strncmp(tmp->identifier, str, 1) == 0)
		{
			if (tmp->path == NULL)
			{
				tmp->path = ft_strdup(data, ft_get_my_path_2(data, str, c));
				if (tmp->path == NULL)
					return (ft_puterr("Error\n"),
						ft_puterr("You need to put some valid rgb\n"), 1);
			}
			else
				return (ft_puterr("Error\n"),
					ft_puterr("Too many same orientation\n"), 1);
			break ;
		}
		tmp = tmp->next;
	}
	return (0);
}

int	ft_check_all_identifier(t_data *data)
{
	t_fd	*tmp;
	int		i;

	i = 0;
	tmp = data->fd;
	while (i < 6)
	{
		if (tmp->path == NULL)
			return (0);
		tmp = tmp->next;
		i++;
	}
	return (1);
}
