/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchabli <nchabli@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 14:30:03 by jvalenci          #+#    #+#             */
/*   Updated: 2022/07/26 11:29:56 by nchabli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void    ft_player_buttons(int key, t_map *m)
{
    if (key == K_A)
    {
        m->l->pa -= (float)0.1;
        if (m->l->pa < 0)
            m->l->pa = (float)(2 * M_PI);
    }
    else if (key == K_D)
    {
        m->l->pa += (float)0.1;
        if (m->l->pa > (float)(2 * M_PI))
            m->l->pa = (float)0;
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
    ft_player_buttons(key, m);
    mlx_destroy_image(m->s_mlx->mlx, m->s_img->img);
    ft_set_image(m);
    create_map(m);
    ft_draw_player(m);
	mlx_put_image_to_window(m->s_mlx->mlx, m->s_mlx->win, m->s_img->img, 0, 0);
    mlx_do_sync(m->s_mlx->mlx);
    return (0);
}