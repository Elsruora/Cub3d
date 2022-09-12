/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_all.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchabli <nchabli@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 10:05:31 by nchabli           #+#    #+#             */
/*   Updated: 2022/09/12 14:46:52 by nchabli          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	check_all_map_file(t_map *m)
{
	check_textures_name(m->map);
	check_textures_path_and_color(m);
	check_map(m);
	check_walls(m);
	return (0);
}
