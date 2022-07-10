/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchabli <nchabli@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 16:05:16 by nchabli           #+#    #+#             */
/*   Updated: 2022/07/08 17:29:47 by nchabli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../../includes/cub3d.h"

int check_textures (char **map)
{
    if (!map[0][3] || !map[1][3] || !map[2][3] || !map[3][3])
        ft_error(TEXTURE_ERROR);
    if (ft_strncmp(map[0], "NO ", 3) || ft_strncmp(map[1], "SO ", 3) 
        || ft_strncmp(map[2], "WE ", 3) || ft_strncmp(map[3], "EA ", 3)
        || ft_strncmp(map[4], "F ", 2) || ft_strncmp(map[5], "C ", 2))
        ft_error(TEXTURE_NAME_ERROR);
    return(0);
}

int control_map(char **map)
{
    check_textures(map);
    return (0);
}