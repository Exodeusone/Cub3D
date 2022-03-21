/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbonniva <jbonniva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 09:05:57 by jbonniva          #+#    #+#             */
/*   Updated: 2022/03/21 16:17:38 by jbonniva         ###   ########.fr       */
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
typedef	struct s_map			t_map;
typedef struct s_garbage		t_garbage;

struct s_garbage
{
	void				*point;
	struct s_garbage	*next;
};

struct	s_map{
	char	*identifier;
	char	*path;
	char	**map;
	t_map	*next;
	t_map	*prev;
};

struct s_data{
	t_garbage	*garbage;
	t_map		*map;
};

/* MAIN */
int	main(int argc, char **argv);

/* GNL */
char	*get_next_line(int fd);
char	*ft_read_buf(int fd, char *statical);
char	*ft_statical_to_line(char *statical);
char	*ft_statical_to_statical(char *statical);
int		ft_statical_chr(char *s, int c);
char	*ft_statical_buf_join(char *statical, char *buf);
char	*ft_cpy_in_join(char *statical, char *buf, char *new_statical);
char	*ft_statical_cpy(char *line, char *statical);
int		ft_len(char *s);

/* GARBAGE COLLECTOR */
int			init_garbage(t_data *data);
t_garbage	*last_garbage(t_garbage *garbage);
int			add_garbage(t_data *data, void *new);
void		*ft_malloc(t_data *data, size_t size);
void		ft_free(t_data *data, void *pointer);
void		clear_garbage(t_data *data);
void		ft_free_garb(t_garbage *garb);

/* UTILS */
int		ft_strncmp(char *s1, char *s2, int n);
int		ft_strlen(char *s);
void	ft_puterr(char *s);
void	ft_putmsg(char *s);
char	*ft_strdup(t_data *data, char *s1);
int		ft_strcmp(char *str_one, char *str_two);

/* CHECK MAP NAME */
int		ft_check_name_map(char *str);
int		ft_check_beggin_name(char *str);
int		ft_check_extention_name(char *str);

/* PARSING MAP */
int		ft_parsing_map(t_data *data, char *str);
void	ft_create_map(t_data *data);
void	ft_add_map(t_data *data, char *str);
void	ft_new_map(t_map *map);

#endif
