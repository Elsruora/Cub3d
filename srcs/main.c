/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvalenci <jvalenci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 04:35:19 by nchabli           #+#    #+#             */
/*   Updated: 2022/09/20 18:36:39 by jvalenci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	ft_close_window(t_map *m)
{
	int	i;

	ft_free((void **)m->map);
	free(m->buffer);
	mlx_destroy_image(m->s_mlx->mlx, m->s_img[0]->img);
	mlx_destroy_image(m->s_mlx->mlx, m->s_img[1]->img);
	mlx_clear_window(m->s_mlx->mlx, m->s_mlx->win);
	mlx_destroy_window(m->s_mlx->mlx, m->s_mlx->win);
	free(m->l);
	free(m->s_mlx);
	free(m->ray);
	i = north;
	while (i <= west)
		free(m->t->textures[i++]);
	free(m->t->textures);
	free(m->t);
	exit(0);
	return (0);
}

void	ft_set_window(t_map *m)
{
	m->s_mlx->mlx = mlx_init();
	m->s_mlx->win = mlx_new_window(m->s_mlx->mlx, 1024,
			(448) * 2, "Cub3d");
}

void	ft_set_image(t_map *m)
{
	int	i;

	i = -1;
	while (++i < 2)
	{
		m->s_img[i]->img = mlx_new_image(m->s_mlx->mlx, 1024,
				448);
		m->s_img[i]->addr = mlx_get_data_addr(m->s_img[i]->img,
				&m->s_img[i]->bits_per_pixel, &m->s_img[i]->line_length,
				&m->s_img[i]->endian);
	}
}

int	main(int ac, char **av)
{
	t_map	m;

	control_arg(ac, av);
	ft_init_struc(&m);
	m.buffer = get_file_str(av[1]);
	m.map = ft_split(m.buffer, '\n');
	check_all_map_file(&m);
	init_texture(&m);
	ft_map_size(&m, &m.colums, &m.lines);
	ft_find_player(&m);
	ft_set_window(&m);
	ft_set_image(&m);
	create_map(&m);
	ft_draw_player(&m);
	mlx_put_image_to_window(m.s_mlx->mlx, m.s_mlx->win, m.s_img[1]->img, \
			0, 0);
	mlx_put_image_to_window(m.s_mlx->mlx, m.s_mlx->win, m.s_img[0]->img, \
			0, 448);
	mlx_hook(m.s_mlx->win, 2, 1L << 0, ft_buttons, &m);
	mlx_hook(m.s_mlx->win, 17, 0, ft_close_window, &m);
	m.s_mlx->loop = mlx_loop(m.s_mlx->mlx);
	return (0);
}
