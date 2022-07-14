/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvalenci <jvalenci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 04:39:56 by nchabli           #+#    #+#             */
/*   Updated: 2022/07/14 16:29:08 by jvalenci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _CUB3D
# define _CUB3D

# include "cub3d.h"
# include "error.h"
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <fcntl.h>
# include <stddef.h>
# include <stdbool.h>
# ifdef __LINUX__
    # include "../linux_mlx/mlx.h"
# else
    # include "../mlx/mlx.h"
#endif


/* mlx enviroment  */
typedef struct  s_sys 
{
	void	*mlx;
	void	*win;
	int		loop;
}               t_sys;

/* structure for image creation  */
typedef struct	s_img
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_img;

/* 2d map information */
typedef struct s_map
{
    char    **map;
    t_sys   *s_mlx;
    t_img   *s_img;
    int     lines;
    int     colums;
}              t_map;



/* tools */
void        ft_error(char *error);
int         control_arg(int argc, char **av);
void        ft_map_size(t_map *mlx, int *cols, int *lines);
int         ft_rgb_to_int(int r, int g, int b);
void        my_mlx_pixel_put(t_img *stru, int x, int y, int color);
void    	create_map(t_map *m);

/* libft */
size_t	    ft_strlen(const char *s);
int         ft_isdigit(int c);
int         ft_is_str_nb(char *str);
char	    *ft_itoa(int n);
int         ft_atoi(const char *str);
void		ft_putchar_fd(char c, int fd);
void		ft_putnbr_fd(int n, int fd);
void		ft_putstr_fd(char *s, int fd);
int			ft_strcmp(const char *s1, const char *s2);
char	    *ft_strjoin(char const *s1, char const *s2);
int         ft_strncmp(const char *s1, const char *s2, size_t n);
char        **ft_split(char const *s, char c);
char	    *ft_strdup(const char *s1);

/* parsing */
char	    *get_file_str(char *file_entry);
int         control_map(char **map);

# endif