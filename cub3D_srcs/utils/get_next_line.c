/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julien <julien@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 11:48:15 by upean-de          #+#    #+#             */
/*   Updated: 2022/03/31 21:48:49 by julien           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3D_include/cub3D.h"

static char	*put_cpy_line(char *substr, char *line)
{
	int	i;

	i = 0;
	while (substr[i] != '\n' && substr[i] != '\0')
	{
		line[i] = substr[i];
		i++;
	}
	if (substr[i] == '\n')
	{
		line[i] = '\n';
		i++;
	}
	line[i] = '\0';
	return (line);
}

static char	*cpy_line(t_data *data, char *substr)
{
	char	*line;
	int		i;

	line = NULL;
	i = 0;
	if (substr[i] == '\0')
		return (NULL);
	while (substr[i] != '\n' && substr[i] != '\0')
		i++;
	if (substr[i] == '\n')
		line = ft_malloc(data, sizeof(char) * (i + 2));
	else if (substr[i] == '\0')
		line = ft_malloc(data, sizeof(char) * (i + 1));
	if (!line)
		return (NULL);
	return (put_cpy_line(substr, line));
}

static char	*trim_substr(t_data *data, char *substr)
{
	char	*dest;
	int		i;
	int		j;

	dest = NULL;
	i = 0;
	j = 0;
	while (substr[i] != '\n' && substr[i] != '\0')
		i++;
	if (substr[i] == '\0')
	{
		ft_free(data, substr);
		return (NULL);
	}
	dest = ft_malloc(data, sizeof(char) * (ft_strlen(substr) - i + 1));
	i++;
	while (substr[i] != '\0')
	{
		dest[j] = substr[i];
		i++;
		j++;
	}
	dest[j] = '\0';
	ft_free (data, substr);
	return (dest);
}

static char	*ft_read(t_data *data, char *substr, int fd)
{
	char	*buff;
	int		cursor;

	cursor = 1;
	buff = ft_malloc(data, sizeof(char) * (BUFFER_SIZE + 1));
	while (!(ft_strchr(substr, '\n') && cursor != 0))
	{
		if (!buff)
		{
			ft_free(data, substr);
			return (NULL);
		}
		cursor = read(fd, buff, BUFFER_SIZE);
		if (cursor <= 0)
			break ;
		buff[cursor] = '\0';
		substr = ft_strjoin(data, substr, buff);
	}
	ft_free(data, buff);
	return (substr);
}

char	*get_next_line(t_data *data, int fd)
{
	char			*line;
	static char		*substr;

	line = NULL;
	if (!substr)
	{
		substr = ft_malloc(data, sizeof(char) * 1);
		if (!substr)
			return (NULL);
		else
			substr[0] = '\0';
	}
	substr = ft_read(data, substr, fd);
	if (substr == NULL)
		return (NULL);
	line = cpy_line(data, substr);
	substr = trim_substr(data, substr);
	return (line);
}
