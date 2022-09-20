/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchabli <nchabli@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 11:32:21 by jvalenci          #+#    #+#             */
/*   Updated: 2022/09/20 17:30:05 by nchabli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

/** 
  @brief determines player's inicial potition
  */
float	player_direction(char c)
{
	if (c == 'N')
		return ((float)PI1);
	else if (c == 'S')
		return ((float)PI2);
	else if (c == 'E')
		return ((float)(2 * M_PI));
	else
		return ((float)(M_PI));
}

/** 
  @brief inicialize main structures see header file to know more about it,
  fetch map size and player position 
  */
void	ft_init_struc(t_map *m)
{
	t_sys		*mlx;
	t_img		*img;
	t_line		*l;
	t_rayc		*ray;
	t_textures	*t;

	t = malloc(sizeof(t_textures));
	mlx = malloc(sizeof(t_sys));
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
	m->t = t;
	m->pps_pix = 32;
	m->l->pa = (float)(2 * M_PI);
}
