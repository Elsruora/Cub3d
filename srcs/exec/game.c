/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvalenci <jvalenci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 14:30:03 by jvalenci          #+#    #+#             */
/*   Updated: 2022/07/26 15:27:09 by jvalenci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void    ft_player_buttons(int key, t_map *m)
{
    int next_case_y = 0;
    int next_case_x = 0;
    printf("next_y : %d\n next_x :%d\n actual y : %d\n actual x : %d\n", next_case_y, next_case_x, (int)m->l->p_y/32, (int)m->l->p_x/32);
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
        next_case_y = (m->l->p_y + sin(m->l->pa) * 5) / 32;
        next_case_x = (m->l->p_x + cos(m->l->pa) * 5) / 32;
        if (does_char_contain(m->map_desc[next_case_y][next_case_x], "0NSWE"))
        {
            m->l->p_y += sin(m->l->pa) * 5;
            m->l->p_x += cos(m->l->pa) * 5;
        }
        else if (m->map_desc[next_case_y][(int)(m->l->p_x/32)] == '1' && m->map_desc[(int)(m->l->p_y/32)][next_case_x] != '1')
            m->l->p_x += cos(m->l->pa) * 5;
        else if (m->map_desc[(int)(m->l->p_y/32)][next_case_x] == '1' && m->map_desc[next_case_y][(int)(m->l->p_x/32)] != '1')
            m->l->p_y += sin(m->l->pa) * 5;
    }
    else if (key == K_S)
    {
        next_case_y = (m->l->p_y - sin(m->l->pa) * 5) / 32;
        next_case_x = (m->l->p_x - cos(m->l->pa) * 5) / 32;
        if (does_char_contain(m->map_desc[next_case_y][next_case_x], "0NSWE"))
        {
            m->l->p_y -= sin(m->l->pa) * 5;
            m->l->p_x -= cos(m->l->pa) * 5;
        }
        else if (m->map_desc[next_case_y][(int)(m->l->p_x/32)] == '1' && m->map_desc[(int)(m->l->p_y/32)][next_case_x] != '1')
            m->l->p_x -= cos(m->l->pa) * 5;
        else if (m->map_desc[(int)(m->l->p_y/32)][next_case_x] == '1' && m->map_desc[next_case_y][(int)(m->l->p_x/32)] != '1')
            m->l->p_y -= sin(m->l->pa) * 5;
    }
    else if (key == K_ESC)
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