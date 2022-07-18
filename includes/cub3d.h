/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchabli <nchabli@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 04:39:56 by nchabli           #+#    #+#             */
/*   Updated: 2022/07/13 10:38:47 by nchabli          ###   ########.fr       */
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

typedef struct s_textures
{
    char    *ceiler_code;
    char    *floor_code;
    int     no_fd;
    int     so_fd;
    int     we_fd;
    int     ea_fd;
}              t_textures;

typedef struct s_map
{
    char        **map;
    t_textures  textures;
    
}              t_map;

typedef struct s_counter
{
    int         i;
    int         j;
    int         k;
    
}              t_counter;


void        ft_error(char *error, char *where);
int         control_arg(int argc, char **av);

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

/* CHECKING */

int         check_all_map_file(t_map m);
void        check_map(t_map m);
void        check_textures_path_and_color (t_map *m);
void        check_textures_name (char **map);


char	    *get_file_str(char *file_entry);
int         control_map(t_map map);
char        *get_color_code(char *rgb_code);
int         is_color_code (char *code);
int         open_each_texture (t_map *m, char *path, int i);

# endif