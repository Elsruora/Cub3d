/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchabli <nchabli@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 04:35:19 by nchabli           #+#    #+#             */
/*   Updated: 2022/07/26 11:30:29 by nchabli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../includes/cub3d.h"

int	ft_close_window(t_map *m)
{
	ft_free((void**)m->map);
    mlx_destroy_image(m->s_mlx->mlx, m->s_img->img);
	mlx_clear_window(m->s_mlx->mlx, m->s_mlx->win);
	mlx_destroy_window(m->s_mlx->mlx, m->s_mlx->win);
	free(m->s_img);
	free(m->l);
	free(m->s_mlx);
	free(m->ray);
	exit(0);
	return (0);
}

void	ft_set_window(t_map *m)
{
	m->s_mlx->mlx = mlx_init(); 
	m->s_mlx->win = mlx_new_window(m->s_mlx->mlx, m->colums * m->pps_pix,
	m->lines * m->pps_pix, "Cub3d");
}

void ft_set_image(t_map *m)
{
	m->s_img->img = mlx_new_image(m->s_mlx->mlx, m->colums * 32,
	m->lines * 32);
	m->s_img->addr = mlx_get_data_addr(m->s_img->img,
	 &m->s_img->bits_per_pixel, &m->s_img->line_length, &m->s_img->endian);
}

int main(int ac, char **av)
{
	t_map m;

 	control_arg(ac, av);
	m.map = ft_split(get_file_str(av[1]), '\n');
	check_all_map_file(&m);
	ft_init_struc(&m);
	ft_set_window(&m);
	ft_set_image(&m);
	create_map(&m);
	ft_draw_player(&m);
	mlx_put_image_to_window(m.s_mlx->mlx, m.s_mlx->win, m.s_img->img, 0, 0);
	mlx_hook(m.s_mlx->win, 2, 1L << 0, ft_buttons, &m);
	mlx_hook(m.s_mlx->win, 17, 0, ft_close_window, &m);
	m.s_mlx->loop = mlx_loop(m.s_mlx->mlx);
	return (0);
}