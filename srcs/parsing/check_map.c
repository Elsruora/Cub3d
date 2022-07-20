/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchabli <nchabli@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 10:35:45 by nchabli           #+#    #+#             */
/*   Updated: 2022/07/20 10:11:53 by nchabli          ###   ########.fr       */
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

void    check_map(t_map *m)
{
    int i;
    
    i = get_map_start(m->map);
    m->map_desc = &m->map[i];
    printf("%s\n", m->map[0]);
}