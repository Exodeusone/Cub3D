/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julien <julien@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 11:39:25 by jbonniva          #+#    #+#             */
/*   Updated: 2022/03/31 22:02:36 by julien           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3D_include/cub3D.h"

int	ft_parse_fd(t_data *data, int fd, char *str)
{
	ft_create_map(data);
	if (ft_read_fd(data, fd) == 1)
		return (1);
	if (ft_fill_map(data, str) == 1)
		return (1);
	if (ft_check_map(data) == 1)
		return (1);
	ft_replace_space(data);
	return (0);
}

int	ft_parsing_map(t_data *data, char *str)
{
	int	fd;
	int	ret;

	ret = 0;
	fd = open(str, O_DIRECTORY);
	if (fd != -1)
		return (ft_puterr("Error\n"),
			ft_puterr(str), ft_puterr(" is a directory\n"), 1);
	fd = open(str, O_RDONLY);
	if (fd < 3)
		return (ft_puterr("Error\n"),
			ft_puterr(str), ft_puterr(" can't be open\n"), 1);
	ret = ft_parse_fd(data, fd, str);
	if (close(fd) < 0)
		return (ft_puterr("Error\n"),
			ft_puterr(str), ft_puterr(" can't be close\n"), 1);
	return (ret);
}
