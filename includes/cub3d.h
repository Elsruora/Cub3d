/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvalenci <jvalenci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 04:39:56 by nchabli           #+#    #+#             */
/*   Updated: 2022/07/28 14:40:41 by jvalenci         ###   ########.fr       */
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
# include <math.h>
# define PI1 (3 * M_PI) / 2
# define PI2  M_PI / 2
# define DR 0.0174533


# ifdef __LINUX__
    # include "../linux_mlx/mlx.h"

	// keyboard keys
	# define K_ESC 65307
	# define K_W 119 
	# define K_A 97 
	# define K_D 100 
	# define K_S 115 

	// Arrows left up right down
	# define K_LEFT 65361
	# define K_UP 65362
	# define K_RIGHT 65363    
	# define K_DOWN 65364
# else
    # include "../mlx/mlx.h"

	// keyboard keys
	# define K_A 0
	# define K_S 1
	# define K_D 2
	# define K_W 13
    # define ESC 53

	// Arrows left up right down
	# define K_LEFT 123 
	# define K_UP 126 
	# define K_RIGHT 124    
	# define K_DOWN 125 
#endif

typedef struct	s_rayc
{
	float	atan;
	float	ntan;
	float	ry;
	float	rx;
	float	hxy[2];
	float	vxy[2];
	float 	ra;
	int		yo;
	int		xo;
	int		ax;
	int		ay;
	int		hdist;
	int		vdist;
	int		up;
	int		left;
}				t_rayc;

typedef struct s_direction
{
	char	up;
	char	left;
	char	down;
	char	right;
}				t_direction;


typedef struct s_textures
{
    int     ceiler_code;
    int     floor_code;
    int     no_fd;
    int     so_fd;
    int     we_fd;
    int     ea_fd;
	int		char_color;
	char	player_dir;
}              t_textures;

/* 
structure for Bresenham's line algorithm
we will use it to draw lines 
*/
typedef struct	s_line 
{
	float			d;
	float			dx;
	float			dy;
	float			xi;
	float			yi;
	int			x;
	int			y;
	int			color;
	float		p_x;
	float		p_y;
	float			pdxy[2];
	float 		pa;
}				t_line;

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
    char    **map_desc;
    int     lines;
    int     colums;
	int		pps_pix;
	t_rayc	*ray;
    t_sys   *s_mlx;
    t_img   *s_img;
	t_line	*l;
    t_textures textures;
}              t_map;

typedef struct s_counter
{
    int         i;
    int         j;
    int         k;
}              t_counter;

/* CHECKING */
int			check_all_map_file(t_map *m);
void        check_map(t_map *m);
void		check_walls(t_map *m);
void        check_textures_path_and_color (t_map *m);
void        check_textures_name (char **map);
void        ft_error(char *error, char *where);

/* PARSING */
char	    *get_file_str(char *file_entry);
void		ft_init_struc(t_map *m);
void		ft_draw_player(t_map *m);
void		ft_set_image(t_map *m);
int         get_color_code(char *rgb_code);
int         is_color_code (char *code);
int         open_each_texture (t_map *m, char *path, int i);

/* EXECUTION */
int			ft_buttons(int key, t_map *m);
int			ft_close_window(t_map *m);
void		ray_caster(t_map *m);

/* TOOLS */
int         control_arg(int argc, char **av);
void        ft_map_size(t_map *mlx, int *cols, int *lines);
int         ft_rgb_to_int(int r, int g, int b);
void        my_mlx_pixel_put(t_img *stru, int x, int y, int color);
void    	create_map(t_map *m);
void		ft_draw_line(t_map *m, int x, int y, int color);
void		ft_draw_square(t_map *m, int x, int y, int color);
void		plot_line(t_map *m, float x0, float y0);
void		ft_find_player(t_map *m);
float		pythagoras(t_map *m, float *xy0, float *xy1);
void		max(t_map *m);
void		dist(t_map *m, char type);

/* LIBFT */
size_t	    ft_strlen(const char *s);
int         ft_isprint(int c);
int         ft_isdigit(int c);
int         ft_isascii(int c);
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
char        *ft_convert_base(char *nbr, char *base_from, char *base_to);
char        *find_scnd_word(char *line);
int         does_char_contain(char c, char *s);
void		ft_free(void **arr);

# endif