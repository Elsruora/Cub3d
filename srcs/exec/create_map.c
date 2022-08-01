/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvalenci <jvalenci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 11:06:30 by jvalenci          #+#    #+#             */
/*   Updated: 2022/08/01 18:20:06 by jvalenci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../../includes/cub3d.h"

void    draw_line_h(t_map *m, int x, int y, int color)
{
   int i;
   int j;

   i  = 0;
   while (i < m->ray->line_h)
   {
       j = 0;
       while (j < 16)
       {
           my_mlx_pixel_put(m->s_img[1], j + x, i + y, color);
           j++;
       }
       i++;
   }

}

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
            if (m->map_desc[i][j] == '1')
               ft_draw_square(m, j * 32, i * 32, ft_rgb_to_int(131, 176, 181));
            else if (does_char_contain(m->map_desc[i][j], "NSEW0"))
               ft_draw_square(m, j * 32, i * 32, m->textures.ceiler_code);
            j++;
       }
       i++;
   }
   m->pps_pix = 32;
}

/* 
--> creates player representation
--> set angle 30 degrees to the left to start representating the player's view which is a 
    60 degrees field 
--> each loop difines a line, do all the math with the function ray_caster
--> with max(m) we we take the shortest line
--> and we draw it with plot_line
*/
void ft_draw_player(t_map *m)
{
    int i;

    i = 0;
    m->pps_pix = 10;
    ft_draw_square(m, m->l->p_x - 5, m->l->p_y - 5,
                   m->textures.char_color);
    m->pps_pix = 32;
    m->ray->ra = m->l->pa - (DR * 30); 
    while (i < 60) 
    {
        m->ray->hdist = 10000;
        m->ray->vdist = 10000;
        if (m->ray->ra < 0)
            m->ray->ra += (float)(2 * M_PI);
        if (m->ray->ra > (float)(2 * M_PI))
            m->ray->ra -= (float)(2 * M_PI);
        ray_caster(m);
        max(m);

        m->ray->ca = m->l->pa - m->ray->ra;
        if (m->ray->ca < 0)
            m->ray->ca += (float)(M_PI * 2);
        else if (m->ray->ca > (float)(M_PI * 2))
            m->ray->ca -= (float)(M_PI *2);
        m->ray->tdist *= cos(m->ray->ca);

        m->ray->line_h = (m->pps_pix * 448) / m->ray->tdist;
        if (m->ray->line_h > 448)
            m->ray->line_h = 448;
        m->ray->line_o = 224 - m->ray->line_h / 2;
        draw_line_h(m, i * 16, m->ray->line_o, 0xeb4034);

        printf("tdist: %d\n line_h: %d\n", m->ray->tdist, m->ray->line_h);
        plot_line(m, m->l->p_x, m->l->p_y);
        i++;
        m->ray->ra += DR;
    }
}