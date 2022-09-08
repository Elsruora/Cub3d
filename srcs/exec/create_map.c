/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchabli <nchabli@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 11:06:30 by jvalenci          #+#    #+#             */
/*   Updated: 2022/09/08 17:55:58 by nchabli          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

/*
The entire players view will have a rage of 60 degrees, we need to break down
the deegres into the screen size, which I personally determined as 1080 so
(60 degrees / 1080) = 18 pixels per deegree.
 */

/* set roof and floor backgroud */
void	draw_backgroud(t_map *m, int x, int y, int color)
{
	int	i;
	int	j;
	int	width;

	i = -1;
	width = (60 * 18);
	while (++i < 224)
	{
		j = -1;
		while (++j < width)
			my_mlx_pixel_put(m->s_img[1], x + j, y + i, color);
	}
}

/* Draw each ray sumulating a 3d view  */
void	draw_line_h(t_map *m, int x, int y, int color)
{
	int	i;

	i = 0;
	while (i < m->ray->line_h)
	{
		my_mlx_pixel_put(m->s_img[1], x, i + y, color);
		i++;
	}
}

/*
	Draw the entire ray casting view
--> ca is the difference between player direction and fist ray to
	the left  which is 30 degrees or 0.523599 radians
--> Then we get rid of the fish eye effect, as the rays in the
	middle are shorter than the fist arrays to the left or right,
	so we use tdist * cos(ca)
--> raycaster screen heigth 448
 */
void	draw_raycaster(t_map *m, int i)
{
	m->ray->ca = m->l->pa - m->ray->ra;
	if (m->ray->ca < 0)
		m->ray->ca += (float)(M_PI * 2);
	else if (m->ray->ca > (float)(M_PI * 2))
		m->ray->ca -= (float)(M_PI * 2);
	m->ray->tdist *= cos(m->ray->ca);
	m->ray->line_h = (m->pps_pix * 448) / m->ray->tdist;
	if (m->ray->line_h > 448)
		m->ray->line_h = 448;
	m->ray->line_o = 224 - m->ray->line_h / 2;
	draw_line_h(m, i, m->ray->line_o, choose_color(m, m->textures.wall_code));
}

/*
Draw each square in the image taking into account the
pps_pix varible will be used by ft_draw_square to create 31 px squares size
*/
void create_map(t_map *m)
{
	int i;
	int j;

	i = 0;
	m->pps_pix = 31;
	while (i < m->lines)
	{
		j = 0;
		while (j < m->colums)
		{
			if (m->map_desc[i][j] == '1')
				ft_draw_square(m, j * 32, i * 32, 0x008083);
			else if (does_char_contain(m->map_desc[i][j], "SEW0N"))
				ft_draw_square(m, j * 32, i * 32, add_shadow(0x249EA0, 1.2));
			j++;
		}
		i++;
	}
	m->pps_pix = 32;
}

/*
--> creates player representation
--> set ra(angle) to 30 degrees to the left to start representating the
	player's view which is a 60 degrees field
--> each loop difines a line,  we do all the math in the function ray_caster
--> with max(m) we we take the shortest line
--> and we draw it with plot_line in the map
*/
void	ft_draw_player(t_map *m)
{
	int	i;

	i = -1;
	m->pps_pix = 10;
	ft_draw_square(m, m->l->p_x - 5, m->l->p_y - 5,
		m->textures.char_color);
	m->pps_pix = 32;
	m->ray->ra = m->l->pa - (DR * (30 * 18));
	draw_backgroud(m, 0, 0, m->textures.ceiler_code);
	draw_backgroud(m, 0, 224, m->textures.floor_code);
	while (++i < (60 * 18))
	{
		m->ray->hdist = 10000;
		m->ray->vdist = 10000;
		if (m->ray->ra < 0)
			m->ray->ra += (float)(2 * M_PI);
		if (m->ray->ra > (float)(2 * M_PI))
			m->ray->ra -= (float)(2 * M_PI);
		ray_caster(m);
		max(m);
		draw_raycaster(m, i);
		plot_line(m, m->l->p_x, m->l->p_y);
		m->ray->ra += DR;
	}
}
