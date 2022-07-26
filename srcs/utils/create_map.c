/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchabli <nchabli@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 11:06:30 by jvalenci          #+#    #+#             */
/*   Updated: 2022/07/26 14:09:08 by nchabli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../../includes/cub3d.h"

/* 
draw each square in the image taking into account the type of sprite
pps_pix varible will be used by ft_draw_square to create 31 px squares size
*/
void    create_map(t_map *m)
{
   int i;
   int  j;

   i = 0;
   m->pps_pix = 31;
   while (i < m->lines)
   {
       j = 0;
       while (j < m->colums)
       {
            if (m->map[i + 6][j] == '1')
               ft_draw_square(m, j * 32, i * 32, ft_rgb_to_int(131, 176, 181));
            else if (does_char_contain(m->map_desc[i][j], "NSEW0"))
               ft_draw_square(m, j * 32, i * 32, m->textures.ceiler_code);
            j++;
       }
       i++;
   }
}

/* 
as we want to mesure correctly the player's position we substract 5 so we draw the player
at the beginning of the square provided as argument
--> see find_player function to undestand more about player's position and mesurements
 */
void ft_draw_player(t_map *m)
{
    ray_caster(m);
    m->pps_pix = 10;
    ft_draw_square(m, m->l->p_x - 5, m->l->p_y - 5,
                   m->textures.char_color);

    printf("ry: %f\n rx: %f\n yo: %d\n xo: %d\n pa %f\n", m->ray->ry, m->ray->rx, m->ray->xo,
           m->ray->yo, m->l->pa);
    if ((m->ray->ax < 0 || m->ray->ay < 0) || (m->ray->ax > m->colums - 1 || m->ray->ay > m->lines - 1))
        return;
    plot_line(m, m->l->p_x, m->l->p_y, m->l->pa);
}