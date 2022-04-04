/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julien <julien@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 10:18:22 by upean-de          #+#    #+#             */
/*   Updated: 2022/04/04 21:27:09 by julien           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3D_include/cub3D.h"

float	dist(t_data *data, float bx, float by, float ang)
{
	float	a;
	float	b;

	(void)ang;
	a = bx - data->player.x;
	b = by - data->player.y;
	return (sqrt(a * a + b * b));
}

void	draw_ray(t_data	*data, char **map)
{
	int		r;
	int		r_limit;
	float	a_tan;
	float	n_tan;
	float	ca;

	r = 0;
	r_limit = 60 * 4;
	a_tan = 0;
	n_tan = 0;
	data->player.ra = data->player.angle - DR * 30;
	if (data->player.ra <= 0)
		data->player.ra += 2 * PI;
	if (data->player.ra > 2 * PI)
		data->player.ra -= 2 * PI;
	while (r < r_limit)
	{
		data->player.dof = 0;
		data->player.disH = 1000000;
		data->player.hx = data->player.x;
		data->player.hy = data->player.y;
		a_tan = -1 / tan(data->player.ra);
		if (data->player.ra > PI)
		{
			data->player.ry = (((int)data->player.y >> 6) << 6) - 0.0001;
			data->player.rx = (data->player.y - data->player.ry) * a_tan + data->player.x;
			data->player.yo = -64;
			data->player.xo = -data->player.yo * a_tan;
		}
		if (data->player.ra < PI)
		{
			data->player.ry = (((int)data->player.y >> 6) << 6) + 64;
			data->player.rx = (data->player.y - data->player.ry) * a_tan + data->player.x;
			data->player.yo = 64;
			data->player.xo = -data->player.yo * a_tan;
		}
		if (data->player.ra == 0 || data->player.ra == PI)
		{
			data->player.rx = data->player.x;
			data->player.ry = data->player.y;
			data->player.dof = data->map_height;
		}
		while (data->player.dof < data->map_height)
		{
			data->player.mx = (int) data->player.rx >> 6;
			data->player.my = (int) data->player.ry >> 6;
			if (data->player.mx >= 0 && data->player.mx < data->map_width
				&& data->player.my >= 0 && data->player.my < data->map_height
				&& map[data->player.my][data->player.mx] == '1')
			{
				data->player.dof = data->map_height;
				data->player.hx = data->player.rx;
				data->player.hy = data->player.ry;
				data->player.disH = dist(data, data->player.hx, data->player.hy, data->player.ra);
			}
			else
			{
				data->player.rx += data->player.xo;
				data->player.ry += data->player.yo;
				data->player.dof++;
			}
		}
		data->player.dof = 0;
		data->player.disV = 1000000;
		data->player.vx = data->player.x;
		data->player.vy = data->player.y;
		n_tan = -tan(data->player.ra);
		if (data->player.ra > P2 && data->player.ra < P3)
		{
			data->player.rx = (((int)data->player.x >> 6) << 6) - 0.0001;
			data->player.ry = (data->player.x - data->player.rx) * n_tan + data->player.y;
			data->player.xo = -64;
			data->player.yo = -data->player.xo * n_tan;
		}
		if (data->player.ra < P2 || data->player.ra > P3)
		{
			data->player.rx = (((int)data->player.x >> 6) << 6) + 64;
			data->player.ry = (data->player.x - data->player.rx) * n_tan + data->player.y;
			data->player.xo = 64;
			data->player.yo = -data->player.xo * n_tan;
		}
		if (data->player.ra == 0 || data->player.ra == PI)
		{
			data->player.rx = data->player.x;
			data->player.ry = data->player.y;
			data->player.dof = data->map_height;
		}
		while (data->player.dof < data->map_width)
		{
			data->player.mx = (int) data->player.rx >> 6;
			data->player.my = (int) data->player.ry >> 6;
			if (data->player.mx >= 0 && data->player.mx < data->map_width
				&& data->player.my >= 0 && data->player.my < data->map_height
				&& map[data->player.my][data->player.mx] == '1')
			{
				data->player.dof = data->map_width;
				data->player.vx = data->player.rx;
				data->player.vy = data->player.ry;
				data->player.disV = dist(data, data->player.vx, data->player.vy, data->player.ra);
			}
			else
			{
				data->player.rx += data->player.xo;
				data->player.ry += data->player.yo;
				data->player.dof++;
			}
		}
		if (data->player.disV < data->player.disH)
		{
			data->player.rx = data->player.vx;
			data->player.ry = data->player.vy;
			data->player.disT = data->player.disV;
			data->player.side = 1;
		}
		if (data->player.disV > data->player.disH)
		{
			data->player.rx = data->player.hx;
			data->player.ry = data->player.hy;
			data->player.disT = data->player.disH;
			data->player.side = 0;
		}
		ca = data->player.angle - data->player.ra;
		if (ca < 0)
			ca += 2 * PI;
		if (ca > 2 * PI)
			ca -= 2 * PI;
		data->player.disT = data->player.disT* cos(ca);
		r++;
		draw_direction(data);
		draw_3d(data, r, r_limit);
		data->player.ra += DR / 4;
		if (data->player.ra <= 0)
			data->player.ra += 2 * PI;
		if (data->player.ra > 2 * PI)
			data->player.ra -= 2 * PI;
	}
	ft_draw_player_front(data);
	ft_draw_player_left(data);
	ft_draw_player_right(data);
	mlx_put_image_to_window(data->mlx, data->win, data->asset[0].img, 0, 0);
	mlx_put_image_to_window(data->mlx, data->win2, data->asset[1].img, 0, 0);
	mlx_destroy_image(data->mlx, data->asset[0].img);
	mlx_destroy_image(data->mlx, data->asset[1].img);
}
