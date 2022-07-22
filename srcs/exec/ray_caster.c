/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_caster.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvalenci <jvalenci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 10:23:13 by jvalenci          #+#    #+#             */
/*   Updated: 2022/07/22 23:49:09 by jvalenci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

/* 
set map array offeset when we are pointing upwards or downwards
*/
int up_down(t_map *m)
{
    if (m->l->pa > (float)M_PI && m->l->pa < (float)(2 * M_PI))
        return (1);
    else
        return (0);
}

/* 
Increment offset function allow us to increase offset up until we reach a wall
*/
void inc_offset(t_map *m, int up)
{
    int i;

    i = 0;
    while (i < m->lines) // So far as we have just implemented horizontal raytracer we use m->lines
    {
        m->ray->ax = (int)m->ray->rx >> 5; // x index in map_desc
        m->ray->ay = (int)m->ray->ry >> 5;// y index in map_desc
        if ((m->ray->ax < 0 || m->ray->ay < 0))
        {
            m->ray->dist = 10000;
            return ;
        }
        if ((abs(m->ray->ax) >= m->colums - 1 || abs(m->ray->ay) >=m->lines) ||
            m->map_desc[m->ray->ay - up][m->ray->ax] == '1')
            i = m->lines;
        else
        {
            m->ray->ry += m->ray->yo;
            m->ray->rx += m->ray->xo;
            i++;
        }
    }
}

/* 
gets horizontal raytrace when 0 to PI and from PI to (2 * PI) 
--> for a deeper undestanding see the next video:
https://www.youtube.com/watch?v=eOCQfxRQ2pY
*/
void check_h_line(t_map *m)
{
    t_rayc *r;

    r = m->ray;
    if (m->l->pa > M_PI)
    {
        r->atan = -1 / tan(m->l->pa);// formula to get x coordinates as per y
        r->ry = (((int)m->l->p_y >> 5) << 5); // the nearest y horizontal coordinate line as per the player
        r->rx = ((m->l->p_y - r->ry) * r->atan + (m->l->p_x)); //apply the formula -dy/tan(angle) to get x
        r->yo = -32; //the y offset is -32 as we are pointing upwards 
        r->xo = -r->yo * r->atan; // the x offset
    }
    else if (m->l->pa < M_PI)
    {
        r->atan = -1 / tan(m->l->pa);
        r->ry = (((int)m->l->p_y >> 5) << 5) + 32; // the nearest y horizontal coordinate when pointing downwards
        r->rx = ((m->l->p_y - r->ry) * r->atan + (m->l->p_x ));
        r->yo = 32; // as we are poiting downwards +32 is y offset
        r->xo = -r->yo * r->atan;
    }
    // As we cannot apply the same -dy/tan(angle) formula when angle is pi we set ry and rx to player's position
    if (m->l->pa == 0 || m->l->pa == M_PI || m->l->pa == (float)(2 * M_PI)) 
    {
        r->ry = m->l->p_y;
        r->rx = m->l->p_x;
    }
    inc_offset(m, up_down(m));
}