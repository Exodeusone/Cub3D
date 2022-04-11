/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: upean-de <upean-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 09:05:57 by jbonniva          #+#    #+#             */
/*   Updated: 2022/04/06 15:16:04 by upean-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

# include "../mlx/mlx.h"
# include "../mlx/mlx_int.h"
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <math.h>

typedef struct s_data			t_data;
typedef struct s_fd				t_fd;
typedef struct s_garb			t_garb;
typedef struct s_player			t_player;
typedef struct s_asset			t_asset;
typedef struct s_rgb			t_rgb;
typedef struct s_path			t_path;
typedef struct s_display		t_display;
typedef struct s_move			t_move;

# define SCREEN_W 960
# define SCREEN_H 960

struct s_garb
{
	void			*point;
	struct s_garb	*next;
};

struct s_move
{
	int	up;
	int	down;
	int	right;
	int	left;
	int	rr;
	int	rl;
};

struct s_rgb
{
	int	red;
	int	green;
	int	blue;
};

struct	s_fd
{
	char	*identifier;
	char	*path;
	char	**map;
	t_fd	*next;
	t_fd	*prev;
};

struct s_asset
{
	void	*img;
	int		width;
	int		height;
	int		*addr;
	int		bits_per_pixel;
	int		size_line;
	int		endian;
};

struct s_path
{
	char	*north;
	char	*south;
	char	*east;
	char	*west;
};

struct s_display
{
	float	wall_x;
	int		tex_x;
	int		tex_y;
	float	tex_pos;
	float	step;
	int		line_height;
	int		draw_start;
	int		draw_end;
	int		tex_dir;
};

struct s_player
{
	float	pos_x;
	float	pos_y;
	float	dir_x;
	float	dir_y;
	float	plane_x;
	float	plane_y;
	float	ray_dir_x;
	float	ray_dir_y;
	int		map_x;
	int		map_y;
	float	side_dist_x;
	float	side_dist_y;
	float	delta_dist_x;
	float	delta_dist_y;
	float	perp_wall_dist;
	int		step_x;
	int		step_y;
	int		hit;
	int		side;
	float	move_speed;
	float	rot_speed;
};

struct s_data
{
	int			map_height;
	int			map_width;
	int			map_check;
	int			before_map;
	char		*err;
	void		*mlx;
	void		*win;
	char		**map;
	t_path		path;
	t_rgb		cell;
	t_rgb		floor;
	t_garb		*garbage;
	t_fd		*fd;
	t_player	player;
	t_asset		asset[5];
	t_display	display;
	t_move		move;
};

/* MAIN */
int		main(int argc, char **argv);

/* GNL */
char	*get_next_line(t_data *data, int fd);
int		ft_strchr(char *s, int c);

/* GARBAGE COLLECTOR */
int		init_garbage(t_data *data);
t_garb	*last_garbage(t_garb *garbage);
int		add_garbage(t_data *data, void *new);
void	*ft_malloc(t_data *data, size_t size);
void	ft_free(t_data *data, void *pointer);
void	clear_garbage(t_data *data);
void	ft_free_garb(t_garb *garb);

/* UTILS */
int		ft_strncmp(char *s1, char *s2, int n);
int		ft_strlen(char *s);
void	ft_puterr(char *s);
void	ft_putmsg(char *s);
char	*ft_strjoin(t_data *data, char *s1, char *s2);
char	*ft_strdup(t_data *data, char *s1);
int		ft_strcmp(char *str_one, char *str_two);
char	**ft_split(t_data *data, char *s, char c);
void	ft_free_strs(t_data *data, char **strs);
int		ft_strslen(char **strs);
int		ft_atoi(const char *str);
int		ft_strlen_rgb(char *str);
char	*ft_strdup_path(t_data *data, char *s1);

/* CHECK MAP NAME */
int		ft_check_name_map(char *str);
int		ft_check_beggin_name(char *str);
int		ft_check_extention_name(char *str);

/* PARSING MAP */
int		ft_parsing_map(t_data *data, char *str);
int		ft_parse_fd(t_data *data, int fd, char *str);
void	ft_create_map(t_data *data);
void	ft_add_map(t_data *data, char *str);
void	ft_new_map(t_fd *map);
int		ft_check_all_identifier(t_data *data);
int		ft_check_identifier_1(t_data *data, char *str);
char	*ft_get_my_path_2(t_data *data, char *str, char c);
char	*ft_get_my_path(char *str);
int		ft_read_fd(t_data *data, int fd);
int		ft_check_read(t_data *data, char *str, int j);
int		ft_get_my_size_map(t_data *data, char *str, int i);
void	ft_malloc_map(t_data *data);
int		ft_first_check(t_data *data);
int		ft_find_identifier(t_data *data, char *str);
int		ft_check_rgb(t_data *data, char *str, char c);
int		ft_check_line(char *str);
void	ft_put_in_area(t_data *data, char *str, int i);
void	ft_create_area(t_data *data, int fd);
int		ft_fill_map(t_data *data, char *str);
int		ft_find_identifier_1(t_data *data, char *str);
int		ft_check_identifier_2(t_data *data, char *str, char c);
int		ft_check_map(t_data *data);
int		ft_check_start(t_data *data, t_fd *tmp);
void	ft_replace_space(t_data *data);
void	ft_add_rgb(t_data *data, int color, char c, int i);
void	ft_get_data_map(t_data *data, t_fd *fd);
void	ft_clear_fd(t_data *data);
void	ft_get_fd(t_data *data);
int		ft_is_in_map(t_data *data, char c);

/* CUB3D */
void	cub3d(t_data *data);
void	draw_ceiling(t_data *data, int x);
void	draw_floor(t_data *data, int x);
int		ft_exit(t_data *data);
void	ft_init_start_angle(t_data *data, char c);
void	get_coor(t_data *data);
void	init_assets(t_data *data);
void	ft_get_addr(t_data *data);
void	ft_get_xpm(t_data *data);
void	look_right(t_data *data);
void	look_left(t_data *data);
void	move_up(t_data *data);
void	move_down(t_data *data);
void	move_right(t_data *data);
void	move_left(t_data *data);
int		key_hook(int keycode, t_data *data);
int		create_trgb(int t, int r, int g, int b);
int		draw_ray(t_data *data);
void	move(t_data *data);
int		key_init(int keycode, t_data *data);
int		key_reset(int keycode, t_data *data);
int		ft_draw_ray2(t_data *data);
void	ft_draw_ray3(t_data *data);
void	ft_draw_ray4(t_data *data);
void	ft_draw_ray5(t_data *data);
int		ft_draw_ray6(t_data *data);
void	ft_draw_ray7(t_data *data, int y, int x);

#endif
