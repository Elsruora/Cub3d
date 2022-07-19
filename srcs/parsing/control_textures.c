/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control_textures.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchabli <nchabli@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 16:05:16 by nchabli           #+#    #+#             */
/*   Updated: 2022/07/18 17:41:28 by nchabli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../../includes/cub3d.h"

char    *find_scnd_word(char *line)
{
    int     i;
    
    i = 0;
    while (line[i] && line[i] == ' ')
        i++;
    while (ft_isprint(line[i]))
        i++;
    while (line[i] == ' ')
        i++;
    return (line + i);
}

int open_each_texture (t_map *m, char *path, int i)
{
    if (ft_strncmp(m->map[i], "NO ", 3))
    {
        m->textures.no_fd = open(path, O_RDONLY);
        return (m->textures.no_fd);
    }
    else if (ft_strncmp(m->map[i], "SO ", 3))
    {
        m->textures.so_fd = open(path, O_RDONLY);
        return (m->textures.so_fd);
    }
    else if (ft_strncmp(m->map[i], "WE ", 3))
    {
        m->textures.we_fd = open(path, O_RDONLY);
        return (m->textures.we_fd);
    }
    else if (ft_strncmp(m->map[i], "EA ", 3))
    {
        m->textures.ea_fd = open(path, O_RDONLY);
        return (m->textures.ea_fd);
    }
    else
    ft_error("LALALALA", NULL);
        return (0);
}

void check_textures_name (char **map)
{
    if (!map[0][3] || !map[1][3] || !map[2][3] || !map[3][3])
        ft_error(TEXTURE_ERROR, NULL);
    if (ft_strncmp(map[0], "NO ", 3) || ft_strncmp(map[1], "SO ", 3) 
        || ft_strncmp(map[2], "WE ", 3) || ft_strncmp(map[3], "EA ", 3)
        || ft_strncmp(map[4], "F ", 2) || ft_strncmp(map[5], "C ", 2))
        ft_error(TEXTURE_NAME_ERROR, NULL);
}

void check_textures_path_and_color (t_map *m)
{
    int i;
    
    i = -1;
    while (++i <= 3)
    { 
        if(open_each_texture(m, find_scnd_word(m->map[i]), i) == -1)
            ft_error(BAD_TEXTURE_PATH, find_scnd_word(m->map[i]));
    }
    i--;
    while (++i <= 5)
    {
        if (!is_color_code(find_scnd_word(m->map[i])))
            ft_error(BAD_COLOR_CODE, find_scnd_word(m->map[i]));
        if (i == 4)
            m->textures.floor_code = get_color_code(m->map[i]);
        if (i == 5)
            m->textures.ceiler_code = get_color_code(m->map[i]);
    }
}
