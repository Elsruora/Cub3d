/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvalenci <jvalenci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 10:32:44 by jvalenci          #+#    #+#             */
/*   Updated: 2022/09/16 09:28:10 by jvalenci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	plot_line_low(t_map *m, float *xy0, float *xy1)
{
	m->l->dx = xy1[0] - xy0[0];
	m->l->dy = xy1[1] - xy0[1];
	m->l->yi = 1;
	if (m->l->dy < 0)
	{
		m->l->yi = -1;
		m->l->dy *= -1;
	}
	m->l->d = (2 * m->l->dy) - m->l->dx;
	m->l->x = xy0[0];
	m->l->y = xy0[1];
	while (m->l->x < xy1[0])
	{
		my_mlx_pixel_put(m->s_img[0], m->l->x, m->l->y, \
				choose_color(m, m->t->wall_code));
		if (m->l->d > 0)
		{
			m->l->y += m->l->yi;
			m->l->d += (2 * (m->l->dy - m->l->dx));
		}
		else
			m->l->d += (2 * m->l->dy);
		m->l->x++;
	}
}

void	plot_line_hight(t_map *m, float *xy0, float *xy1)
{
	m->l->dx = xy1[0] - xy0[0];
	m->l->dy = xy1[1] - xy0[1];
	m->l->xi = 1;
	if (m->l->dx < 0)
	{
		m->l->xi = -1;
		m->l->dx *= -1;
	}
	m->l->d = (2 * m->l->dx) - m->l->dy;
	m->l->y = xy0[1];
	m->l->x = xy0[0];
	while (m->l->y < xy1[1])
	{
		my_mlx_pixel_put(m->s_img[0], m->l->x, m->l->y, \
				choose_color(m, m->t->wall_code));
		if (m->l->d > 0)
		{
			m->l->x += m->l->xi;
			m->l->d += (2 * (m->l->dx - m->l->dy));
		}
		else
			m->l->d += (2 * m->l->dx);
		m->l->y++;
	}
}

/**
   @brief Bresenham's line algorithm is a line drawing algorithm that determines
		   the points of an n-dimensional raster that should be selected in order
		   to form a close approximation to a straight line between two points.
		   It is commonly used to draw line primitives in a bitmap image

   --->    https://en.wikipedia.org/wiki/Bresenham%27s_line_algorithm
*/
void	plot_line(t_map *m, float x0, float y0)
{
	float	xy0[2];

	xy0[0] = x0;
	xy0[1] = y0;
	if (m->height <= 448 && m->width <= 1024)
	{
		if (abs((int)m->l->pdxy[1] - (int)xy0[1]) < \
				abs((int)m->l->pdxy[0] - (int)xy0[0]))
		{
			if (xy0[0] > m->l->pdxy[0])
				plot_line_low(m, m->l->pdxy, xy0);
			else
				plot_line_low(m, xy0, m->l->pdxy);
		}
		else
		{
			if (xy0[1] > m->l->pdxy[1])
				plot_line_hight(m, m->l->pdxy, xy0);
			else
				plot_line_hight(m, xy0, m->l->pdxy);
		}
	}
}
