/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_all.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvalenci <jvalenci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 10:05:31 by nchabli           #+#    #+#             */
/*   Updated: 2022/07/19 16:50:47 by jvalenci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../../includes/cub3d.h"

int check_all_map_file(t_map m)
{
    check_textures_name(m.map);
    check_textures_path_and_color(&m);
    // check_map(m);
    return (0);
}
