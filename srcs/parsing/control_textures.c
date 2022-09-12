/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control_textures.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvalenci <jvalenci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 16:05:16 by nchabli           #+#    #+#             */
/*   Updated: 2022/09/12 10:56:05 by jvalenci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../../includes/cub3d.h"

char    *find_scnd_word(char *line)
{
    int     i; i = 0;
    while (line[i] && line[i] == ' ')
        i++;
    while (ft_isprint(line[i]))
        i++;
    while (line[i] == ' ')
        i++;
    return (line + i);
}

void check_texture_ext(char *path)
{
    char    extension[5];
    int     i;
    int     j;
    
    j = 0;
    i = 4;
    if (path[4])
    {
        while(i)
            extension[j++] = path[ft_strlen(path) - i--];
        extension[4] = '\0';
        if (ft_strcmp(extension, ".xpm"))  
            ft_error(WRONG_TEXTURE_EXT, path);
    }
}

int    open_one_texture(char *path)
{
    int fd;
    check_texture_ext(path);
    if (open(path, O_DIRECTORY) != -1)
		ft_error(PATH_IS_DIRECTORY, "textures");
    fd = open(path, O_RDONLY);
    return (fd);
}

int open_each_texture (t_map *m, char *path, int i)
{
    if (ft_strncmp(m->map[i], "NO ", 3))
    {
        m->t->no_fd = open_one_texture(path);
        return (m->t->no_fd);
    }
    else if (ft_strncmp(m->map[i], "SO ", 3))
    {
        m->t->so_fd = open_one_texture(path);
        return (m->t->so_fd);
    }
    else if (ft_strncmp(m->map[i], "WE ", 3))
    {
        m->t->we_fd = open_one_texture(path);
        return (m->t->we_fd);
    }
    else if (ft_strncmp(m->map[i], "EA ", 3))
    {
        m->t->ea_fd = open_one_texture(path);
        return (m->t->ea_fd);
    }
    else
        return (0);
}

void    check_textures_doublons(char **map)
{
    int i;
    int comb;

    i = 0;
    comb = 0;
    while (i < 6)
    {
        if (!ft_strncmp(map[i], "NO ", 3))
            comb += 3;
        else if (!ft_strncmp(map[i], "SO ", 3))
            comb += 5;
        else if (!ft_strncmp(map[i], "WE ", 3))
            comb += 7;
        else if (!ft_strncmp(map[i], "EA ", 3))
            comb += 11;
        else if (!ft_strncmp(map[i], "F ", 2))
            comb += 13;
        else if (!ft_strncmp(map[i], "C ", 2))
            comb += 17;
        i++;
    }
    if (comb != 56)
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
            m->t->floor_code = get_color_code(m->map[i]);
        if (i == 5)
            m->t->ceiler_code = get_color_code(m->map[i]);
    }
}
