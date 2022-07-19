/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvalenci <jvalenci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 14:30:03 by jvalenci          #+#    #+#             */
/*   Updated: 2022/07/18 17:50:17 by jvalenci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int ft_buttons(int key, t_map *m)
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
    printf("key: %d\npx: %d\npy: %d\n K_A macro: %d\n Angle: %f\n", key, m->l->p_x, m->l->p_y, K_A, m->l->pa);
    mlx_destroy_image(m->s_mlx->mlx, m->s_img->img);
    ft_set_image(m);
    create_map(m);
    ft_draw_player(m);
	plot_line(m, m->l->p_x + 10, m->l->p_y + 10, m->l->pa);
	mlx_put_image_to_window(m->s_mlx->mlx, m->s_mlx->win, m->s_img->img, 0, 0);
    mlx_do_sync(m->s_mlx->mlx);
    return (0);
}