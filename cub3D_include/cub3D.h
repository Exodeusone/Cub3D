/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julien <julien@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 09:05:57 by jbonniva          #+#    #+#             */
/*   Updated: 2022/03/22 14:57:05 by julien           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <math.h>

typedef struct s_data			t_data;
typedef struct s_map			t_map;
typedef struct s_garb			t_garb;
typedef struct s_player			t_player;
typedef struct s_coor			t_coor;

struct s_garb
{
	void				*point;
	struct s_garb	*next;
};

struct s_coor
{
	int	x;
	int	y;
};


struct s_player
{
	t_coor	coor;
};

struct	s_map
{
	char	*identifier;
	char	*path;
	char	**map;
	t_map	*next;
	t_map	*prev;
};

struct s_data
{
	int			map_height;
	int			map_width;
	int			map_check;
	int			before_map;
	t_garb		*garbage;
	t_map		*map;
	t_player	player;
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

/* CHECK MAP NAME */
int		ft_check_name_map(char *str);
int		ft_check_beggin_name(char *str);
int		ft_check_extention_name(char *str);

/* PARSING MAP */
int		ft_parsing_map(t_data *data, char *str);
int		ft_parse_fd(t_data *data, int fd, char *str);
void	ft_create_map(t_data *data);
void	ft_add_map(t_data *data, char *str);
void	ft_new_map(t_map *map);
int		ft_check_all_identifier(t_data *data);
int		ft_check_identifier_2(t_data *data, char *str);
int		ft_check_identifier_1(t_data *data, char *str);
char	*ft_get_my_path_2(t_data *data, char *str);
char	*ft_get_my_path(char *str);
int		ft_read_fd(t_data *data, int fd);
int		ft_check_read(t_data *data, char *str, int j);
int		ft_get_my_size_map(t_data *data, char *str, int i);
void	ft_malloc_map(t_data *data);
int		ft_first_check(t_data *data);
int		ft_find_identifier(t_data *data, char *str);
int		ft_check_rgb(t_data *data, char *str);
int		ft_check_line(char *str);
void	ft_put_in_area(t_data *data, char *str, int i);
void	ft_create_area(t_data *data, int fd);
int		ft_fill_map(t_data *data, char *str);
int		ft_find_identifier_1(t_data *data, char *str);
int		ft_find_identifier_2(t_data *data, char *str);
int		ft_check_map(t_data *data);
int		ft_check_start(t_data *data, t_map *tmp);
void	ft_replace_space(t_data *data);

#endif
