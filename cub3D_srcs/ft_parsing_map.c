/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbonniva <jbonniva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 11:39:25 by jbonniva          #+#    #+#             */
/*   Updated: 2022/03/21 17:09:23 by jbonniva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D_include/cub3D.h"

char *ft_get_my_path(char *str)
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

int	ft_check_rgb(char *str)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != '\n')
	{
		if ((str[i] < '0' || str[i] > '9') && str[i] != ',')
			return (1);
		i++;
	}
	return (0);
}

char *ft_get_my_path_2(char *str)
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
					return (ft_puterr("You need to put some path in all orientation"), 1);
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

int	ft_check_identifier(t_data *data, char *str)
{
	if (ft_strncmp(str, "SO", 2) == 0)
	{
		if (ft_check_identifier_1(data, str) == 1)
			return (1);
	}
	if (ft_strncmp(str, "NO", 2) == 0)
	{
		if (ft_check_identifier_1(data, str) == 1)
			return (1);
	}
	if (ft_strncmp(str, "WE", 2) == 0)
	{
		if (ft_check_identifier_1(data, str) == 1)
			return (1);
	}
	if (ft_strncmp(str, "EA", 2) == 0)
	{
		if (ft_check_identifier_1(data, str) == 1)
			return (1);
	}
	if (ft_strncmp(str, "F", 1) == 0)
	{
		if (ft_check_identifier_2(data, str) == 1)
			return (1);
	}
	if (ft_strncmp(str, "C", 1) == 0)
	{
		if (ft_check_identifier_2(data, str) == 1)
			return (1);
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

int	ft_check_read(t_data *data, char *str)
{
	int	i;

	i = 0;
	if (ft_check_all_identifier(data) == 0)
	{
		while(str[i] && (str[i] == ' ' || str[i] == '\t'))
			i++;
		if (!str[i] || str[i] == '\n')
			return (0);
		if (ft_check_identifier(data, &str[i]) == 1)
			return (1);
	}
	else
	{
		// if (ft_get_my_map(data, str) == 1)
		// 	return (1);
		printf("ICI\n");
	}
	return (0);
}

void	print_map(t_map *map)
{
	t_map *tmp;

	tmp = map;
	while (tmp)
	{
		if (tmp->identifier != NULL)
			printf("%s ", tmp->identifier);
		if (tmp->path != NULL)
			printf("%s", tmp->path);
		printf("\n");
		tmp = tmp->next;
	}
}

int	ft_read_fd(t_data *data, int fd)
{
	char	*str;

	while (1)
	{
		str = get_next_line(fd);
		if (!str)
			break ;
		if (ft_check_read(data, str) == 1)
		{
			free(str);
			return (1);
		}
		free(str);
	}
	return (0);
}

int	ft_parse_fd(t_data *data, int fd)
{
	ft_create_map(data);
	if (ft_read_fd(data, fd) == 1)
		return (1);
	print_map(data->map);
	// if (ft_check_map(data) == 1)
	// 	return (1);
	return (0);
}

int	ft_parsing_map(t_data *data, char *str)
{
	int	fd;
	int	ret;

	ret = 0;
	fd = open(str, O_RDONLY);
	if (fd < 3)
		return (ft_puterr(str), ft_puterr(" can't be open\n"), 1);
	ret = ft_parse_fd(data, fd);
	if (close(fd) < 0)
		return (ft_puterr(str), ft_puterr(" can't be close\n"), 1);
	return (ret);
}