/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_all.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchabli <nchabli@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 10:05:31 by nchabli           #+#    #+#             */
/*   Updated: 2022/07/20 15:19:34 by nchabli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../../includes/cub3d.h"

int check_all_map_file(t_map *m)
{
    check_textures_name(m->map);
    check_textures_path_and_color(m);
    check_map(m);
    return (0);
}
