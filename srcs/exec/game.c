/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvalenci <jvalenci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 14:30:03 by jvalenci          #+#    #+#             */
/*   Updated: 2022/07/21 15:05:47 by jvalenci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void    ft_player_buttons(int key, t_map *m)
{
    if (key == K_A)
    {
        m->l->pa -= 0.1;
        if (m->l->pa < 0)
            m->l->pa = (2 * PI);
    }
    else if (key == K_D)
    {
        m->l->pa += 0.1;
        if (m->l->pa > (2 * PI))
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
}

int ft_buttons(int key, t_map *m)
{
    ft_player_buttons(key, m);
    check_h_line(m);
    printf("key: %d\npx: %d\npy: %d\n K_A macro: %d\n Angle: %f\n next y position: %d\n next x position: %d\n\
y divided by 32: %d\n, x divided by 32: %d\n", key, m->l->p_x, m->l->p_y, K_A, m->l->pa, m->ray->ry,
m->ray->rx, (int)m->ray->ry >> 5, (int)m->ray->rx >> 5);
    mlx_destroy_image(m->s_mlx->mlx, m->s_img->img);
    ft_set_image(m);
    create_map(m);
    ft_draw_player(m);
	mlx_put_image_to_window(m->s_mlx->mlx, m->s_mlx->win, m->s_img->img, 0, 0);
    mlx_do_sync(m->s_mlx->mlx);
    return (0);
}