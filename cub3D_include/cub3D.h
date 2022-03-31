/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julien <julien@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 09:05:57 by jbonniva          #+#    #+#             */
/*   Updated: 2022/03/31 22:20:15 by julien           ###   ########.fr       */
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
typedef struct s_cleaner		t_cleaner;
typedef struct s_asset			t_asset;
typedef struct s_rgb			t_rgb;
typedef struct s_path			t_path;

# define PI 3.14159265359
# define MAP_S 64
# define P2 PI/2
# define P3 3*PI/2
# define DR 0.0174533
# define SCREEN_W 960
# define SCREEN_H 960

struct s_rgb
{
	int	red;
	int	green;
	int	blue;
};

struct s_garb
{
	void				*point;
	struct s_garb	*next;
};

struct s_player
{
	float	x;
	float	y;
	float	dx;
	float	dy;
	float	angle;
	int		mx;
	int		my;
	int		dof;
	float	rx;
	float	ry;
	float	ra;
	float	xo;
	float	yo;
	float	disH;
	float	hx;
	float	hy;
	float	disV;
	float	vx;
	float	vy;
	float	disT;
	int		side;
};

struct	s_fd
{
	char	*identifier;
	char	*path;
	char	**map;
	t_fd	*next;
	t_fd	*prev;
};

struct s_cleaner
{
	float	x;
	float	y;
	float	ra;
	float	ry;
	float	dy;
	t_cleaner	*next;
	t_cleaner	*prev;
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
	char *north;
	char *south;
	char *east;
	char *west;
};


struct s_data
{
	int			map_height;
	int			map_width;
	int			map_check;
	int			before_map;
	void		*mlx;
	void		*win;
	void		*win2;
	char		**map;
	t_path		path;
	t_rgb		cell;
	t_rgb		floor;
	t_garb		*garbage;
	t_fd		*fd;
	t_player	player;
	t_cleaner	*cleaner;
	t_asset		asset[4];
};

/* MAIN */
int		main(int argc, char **argv);

/* GNL */
char		*get_next_line(t_data *data, int fd);
int			ft_strchr(char *s, int c);


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

/* MINIMAP */
void	init_minimap(t_data *data);
int		key_hook(int keycode, t_data *data);
void	erase_player(t_data *data);
void	draw_direction(t_data *data);
void	draw_player(t_data *data);
void	draw_wall(t_data *data, int x, int y);
void	draw_map(t_data *data, char **map);
int		create_trgb(int t, int r, int g, int b);
int		ft_exit(t_data *data);
void	erase_direction(t_data *data, t_cleaner *tmp);
void	draw_ray(t_data	*data, char **map);
void	add_cleaner(t_data *data);
void	ft_clean_cleaner(t_data *data);
int		ok_move_up(t_data *data);
int		ok_move_down(t_data *data);
int		ok_move_side(t_data *data, float dx, float dy);
void	draw_3d(t_data *data, int r, int r_limit);
void	init_assets(t_data *data);

#endif
