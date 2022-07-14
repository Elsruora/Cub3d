/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvalenci <jvalenci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 22:34:06 by jvalenci          #+#    #+#             */
/*   Updated: 2022/07/14 17:03:26 by jvalenci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"


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
	*(unsigned int*)dst = color;
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
   while (i < 30)
   {
       j = 0;
       while (j < 30)
       {
           my_mlx_pixel_put(m->s_img, j + x, i + y, color);
           j++;
       }
       i++;
   }
}

/* 
draw each square in the image taking into account the type of sprite
*/
void    create_map(t_map *m)
{
   int i;
   int  j;

   i = 0;
   while (i < m->lines - 1)
   {
       j = 0;
       while (j < m->colums)
       {
           if (m->map[i + 6][j] == '1')
               ft_draw_square(m, j * 32, i * 32, ft_rgb_to_int(131, 176, 181));
           else if (m->map[i + 6][j] == '0')
               ft_draw_square(m, j * 32, i * 32, ft_rgb_to_int(255, 255, 255));
           else if (m->map[i + 6][j] == 'N')
               ft_draw_square(m, j * 32, i * 32, ft_rgb_to_int(226, 83, 69));
            j++;
       }
       i++;
   }
}