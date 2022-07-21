/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchabli <nchabli@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 04:39:56 by nchabli           #+#    #+#             */
/*   Updated: 2022/07/21 10:13:21 by nchabli          ###   ########.fr       */
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

# ifdef __LINUX__
    # include "../linux_mlx/mlx.h"
# else
    # include "../mlx/mlx.h"
#endif

# ifdef __LINUX__
	// keyboard keys
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

/* 
--> atan = -1/tan(angle) this will help us find a x coordinate in a horizontal or 
  vertical line
--> ry = is y's nearest coordinate to a horizontal or vertical line, 
  taking into account the angle
--> xy = is x's nearest coordinate to a horizontal or vertical line, 
  taking into account the angle
-->yo y offset
-->xo x offset
 */

typedef struct	s_rayc
{
	float atan;
	int ry;
	int rx;
	int	yo;
	int xo;
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
}              t_textures;

/* 
structure for Bresenham's line algorithm
we will use it to draw lines 
*/
typedef struct	s_line 
{
	int		d;
	int		dx;
	int		dy;
	int		xi;
	int		yi;
	int		x;
	int		y;
	int		color;
	int		p_x;
	int		p_y;
	int		pdxy[2];
	double 	pa;
	double	pi;
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

/* TOOLS */
int         control_arg(int argc, char **av);
void        ft_map_size(t_map *mlx, int *cols, int *lines);
int         ft_rgb_to_int(int r, int g, int b);
void        my_mlx_pixel_put(t_img *stru, int x, int y, int color);
void    	create_map(t_map *m);
void		ft_draw_line(t_map *m, int x, int y, int color);
void		ft_draw_square(t_map *m, int x, int y, int color);
void		plot_line(t_map *m, int x0, int y0, double angle_r);
void		ft_find_player(t_map *m);

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

/* CHECKING */
int         check_all_map_file(t_map *m);
void        check_map(t_map *m);
void        check_textures_path_and_color (t_map *m);
void        check_textures_name (char **map);
void    	check_walls(t_map *m);
void        ft_error(char *error, char *where);

# endif