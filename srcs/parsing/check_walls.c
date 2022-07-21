/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_walls.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchabli <nchabli@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 09:40:14 by nchabli           #+#    #+#             */
/*   Updated: 2022/07/21 10:32:55 by nchabli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void    is_good_around(char **map, int x, int y)
{
    t_direction dir;
    
    dir.down = 0;
    dir.up = 0;
    dir.left = 0;
    dir.right = 0;
    if (map[x - 1][y])
        dir.up = map[x - 1][y];
    if (map[x][y + 1])
        dir.right = map[x][y + 1];
    if (map[x + 1][y])
        dir.down = map[x + 1][y];
    if (map[x][y - 1])
        dir.left = map[x][y - 1];
    if (map[x][y] == '0' && dir.down && dir.left && dir.right && dir.up)
    {
        printf("x : %d, y : %d\n", x, y);
        if (!does_char_contain(dir.down, "10NSWE")
            || !does_char_contain(dir.up, "10NSWE")
            || !does_char_contain(dir.left, "10NSWE")
            || !does_char_contain(dir.right, "10NSWE"))
                ft_error (BAD_WALL, NULL);
    }
    else
        ft_error(BAD_WALL, ft_strjoin("line ", ft_itoa(x - 1)));
}

void    check_walls(t_map *m)
{
    t_counter       c;
    c.i = 0;
    while(m->map_desc[c.i])
    {
        c.j = 0;
        while(m->map_desc[c.i][c.j])
        {
            if (m->map_desc[c.i][c.j] == '0')
                is_good_around(m->map_desc, c.i, c.j);
            c.j++;
        }
        c.i++;
    }
}