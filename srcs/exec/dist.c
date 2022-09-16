/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dist.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvalenci <jvalenci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 16:06:19 by jvalenci          #+#    #+#             */
/*   Updated: 2022/09/16 09:19:49 by jvalenci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

/**
 @param Pythagorean_theorem,
		https://en.wikipedia.org/wiki/Hypotenuse
*/
float	pythagoras(t_map *m, float *xy0, float *xy1)
{
	float	num;

	num = sqrt((xy1[0] - xy0[0]) * (xy1[0] - xy0[0])
			+ (xy1[1] - xy0[1]) * (xy1[1] - xy0[1]));
	if ((m->ray->ax < 0 || m->ray->ay < 0) || (m->ray->ax > m->colums - 1
			|| m->ray->ay > m->lines - 1) || (m->l->p_y < m->ray->ry
			&& m->ray->ra < (float)(2 * M_PI) && m->ray->ra > (float)M_PI) ||
		(m->l->p_y > m->ray->ry && m->ray->ra > 0 && m->ray->ra < (float)M_PI))
		num = 10000;
	return (num);
}

/**
 @brief Calculates hdist and vdist which is the hypotenuse
		or the distance between the player and the wall
*/
void	dist(t_map *m, char type)
{
	t_rayc	*r;
	float	xy0[2];

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

/**
	@brief Set minimum distance between hdist and vdist
*/
void	max(t_map *m)
{
	if (m->ray->hdist < m->ray->vdist)
	{
		m->l->pdxy[0] = m->ray->hxy[0];
		m->l->pdxy[1] = m->ray->hxy[1];
		m->ray->tdist = m->ray->hdist;
		m->ray->c_dir = 'h';
	}
	else if (m->ray->vdist < m->ray->hdist)
	{
		m->l->pdxy[0] = m->ray->vxy[0];
		m->l->pdxy[1] = m->ray->vxy[1];
		m->ray->tdist = m->ray->vdist;
		m->ray->c_dir = 'v';
	}
}
