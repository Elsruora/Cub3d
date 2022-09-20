/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_walls.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchabli <nchabli@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 09:40:14 by nchabli           #+#    #+#             */
/*   Updated: 2022/09/20 17:56:14 by jvalenci         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	is_good_around(char **map, int x, int y)
{
	t_direction	dir;

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
	if (does_char_contain(map[x][y], "0NSWE") && dir.down && dir.left \
			&& dir.right && dir.up)
	{
		if (!does_char_contain(dir.down, "10NSWE") || \
				!does_char_contain(dir.up, "10NSWE") || \
				!does_char_contain(dir.left, "10NSWE") || \
				!does_char_contain(dir.right, "10NSWE"))
			ft_error(BAD_WALL, NULL);
	}
	else
		ft_error(BAD_WALL, ft_strjoin("line ", ft_itoa(x)));
}

void	check_walls(t_map *m)
{
	t_counter	c;

	c.i = 0;
	while (m->map_desc[c.i + 1])
	{
		c.j = 0;
		while (m->map_desc[c.i][c.j])
		{
			if (does_char_contain(m->map_desc[c.i][c.j], "0NSWE"))
				is_good_around(m->map_desc, c.i, c.j);
			c.j++;
		}
		c.i++;
	}
	c.j = 0;
	while (m->map_desc[c.i][c.j])
	{
		if (m->map_desc[c.i][c.j] == '0' || m->map_desc[c.i][c.j] == 'N')
			ft_error(BAD_WALL, ft_strjoin("line ", ft_itoa(c.i)));
		c.j++;
	}
}
