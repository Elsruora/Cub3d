/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchabli <nchabli@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 14:30:03 by jvalenci          #+#    #+#             */
/*   Updated: 2022/07/20 19:07:30 by nchabli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void    ft_player_buttons(int key, t_map *m)
{
    if (key == K_A)
    {
        m->l->pa -= 0.1;
        if (m->l->pa < 0)
            m->l->pa = (2 * m->l->pi);
    }
    else if (key == K_D)
    {
        m->l->pa += 0.1;
        if (m->l->pa > (2 * m->l->pi))
            m->l->pa = 0;
    }
    else if (key == K_W)
    {
        m->l->p_y += sin(m->l->pa) * 5;
        m->l->p_x += cos(m->l->pa) * 5;
    }
    else if (key == K_S)
    {
        m->l->p_y -= sin(m->l->pa) * 5;
        m->l->p_x -= cos(m->l->pa) * 5;
    }
    else if (key == ESC)
    {
        exit(EXIT_FAILURE);
    }
}

int ft_buttons(int key, t_map *m)
{
    int test_y;
    int test_x;
    float atan;

    atan = -1/tan(m->l->pa);
    ft_player_buttons(key, m);
    test_y = ((((int)m->l->p_y >> 5) << 5));
    test_x = (m->l->p_y - test_y) * atan + m->l->p_x;
    printf("key: %d\npx: %d\npy: %d\n K_A macro: %d\n Angle: %f\n next y position: %d\n next x position: %d\n", key, 
        m->l->p_x, m->l->p_y, K_A, m->l->pa, test_y, test_x);
    mlx_destroy_image(m->s_mlx->mlx, m->s_img->img);
    ft_set_image(m);
    create_map(m);
    ft_draw_player(m);
	plot_line(m, m->l->p_x + 5, m->l->p_y + 5, m->l->pa);
	mlx_put_image_to_window(m->s_mlx->mlx, m->s_mlx->win, m->s_img->img, 0, 0);
    mlx_do_sync(m->s_mlx->mlx);
    return (0);
}