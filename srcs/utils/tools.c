/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvalenci <jvalenci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 22:34:06 by jvalenci          #+#    #+#             */
/*   Updated: 2022/07/18 11:44:32 by jvalenci         ###   ########.fr       */
/*                                                                            */ /* ************************************************************************** */

#include "../../includes/cub3d.h"

/* 
inicialize player position in the struc t_line
we do this in order to draw the player after drawing the entire map 
in a allowed place, then move its position x, y independently the map.
*/
void ft_find_player(t_map *m)
{
    int i;
    int j;

    i = 0;
    while (i < m->lines - 1)
    {
        j = 0;
        while (j < m->colums)
        {
            if (m->map[i + 6][j] == 'N')
            {
                m->l->p_x = j * 32;
                m->l->p_y = i * 32;
                break;
            }
            j++;
        }
        i++;
    }
}

int ft_rgb_to_int(int r, int g, int b)
{
	return ((r<<16) + (g<<8) + b);
}

/* 
determines the max with and heigth of the map chart
*/
void    ft_map_size(t_map *m, int *cols, int *lines)
{
    int i;
    int temp;

    i = 5; 
    temp = 0;
    *cols = 0;
    *lines = 0;
    while (m->map[++i])
    {
        temp = ft_strlen(m->map[i]);
        if (temp > *cols)
            *cols = temp;
    }
    *lines = i - 5;
}

/* 
Costumized mlx_pixel_put function in order to write pixels faster
see documentation to know more: 
    https://harm-smits.github.io/42docs/libs/minilibx/getting_started.html
*/
void	my_mlx_pixel_put(t_img *stru, int x, int y, int color)
{
	char	*dst;

    dst = stru->addr + (y * stru->line_length + x * (stru->bits_per_pixel / 8));
    *(unsigned int *)dst = color;
}

/* 
draw a square pipex by pixel, we need to provide x and y coordinates and 
color
*/
void    ft_draw_square(t_map *m, int x, int y, int color)
{
   int i;
   int j;

   i  = 0;
   while (i < m->pps_pix)
   {
       j = 0;
       while (j < m->pps_pix)
       {
           my_mlx_pixel_put(m->s_img, j + x, i + y, color);
           j++;
       }
       i++;
   }
}