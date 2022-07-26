/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dist.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvalenci <jvalenci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 16:06:19 by jvalenci          #+#    #+#             */
/*   Updated: 2022/07/26 21:02:15 by jvalenci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"


/* 
Pythagorean theorem,
https://en.wikipedia.org/wiki/Hypotenuse
*/
float    pythagoras(t_map *m, float *xy0, float *xy1)
{
    float   num;

    num = sqrt((xy1[0] - xy0[0]) * (xy1[0] - xy0[0]) + 
    (xy1[1] - xy0[1]) * (xy1[1] - xy0[1]));
    if ((m->ray->ax < 0 || m->ray->ay < 0) || (m->ray->ax > m->colums - 1 
    || m->ray->ay > m->lines - 1))
        num = 10000;
    return (num);
}

/* 
Calculates hdist and vdist which is the hypotenuse
or the distance between the player and the wall
*/
void    dist(t_map *m, char type)
{   
    t_rayc  *r; 
    float   xy0[2];

    r = m->ray;
    xy0[0] = m->l->p_x;
    xy0[1] = m->l->p_y;
    if (type == 'h')
    {
        r->hxy[0] = r->rx;
        r->hxy[1] = r->ry;
        r->hdist = pythagoras(m, xy0, r->hxy);
    }
    else if (type == 'v')
    {
        r->vxy[0] = r->rx;
        r->vxy[1] = r->ry;
        r->vdist = pythagoras(m, xy0, r->vxy);
    }
}

/* 
Set minimum  distance between hdist and vdist 
*/
void max(t_map *m)
{
    if (m->ray->hdist < m->ray->vdist)
    {
        m->l->pdxy[0] = m->ray->hxy[0];
        m->l->pdxy[1] = m->ray->hxy[1];
    }
    else
    {
        m->l->pdxy[0] = m->ray->vxy[0];
        m->l->pdxy[1] = m->ray->vxy[1];
    }
}