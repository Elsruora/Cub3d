/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvalenci <jvalenci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 11:06:30 by jvalenci          #+#    #+#             */
/*   Updated: 2022/09/16 09:19:43 by jvalenci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

/**
  @brief set roof and floor backgroud
 */
void	draw_backgroud(t_map *m, int x, int y, int color)
{
	int	i;
	int	j;
	int	width;
	int	height;

	i = -1;
	width = (1024);
	height = 448;
	while (++i < height / 2)
	{
		j = -1;
		while (++j < width)
			my_mlx_pixel_put(m->s_img[1], x + j, y + i, color);
	}
}

/**
  @brief  each ray simulating a 3d view 
 */
void	draw_line_h(t_map *m, int x, int y, int *texture)
{
	int	i;
	int	pixel;
	int	c[3];

	i = 0;
	if (m->ray->c_dir == 'v')
		m->ray->tx = (int)(m->l->pdxy[1] * 4) % 64;
	else
		m->ray->tx = (int)(m->l->pdxy[0] * 4) % 64;
	m->ray->ty = m->ray->t_step * m->ray->t_offset;
	while (i < m->ray->line_h)
	{
		pixel = ((int)m->ray->ty * 64 + (int)m->ray->tx) * 3;
		c[0] = texture[pixel + 0];
		c[1] = texture[pixel + 1];
		c[2] = texture[pixel + 2];
		my_mlx_pixel_put(m->s_img[1], x, i + y, \
				choose_color(m, rgb_to_int(c[0], c[1], c[2])));
		i++;
		m->ray->ty += m->ray->t_step;
	}
}
/**
  @brief Draw the entire ray casting view
  @a --> ca is the difference between player direction and fist ray to
  the left  which is 30 degrees or 0.523599 radians
  @a --> fish_eye_effect, we get rid of it,  as the rays in the
  middle are shorter than the fist arrays to the left or right,
  so we use tdist * cos(ca)
  @a --> screen heigth 448
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
	m->ray->t_step = 64.0 / (float)m->ray->line_h;
	m->ray->t_offset = 0;
	if (m->ray->line_h > 448)
	{
		m->ray->t_offset = (m->ray->line_h - 448) / 2.0;
		m->ray->line_h = 448;
	}
	m->ray->line_o = 224 - m->ray->line_h / 2;
	draw_line_h(m, i, m->ray->line_o, choose_texture(m));
}

/**
  @brief Draw each square in the image taking into account the
  pps_pix varible that will be used by ft_draw_square to
  create 31 px squares size
 */

void	create_map(t_map *m)
{
	int	i;
	int	j;

	i = 0;
	if (m->height <= 448 && m->width <= 1024)
	{
		m->pps_pix = 31;
		while (i < m->lines)
		{
			j = 0;
			while (j < m->colums)
			{
				if (m->map_desc[i][j] == '1')
					ft_draw_square(m, j * 32, i * 32, 0x008083);
				else if (does_char_contain(m->map_desc[i][j], "SEW0N"))
					ft_draw_square(m, j * 32, i * 32, \
							add_shadow(0x249EA0, 1.2));
				j++;
			}
			i++;
		}
		m->pps_pix = 32;
	}
}

/**
  @a --> creates player representation
  @a --> set ra(angle) to 30 degrees to the left to start representating
  the player's view which is a 60 degrees field
  @a -->	pixels per degree = (1024/60) 
  @a --> each loop difines a line,  we do all the math in the function
  ray_caster
  @a --> with max(m) we we take the shortest line
  @a --> and we draw it with plot_line in the map
 */

void	ft_draw_player(t_map *m)
{
	int	i;

	i = -1;
	m->pps_pix = 10;
	ft_draw_square(m, m->l->p_x - 5, m->l->p_y - 5, \
			m->t->char_color);
	m->pps_pix = 32;
	m->ray->ra = m->l->pa - (DR * ((1024 / 60) * 30));
	draw_backgroud(m, 0, 0, m->t->ceiler_code);
	draw_backgroud(m, 0, 224, m->t->floor_code);
	while (++i < (1024))
	{
		m->ray->hdist = 10000000;
		m->ray->vdist = 10000000;
		if (m->ray->ra < (float)0)
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
