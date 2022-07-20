/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchabli <nchabli@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 11:06:30 by jvalenci          #+#    #+#             */
/*   Updated: 2022/07/20 15:14:53 by nchabli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../../includes/cub3d.h"

/* 
draw each square in the image taking into account the type of sprite
*/
void    create_map(t_map *m)
{
   int i;
   int  j;

   i = 0;
   m->pps_pix = 31;
   while (i < m->lines - 1)
   {
       j = 0;
       while (j < m->colums)
       {
            if (m->map[i + 6][j] == '1')
               ft_draw_square(m, j * 32, i * 32, ft_rgb_to_int(131, 176, 181));
            else if (does_char_contain(m->map_desc[i][j], "NSEW0"))
               ft_draw_square(m, j * 32, i * 32, m->textures.ceiler_code);
            else if (does_char_contain(m->map_desc[i][j], "0"))
                ft_draw_square(m, j * 32, i * 32, ft_rgb_to_int(131, 50, 181));

            j++;
       }
       i++;
   }
}

void    ft_draw_player(t_map *m)
{
    m->pps_pix = 20;
    ft_draw_square(m, m->l->p_x , m->l->p_y,
        m->textures.floor_code);
}