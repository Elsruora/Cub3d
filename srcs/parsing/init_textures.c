/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvalenci <jvalenci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 15:07:46 by jvalenci          #+#    #+#             */
/*   Updated: 2022/09/15 19:23:17 by jvalenci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void    init_texture(t_map *m)
{
	m->t->char_color = rgb_to_int(123,34,12);
	m->t->wall_code = rgb_to_int( 217, 72, 125);
    m->t->textures = malloc(4 * sizeof(int*));
    if (!m->t->textures)
        return ; 
    m->t->textures[north] = filter_rgb_file(FNORTH);
    m->t->textures[south] = filter_rgb_file(FSOUTH);
    m->t->textures[east] = filter_rgb_file(FEAST);
    m->t->textures[west] = filter_rgb_file(FWEST);
}

/** 
   @param return texture taking into account the players direction
*/
int *choose_texture(t_map *m)
{
    if (m->ray->c_dir == 'v' && (m->ray->ra > PI1 || m->ray->ra < PI2))
        return (m->t->textures[east]);
    else if (m->ray->c_dir == 'v' && (m->ray->ra < PI1 && m->ray->ra > PI2))
        return (m->t->textures[west]);
    else if (m->ray->c_dir == 'h' && m->ray->ra > M_PI)
        return (m->t->textures[north]);
    else if (m->ray->c_dir == 'h' && m->ray->ra < M_PI)
        return (m->t->textures[south]);
    return (NULL);
}