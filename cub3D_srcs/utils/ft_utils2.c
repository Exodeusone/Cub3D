/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julien <julien@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 13:42:58 by julien            #+#    #+#             */
/*   Updated: 2022/03/31 21:32:48 by julien           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3D_include/cub3D.h"

char	*ft_strjoin(t_data *data, char *s1, char *s2)
{
	char	*str;
	int		i;
	int		j;

	i = 0;
	j = 0;
	str = ft_malloc(data, sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		str[i] = s2[j];
		i++;
		j++;
	}
	str[i] = '\0';
	return (str);
}

int	ft_atoi(const char *str)
{
	int	i;
	int	negative;
	int	result;

	i = 0;
	negative = 1;
	result = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			negative *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9' && str[i])
	{
		result = result * 10 + (str[i] - 48);
		i++;
	}
	return (result * negative);
}

int	ft_strlen_rgb(char *str)
{
	int	i;

	i = 0;
	if (str)
	{
		while (str[i] && str[i] != '\n')
			i++;
	}
	return (i);
}

int	ft_strslen(char **strs)
{
	int	i;

	i = 0;
	if (strs)
	{
		while (strs[i])
			i++;
	}
	return (i);
}

void	ft_free_strs(t_data *data, char **strs)
{
	int	i;

	i = 0;
	if (strs != NULL)
	{
		while (strs[i] != NULL)
		{
			ft_free(data, strs[i]);
			strs[i] = NULL;
			i++;
		}
		ft_free(data, strs);
		strs = NULL;
	}
}

char	*ft_strdup_path(t_data *data, char *s1)
{
	unsigned long	i;
	size_t			len;
	char			*s2;

	if (s1 == NULL)
		return (NULL);
	i = 0;
	len = 0;
	while (s1[len])
		len++;
	s2 = ft_malloc(data, sizeof(char) * (len + 1));
	while (s1[i] && s1[i] != '\n')
	{
		s2[i] = s1[i];
		i++;
	}
	s2[i] = '\0';
	return (s2);
}
