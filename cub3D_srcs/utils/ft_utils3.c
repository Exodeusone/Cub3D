/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julien <julien@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 22:57:53 by julien            #+#    #+#             */
/*   Updated: 2022/04/04 22:58:18 by julien           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3D_include/cub3D.h"

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
