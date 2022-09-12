/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchabli <nchabli@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 15:07:46 by jvalenci          #+#    #+#             */
/*   Updated: 2022/09/12 14:47:59 by nchabli          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	init_texture(t_map *m)
{
	m->t->char_color = rgb_to_int(123, 34, 12);
	m->t->wall_code = rgb_to_int(217, 72, 125);
	m->t->t_north = filter_rgb_file(FNORTH);
	m->t->t_south = filter_rgb_file(FSOUTH);
	m->t->t_west = filter_rgb_file(FWEST);
	m->t->t_east = filter_rgb_file(FEAST);
}

/**
   @param return texture taking into account the players direction
*/
int	*choose_texture(t_map *m)
{
	if (m->ray->c_dir == 'v' && (m->ray->ra > PI1 || m->ray->ra < PI2))
		return (m->t->t_east);
	else if (m->ray->c_dir == 'v' && (m->ray->ra < PI1 && m->ray->ra > PI2))
		return (m->t->t_west);
	else if (m->ray->c_dir == 'h' && m->ray->ra > M_PI)
		return (m->t->t_north);
	else if (m->ray->c_dir == 'h' && m->ray->ra < M_PI)
		return (m->t->t_south);
	return (NULL);
}
