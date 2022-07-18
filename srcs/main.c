/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchabli <nchabli@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 04:35:19 by nchabli           #+#    #+#             */
/*   Updated: 2022/07/18 13:05:06 by nchabli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	ft_set_window(t_map *m)
{
	t_sys *mlx = malloc(sizeof(t_sys));
	t_img *img = malloc(sizeof(t_img));

	if (!mlx || !img)
		return (perror("Error allocating structures"));
	m->s_img = img;
	m->s_mlx = mlx;
	ft_map_size(m, &m->colums, &m->lines);
	m->s_mlx->mlx = mlx_init(); 
	m->s_mlx->win = mlx_new_window(m->s_mlx->mlx, m->colums * 64, m->lines * 64,
	 "Cub3d");
	m->s_img->img = mlx_new_image(m->s_mlx->mlx, m->colums * 32, m->lines * 32);
	m->s_img->addr = mlx_get_data_addr(m->s_img->img, &m->s_img->bits_per_pixel,
	&m->s_img->line_length, &m->s_img->endian);
	create_map(m);
	mlx_put_image_to_window(m->s_mlx->mlx, m->s_mlx->win, m->s_img->img, 0, 0);
}

int main(int ac, char **av)
{
	t_map m;
	// int i = -1; 

 	control_arg(ac, av);
	m.map = ft_split(get_file_str(av[1]), '\n');
	control_map(m);
	ft_set_window(&m);
	mlx_loop(m.s_mlx->mlx);
/* 	while (m.map[++i])
		printf("%s\n", m.map[i]); */
	return (0);
}
