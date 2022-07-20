/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control_textures.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchabli <nchabli@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 16:05:16 by nchabli           #+#    #+#             */
/*   Updated: 2022/07/20 19:40:09 by nchabli          ###   ########.fr       */
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

void    check_textures_doublons(char **map)
{
    int i;
    int comb;

    i = 0;
    comb = 1;
    while (i < 6)
    {
        if (!ft_strncmp(map[i], "NO ", 3))
            comb *= 7;
        else if (!ft_strncmp(map[i], "SO ", 3))
            comb *= 2;
        else if (!ft_strncmp(map[i], "WE ", 3))
            comb *= 87;
        else if (!ft_strncmp(map[i], "EA ", 3))
            comb *= 8;
        else if (!ft_strncmp(map[i], "F ", 2))
            comb *= 19;
        else if (!ft_strncmp(map[i], "C ", 2))
            comb *= 4;
        i++;
    }
    if (comb != 740544)
        ft_error(DOUBL_ON_TEXTURES, NULL);
}

void check_textures_name (char **map)
{
    int i;

    i = 0;
    if (!map[0][3] || !map[1][3] || !map[2][3] || !map[3][3])
        ft_error(TEXTURE_ERROR, NULL);
    while (i < 6)
    {
        if (ft_strncmp(map[i], "NO ", 3) && ft_strncmp(map[i], "SO ", 3) 
            && ft_strncmp(map[i], "WE ", 3) && ft_strncmp(map[i], "EA ", 3)
            && ft_strncmp(map[i], "F ", 2) && ft_strncmp(map[i], "C ", 2))
            ft_error(TEXTURE_NAME_ERROR, map[i]);
        i++;
    }
    check_textures_doublons(map);
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
