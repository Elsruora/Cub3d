/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control_textures2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchabli <nchabli@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 14:22:13 by nchabli           #+#    #+#             */
/*   Updated: 2022/09/20 17:58:52 by jvalenci         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	check_textures_name(char **map)
{
	int	i;

	i = 0;
	if (!map[0][3] || !map[1][3] || !map[2][3] || !map[3][3])
		ft_error(TEXTURE_ERROR, NULL);
	while (i < 6)
	{
		if (ft_strncmp(map[i], "NO ", 3) && ft_strncmp(map[i], "SO ", 3) \
				&& ft_strncmp(map[i], "WE ", 3) && \
				ft_strncmp(map[i], "EA ", 3) && ft_strncmp(map[i], "F ", 2) \
				&& ft_strncmp(map[i], "C ", 2))
			ft_error(TEXTURE_NAME_ERROR, map[i]);
		i++;
	}
	check_textures_doublons(map);
}

void	check_textures_path_and_color(t_map *m)
{
	int	i;

	i = -1;
	while (++i <= 3)
		open_each_texture(m, find_scnd_word(m->map[i]), i);
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
