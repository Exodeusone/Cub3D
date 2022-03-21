/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exodeus <exodeus@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 09:54:04 by jbonniva          #+#    #+#             */
/*   Updated: 2022/03/21 22:03:57 by exodeus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3D_include/cub3D.h"

int	ft_strncmp(char *s1, char *s2, int n)
{
	int	i;

	i = 0;
	if (n == 0)
		return (0);
	while (s1[i] != '\0' && s2[i] != '\0' && s1[i] == s2[i] && i < n - 1)
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strdup(t_data *data, char *s1)
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
	while (s1[i])
	{
		s2[i] = s1[i];
		i++;
	}
	s2[i] = '\0';
	return (s2);
}

int	ft_strcmp(char *str_one, char *str_two)
{
	int	i;

	i = 0;
	while (str_two[i])
	{
		if (str_two[i] == str_one[i])
			i++;
		else
			return (str_one[i] - str_two[i]);
	}
	return (0);
}