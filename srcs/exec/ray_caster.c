/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_caster.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvalenci <jvalenci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 10:23:13 by jvalenci          #+#    #+#             */
/*   Updated: 2022/07/21 16:18:33 by jvalenci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"


void inc_offset(t_map *m)
{
    int i;

    i = 0;
    while (i < m->lines)
    {
        if (((int)m->ray->rx >> 5) > 0 || ((int)m->ray->ry >> 5) > 0)
        {
            m->ray->ax = (int)m->ray->rx >> 5;
            m->ray->ay = (int)m->ray->ry >> 5;
            if ((m->ray->ax > m->colums - 1 && m->ray->ay > m->lines) ||
                m->map_desc[m->ray->ay - 1][m->ray->ax] == '1')
                i = m->lines;
            else
            {
                m->ray->ry += m->ray->yo;
                m->ray->rx += m->ray->xo;
                i++;
            }
        }
        else
            break;
    }
}

void check_h_line(t_map *m)
{
    t_rayc *r;

    r = m->ray;
    if (m->l->pa > M_PI)
    {
        r->atan = -1 / tan(m->l->pa);
        r->ry = (((int)m->l->p_y >> 5) << 5);
        r->rx = ((m->l->p_y - r->ry) * r->atan + (m->l->p_x));
        r->yo = -32;
        r->xo = -r->yo * r->atan;
    }
    else if (m->l->pa < PI)
    {
        r->atan = -1 / tan(m->l->pa);
        r->ry = (((int)m->l->p_y >> 5) << 5) + 32;
        r->rx = ((m->l->p_y - r->ry) * r->atan + (m->l->p_x ));
        r->yo = 32;
        r->xo = -r->yo * r->atan;
    }
    if (m->l->pa == 0 || m->l->pa == (2 * PI) || m->l->pa == PI)
    {
       r->rx = m->l->p_x; 
       r->ry = m->l->p_y;
    }
    inc_offset(m);
}

/* void check_h_line(t_map *m)
{

} */