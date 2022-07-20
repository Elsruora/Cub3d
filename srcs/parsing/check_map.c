/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchabli <nchabli@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 10:35:45 by nchabli           #+#    #+#             */
/*   Updated: 2022/07/20 11:24:05 by nchabli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int get_map_start(char **map)
{
    t_counter c;

    c.i = 0;
    c.j = 0;
    while (map[c.i])
        c.i++;
    c.i--;
    while ((map[c.i][0] == '1' || map[c.i][0] == ' '
    || map[c.i][0] == '0') && map[c.i])
        c.i--;
    return (c.i + 1);
}

int nb_lines(char **map)
{
    int i;
    
    i = 0;
    while (map[i])
        i++;
    return (i);
}

void    control_chars(char **map)
{
    int     i;
    int     j;
    char    *error_line;

    i = 0;
    error_line = NULL;
    while (i != nb_lines(map) - 1)
    {
        j = 0;
        while (map[i][j] != '\n' && map[i][j])
        {
            if (!does_char_contain(map[i][j], "NSWE01 \n"))
            {
                error_line = ft_strjoin("line ", ft_itoa(i + 1));
                ft_error(BAD_CHAR_ON_MAP, error_line);
            }
            j++;
        }
        i++;
    }
}

int how_much_players(char **map)
{
    int i;
    int j;
    int nb_players;

    i = 0;
    nb_players = 0;
    while (i != nb_lines(map) - 1)
    {
        j = 0;
        while (map[i][j] != '\n' && map[i][j])
        {
            if (does_char_contain(map[i][j], "NSWE"))
                nb_players++;
            j++;
        }
        i++;
    }
    return (nb_players);
}

void    check_map(t_map *m)
{
    int i;
    
    i = get_map_start(m->map);
    m->map_desc = &m->map[i];
    i = 0;
    control_chars(m->map_desc);
    while (m->map_desc[i])
        printf("%s\n", m->map_desc[i++]);
    if (how_much_players(m->map_desc) == 1)
    {
        printf("lalasqdsq");
    }
    else
        ft_error(BAD_PLAYER_NB, NULL);
    
}