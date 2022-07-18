/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvalenci <jvalenci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 11:32:21 by jvalenci          #+#    #+#             */
/*   Updated: 2022/07/18 16:36:12 by jvalenci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

/* 
inicialize main structures see header file to know more about it,
fetch map size and player position 
*/
void ft_init_struc(t_map *m)
{
	t_sys *mlx;
	t_img *img; 
	t_line *l;

    mlx = malloc(sizeof(t_sys));
    img = malloc(sizeof(t_img));
    l = malloc(sizeof(t_line));
    if (!mlx || !img || !l)
		return (perror("Error allocating structures"));
	m->s_img = img;
	m->s_mlx = mlx;
	m->l = l;
	m->pps_pix = 32;
	m->l->color = ft_rgb_to_int(242, 160, 160);
	m->l->pi = 3.14159265359; 
    m->l->pa =  (2 * m->l->pi);
	ft_map_size(m, &m->colums, &m->lines);
    ft_find_player(m);
}