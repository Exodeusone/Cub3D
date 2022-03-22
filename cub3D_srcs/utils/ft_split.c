/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julien <julien@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 11:19:43 by upean-de          #+#    #+#             */
/*   Updated: 2022/03/22 14:42:19 by julien           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3D_include/cub3D.h"

static int	count_word(char *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i] && s[i] == c)
		i++;
	while (s[i])
	{
		count++;
		while (s[i] && s[i] != c)
			i++;
		while (s[i] && s[i] == c)
			i++;
	}
	return (count);
}

static int	len_word(int i, char *s, char c)
{
	int	count;

	count = 0;
	while (s[i] == c)
		i++;
	while (s[i] && s[i] != c)
	{
		i++;
		count++;
	}
	return (count);
}

static int	cpy_word(int i, char *src, char *dst, char c)
{
	int	j;

	j = 0;
	while (src[i] && src[i] == c)
		i++;
	while (src[i] && src[i] != c)
	{
		dst[j] = src[i];
		i++;
		j++;
	}
	dst[j] = '\0';
	return (i);
}

static void	free_strs(t_data *data, char **strs)
{
	int	i;

	i = 0;
	while (strs[i])
	{
		ft_free(data, strs[i]);
		i++;
	}
	ft_free(data, strs);
}

char	**ft_split(t_data *data, char *s, char c)
{
	char	**strs;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (s == NULL)
		return (NULL);
	strs = ft_malloc(data, sizeof(char *) * (count_word((char *)s, c) + 1));
	if (!strs)
		return (NULL);
	while (j < count_word((char *)s, c))
	{
		strs[j] = ft_malloc(data, sizeof(char)
				* (len_word(i, (char *)s, c) + 1));
		if (!strs[j])
		{
			free_strs(data, strs);
			return (NULL);
		}
		i = cpy_word(i, (char *)s, strs[j], c);
		j++;
	}
	strs[j] = NULL;
	return (strs);
}
