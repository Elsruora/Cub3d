/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvalenci <jvalenci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 15:07:46 by jvalenci          #+#    #+#             */
/*   Updated: 2022/09/09 15:11:24 by jvalenci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void    init_texture(t_map *m)
{
    m->textures.t_north = filter_rgb_file(FNORTH);
    m->textures.t_south = filter_rgb_file(FSOUTH);
    m->textures.t_west = filter_rgb_file(FWEST);
    m->textures.t_east = filter_rgb_file(FEAST);
}