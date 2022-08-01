/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvalenci <jvalenci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 11:32:21 by jvalenci          #+#    #+#             */
/*   Updated: 2022/08/01 16:19:03 by jvalenci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

/* 
inicialize main structures see header file to know more about it,
fetch map size and player position 
*/
void ft_init_struc(t_map *m)
{
	t_sys	*mlx;
	t_img	*img; 
	t_line	*l;
	t_rayc	*ray;

    mlx = malloc(sizeof(t_sys));
	m->textures.char_color = ft_rgb_to_int(123,34,12);
    img = malloc(sizeof(t_img) * 2);
    l = malloc(sizeof(t_line));
    ray = malloc(sizeof(t_rayc));
    if (!mlx || !img || !l || !ray)
		return (perror("Error allocating structures"));
	m->s_img[0] = &img[0];
	m->s_img[1] = &img[1];
	m->s_mlx = mlx;
	m->l = l;
	m->ray = ray;
	m->pps_pix = 32;
	m->l->color = ft_rgb_to_int(242, 160, 160);
    m->l->pa =  (float)(2 * M_PI);
	ft_map_size(m, &m->colums, &m->lines);
    ft_find_player(m);
}