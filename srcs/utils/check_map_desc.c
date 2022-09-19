/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_desc.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvalenci <jvalenci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 16:27:12 by jvalenci          #+#    #+#             */
/*   Updated: 2022/09/19 16:34:43 by jvalenci         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	check_map_desc_len(char **map)
{
	int	i;

	i = 0;
	while (map[i])
		i++;
	if (i < 3)
		ft_error(BAD_WALL, NULL);
}
