/* ************************************************************************** */ /*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_caster.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvalenci <jvalenci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 10:23:13 by jvalenci          #+#    #+#             */
/*   Updated: 2022/07/26 10:35:50 by jvalenci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

/*
function called by inc_offset in order to calculte the line offset
*/
void line_offset(t_map *m, char type)
{
    m->ray->up = 0;
    m->ray->left = 0;
    if (m->l->pa > (float)M_PI && m->l->pa < (float)(2 * M_PI) && type == 'h')
        m->ray->up = 1;
    if (m->l->pa < (float)PI1 && m->l->pa > (float)PI2 && type == 'v')
        m->ray->left = 1;
}

/*
Increment offset function allow us to increase offset up until we reach a wall
*/
void inc_offset(t_map *m, char type)
{
    int i;

    i = 0;
    line_offset(m, type);
    while (!i)
    {
        m->ray->ax = (int)m->ray->rx >> 5; // x index in map_desc
        m->ray->ay = (int)m->ray->ry >> 5; // y index in map_desc
        if ((int)m->ray->ax >= m->colums - 1 || (int)m->ray->ay 
        >= m->lines - 1 || m->ray->ax < 0 || m->ray->ay < 0 ||
        m->map_desc[m->ray->ay - m->ray->up][m->ray->ax - m->ray->left] 
        == '1' )
            i = 1;
        else
        {
            m->ray->ry += m->ray->yo;
            m->ray->rx += m->ray->xo;
        }
    }
    dist(m, type);
}

/*
gets horizontal raytrace from 0 to PI and from PI to (2 * PI)
--> for a deeper undestanding see the next video:
https://www.youtube.com/watch?v=eOCQfxRQ2pY
*/
void check_h_line(t_map *m)
{
    t_rayc *r;

    r = m->ray;
    if (m->l->pa > M_PI)
    {
        r->atan = -1 / tan(m->l->pa);                          // formula to get x coordinates as per y
        r->ry = (((int)m->l->p_y >> 5) << 5);                  // the nearest y horizontal coordinate line as per the player
        r->rx = ((m->l->p_y - r->ry) * r->atan + (m->l->p_x)); // apply the formula -dy/tan(angle) to get x
        r->yo = -32;                                           // the y offset is -32 as we are pointing upwards
        r->xo = -r->yo * r->atan;                              // the x offset
    }
    else if (m->l->pa < M_PI)
    {
        r->atan = -1 / tan(m->l->pa);
        r->ry = (((int)m->l->p_y >> 5) << 5) + 32; // the nearest y horizontal coordinate when pointing downwards
        r->rx = ((m->l->p_y - r->ry) * r->atan + (m->l->p_x));
        r->yo = 32; // as we are poiting downwards +32 is y offset
        r->xo = -r->yo * r->atan;
    }
    // as we cannot apply the same -dy/tan(angle) formula when angle is pi we set ry and rx to player's position
    if (m->l->pa == 0 || m->l->pa == M_PI || m->l->pa == (float)(2 * M_PI))
    {
        r->ry = m->l->p_y;
        r->rx = m->l->p_x;
    }
    inc_offset(m, 'h');
}

void check_v_line(t_map *m)
{
    t_rayc *r;

    r = m->ray;
    if (m->l->pa > PI1 || m->l->pa < PI2)
    {
        r->ntan = -tan(m->l->pa);                              // formula to get y coordinates as per x
        r->rx = (((int)m->l->p_x >> 5) << 5) + 32;             // the nearest x horizontal coordinate line as per the player
        r->ry = ((m->l->p_x - r->rx) * r->ntan + (m->l->p_y)); // apply the formula to get y
        r->xo = 32;                                            // the x offset is 32 as we are pointing upwards
        r->yo = -r->xo * r->ntan;                              // the y offset
    }
    else if (m->l->pa < PI1 && m->l->pa > PI2)
    {
        r->ntan = -tan(m->l->pa);
        r->rx = (((int)m->l->p_x >> 5) << 5); // the nearest x vertical coordinate when pointing downwards
        r->ry = ((m->l->p_x - r->rx) * r->ntan + (m->l->p_y));
        r->xo = -32; // as we are poiting downwards +32 is y offset
        r->yo = -r->xo * r->ntan;
    }
    inc_offset(m, 'v');
}

void ray_caster(t_map *m)
{
    check_h_line(m);
    check_v_line(m);
}