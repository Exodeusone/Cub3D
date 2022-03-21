/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbonniva <jbonniva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 22:56:41 by exodeus           #+#    #+#             */
/*   Updated: 2022/03/21 09:21:16 by jbonniva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D_include/cub3D.h"

int	ft_len(char *s)
{
	int	len;

	len = 0;
	while (s[len] != '\0')
		len++;
	return (len);
}

char	*ft_statical_cpy(char *line, char *statical)
{
	int	i;

	i = 0;
	while (statical[i] != '\0' && statical[i] != '\n')
	{
		line[i] = statical[i];
		i++;
	}
	if (statical[i] == '\n')
	{
		line[i] = '\n';
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*ft_cpy_in_join(char *statical, char *buf, char *new_statical)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (statical[j] != '\0')
	{
		new_statical[j] = statical[j];
		j++;
	}
	while (buf[i] != '\0')
	{
		new_statical[j] = buf[i];
		i++;
		j++;
	}
	new_statical[j] = '\0';
	free(statical);
	return (new_statical);
}

char	*ft_statical_buf_join(char *statical, char *buf)
{
	char	*new_statical;

	if (!statical)
	{
		statical = malloc(sizeof(char) * 1);
		statical[0] = '\0';
	}
	if (!statical || !buf)
		return (NULL);
	new_statical = malloc(sizeof(char) * (ft_len(statical) + ft_len(buf) + 1));
	if (!new_statical)
		return (NULL);
	return (ft_cpy_in_join(statical, buf, new_statical));
}

int	ft_statical_chr(char *s, int c)
{
	int		i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != '\0')
	{
		if (s[i] == (char)c)
			return (1);
		i++;
	}
	if (s[i] == (char)c)
		return (1);
	return (0);
}
