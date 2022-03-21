/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exodeus <exodeus@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 20:25:11 by exodeus           #+#    #+#             */
/*   Updated: 2022/03/21 22:04:05 by exodeus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3D_include/cub3D.h"

char	*ft_statical_to_statical(char *statical)
{
	char	*new_statical;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (statical[i] != '\n' && statical[i] != '\0')
		i++;
	if (statical[i] == '\0')
	{
		free(statical);
		return (NULL);
	}
	new_statical = malloc(sizeof(char) * (ft_len(statical) - i + 1));
	i++;
	while (statical[i] != '\0')
	{
		new_statical[j] = statical[i];
		i++;
		j++;
	}
	new_statical[j] = '\0';
	free(statical);
	return (new_statical);
}

char	*ft_statical_to_line(char *statical)
{
	char	*line;
	int		i;

	line = NULL;
	i = 0;
	if (statical[i] == '\0')
		return (NULL);
	while (statical[i] != '\0' && statical[i] != '\n')
		i++;
	if (statical[i] == '\0')
		line = malloc(sizeof(char) * (i + 1));
	else if (statical[i] == '\n')
		line = malloc(sizeof(char) * (i + 2));
	if (!line)
	{
		free(statical);
		return (NULL);
	}
	return (ft_statical_cpy(line, statical));
}

char	*ft_read_buf(int fd, char *statical)
{
	char	*buf;
	int		ret;

	ret = 1;
	buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (NULL);
	while (!ft_statical_chr(statical, '\n') && ret > 0)
	{
		ret = read(fd, buf, BUFFER_SIZE);
		if (ret < 0)
			break ;
		buf[ret] = '\0';
		statical = ft_statical_buf_join(statical, buf);
	}
	free(buf);
	return (statical);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*statical;

	line = NULL;
	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	statical = ft_read_buf(fd, statical);
	if (!statical)
		return (NULL);
	line = ft_statical_to_line(statical);
	statical = ft_statical_to_statical(statical);
	return (line);
}
