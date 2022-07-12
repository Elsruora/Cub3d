/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvalenci <jvalenci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 22:34:06 by jvalenci          #+#    #+#             */
/*   Updated: 2022/07/12 22:56:01 by jvalenci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void    ft_map_size(t_map *m, int *cols, int *lines)
{
    int i;
    int temp;

    i = 5; 
    temp = 0;
    *cols = 0;
    *lines = 0;
    while (m->map[++i])
    {
        temp = ft_strlen(m->map[i]);
        if (temp > *cols)
            *cols = temp;
    }
    *lines = i - 5;
}