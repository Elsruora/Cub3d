/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_caster.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvalenci <jvalenci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 11:08:03 by jvalenci          #+#    #+#             */
/*   Updated: 2022/09/16 09:21:27 by jvalenci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

/**
 @brief function called by inc_offset in order to calculte the line offset
*/

void	line_offset(t_map *m, char type)
{
	m->ray->up = 0;
	m->ray->left = 0;
	if (m->ray->ra > (float)M_PI && m->ray->ra < (float)(2 * M_PI)
		&& type == 'h')
		m->ray->up = 1;
	if (m->ray->ra < (float)PI1 && m->ray->ra > (float)PI2 && type == 'v')
		m->ray->left = 1;
}

/**
	@brief Increment offset function allow us to increase offset up until 
	we reach a wall
*/

void	inc_offset(t_map *m, char type)
{
	int	i;

	i = 0;
	line_offset(m, type);
	while (!i)
	{
		m->ray->ax = (int)m->ray->rx >> 5;
		m->ray->ay = (int)m->ray->ry >> 5;
		if (((int)m->ray->ax >= m->colums - 1 || (int)m->ray->ay >= m->lines - 1
				|| m->ray->ax < 0 || m->ray->ay < 0)
			|| m->map_desc[m->ray->ay - m->ray->up]
			[m->ray->ax - m->ray->left] == '1')
			i = 1;
		else
		{
			m->ray->ry += m->ray->yo;
			m->ray->rx += m->ray->xo;
		}
	}
	dist(m, type);
}

/**
 @brief gets horizontal raytrace from 0 to PI and from PI to (2 * PI)
		--> for a deeper undestanding see the next video:
		https://www.youtube.com/watch?v=eOCQfxRQ2pY
*/

void	check_h_line(t_map *m)
{
	t_rayc	*r;

	r = m->ray;
	if (r->ra > M_PI)
	{
		r->atan = -1 / tan(r->ra);
		r->ry = (((int)m->l->p_y >> 5) << 5);
		r->rx = ((m->l->p_y - r->ry) * r->atan + (m->l->p_x));
		r->yo = -32;
		r->xo = -r->yo * r->atan;
	}
	else if (r->ra < M_PI)
	{
		r->atan = -1 / tan(r->ra);
		r->ry = (((int)m->l->p_y >> 5) << 5) + 32;
		r->rx = ((m->l->p_y - r->ry) * r->atan + (m->l->p_x));
		r->yo = 32;
		r->xo = -r->yo * r->atan;
	}
	if (r->ra == 0 || r->ra == M_PI || r->ra == (float)(2 * M_PI))
	{
		r->ry = m->l->p_y;
		r->rx = m->l->p_x;
	}
	inc_offset(m, 'h');
}

void	check_v_line(t_map *m)
{
	t_rayc	*r;

	r = m->ray;
	if (r->ra > PI1 || r->ra < PI2)
	{
		r->ntan = -tan(r->ra);
		r->rx = (((int)m->l->p_x >> 5) << 5) + 32;
		r->ry = ((m->l->p_x - r->rx) * r->ntan + (m->l->p_y));
		r->xo = 32;
		r->yo = -r->xo * r->ntan;
	}
	else if (r->ra < PI1 && r->ra > PI2)
	{
		r->ntan = -tan(r->ra);
		r->rx = ((int)m->l->p_x >> 5) << 5;
		r->ry = ((m->l->p_x - r->rx) * r->ntan + (m->l->p_y));
		r->xo = -32;
		r->yo = -r->xo * r->ntan;
	}
	if (r->ra == (float)PI1 || r->ra == (float)PI2)
	{
		r->ry = m->l->p_y;
		r->rx = m->l->p_x;
	}
	inc_offset(m, 'v');
}

void	ray_caster(t_map *m)
{
	check_h_line(m);
	check_v_line(m);
}
