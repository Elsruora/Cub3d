/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchabli <nchabli@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 14:30:03 by jvalenci          #+#    #+#             */
/*   Updated: 2022/09/12 16:03:43 by nchabli          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	is_there_wall(t_map *m, int i)
{
	int	next_case_y;
	int	next_case_x;

	next_case_y = 0;
	next_case_x = 0;
	while (i != 0)
	{
		next_case_y = (m->l->p_y + sin(m->l->pa) * i) / m->pps_pix;
		next_case_x = (m->l->p_x + cos(m->l->pa) * i) / m->pps_pix;
		if (!does_char_contain(m->map_desc[next_case_y][next_case_x], "0NSWE")
			|| m->map_desc[next_case_y][next_case_x] == '1')
			return (1);
		next_case_y = (m->l->p_y + sin(m->l->pa)) / m->pps_pix;
		next_case_x = (m->l->p_x + cos(m->l->pa) * i) / m->pps_pix;
		if (!does_char_contain(m->map_desc[next_case_y][next_case_x], "0NSWE")
			|| m->map_desc[next_case_y][next_case_x] == '1')
			return (1);
		next_case_y = (m->l->p_y + sin(m->l->pa) * i) / m->pps_pix;
		next_case_x = (m->l->p_x + cos(m->l->pa)) / m->pps_pix;
		if (!does_char_contain(m->map_desc[next_case_y][next_case_x], "0NSWE")
			|| m->map_desc[next_case_y][next_case_x] == '1')
			return (1);
		i--;
	}
	return (0);
}

void	ft_player_buttons(int key, t_map *m)
{
	int	next_case_y;
	int	next_case_x;
	int	i;

	next_case_y = 0;
	next_case_x = 0;
	i = 0;
	if (key == K_A || key == K_D)
		go_lr(key, m);
	else if (key == K_W)
		go_up(m);
	else if (key == K_S)
		go_down(m);
	else if (key == K_ESC)
	{
		exit(EXIT_FAILURE);
	}
}

int	ft_buttons(int key, t_map *m)
{
	ft_player_buttons(key, m);
	mlx_destroy_image(m->s_mlx->mlx, m->s_img[0]->img);
	mlx_destroy_image(m->s_mlx->mlx, m->s_img[1]->img);
	ft_set_image(m);
	create_map(m);
	ft_draw_player(m);
	mlx_put_image_to_window(m->s_mlx->mlx, m->s_mlx->win, m->s_img[0]->img,
		0, (m->lines * 32));
	mlx_put_image_to_window(m->s_mlx->mlx, m->s_mlx->win, m->s_img[1]->img,
		0, 0);
	mlx_do_sync(m->s_mlx->mlx);
	return (0);
}
