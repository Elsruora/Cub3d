/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvalenci <jvalenci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 11:06:30 by jvalenci          #+#    #+#             */
/*   Updated: 2022/07/20 11:04:44 by jvalenci         ###   ########.fr       */
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
           else if (m->map[i + 6][j] == '0')
               ft_draw_square(m, j * 32, i * 32, ft_rgb_to_int(255, 255, 255));
           else if (m->map[i + 6][j] == 'N')
               ft_draw_square(m, j * 32, i * 32, ft_rgb_to_int(255, 255, 255));
            j++;
       }
       i++;
   }
}

void    ft_draw_player(t_map *m)
{
    m->pps_pix = 10; 
    ft_draw_square(m, m->l->p_x , m->l->p_y,
        m->textures.ceiler_code);
}