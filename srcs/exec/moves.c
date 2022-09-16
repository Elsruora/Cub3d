/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchabli <nchabli@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 16:03:51 by nchabli           #+#    #+#             */
/*   Updated: 2022/09/16 08:43:58 by nchabli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	go_lr(int key, t_map *m)
{
	if (key == K_A || key == K_LEFT)
	{
		m->l->pa -= 0.08;
		if (m->l->pa < 0)
			m->l->pa = (float)(2 * M_PI);
	}
	else if (key == K_D || key == K_RIGHT)
	{
		m->l->pa += 0.08;
		if (m->l->pa > (float)(2 * M_PI))
			m->l->pa = (float)0;
	}
}

void	go_down(t_map *m)
{
	int	next_case_y;
	int	next_case_x;

	next_case_y = (m->l->p_y - sin(m->l->pa) * 5) / m->pps_pix;
	next_case_x = (m->l->p_x - cos(m->l->pa) * 5) / m->pps_pix;
	if (does_char_contain(m->map_desc[next_case_y][next_case_x], "0NSWE"))
	{
		m->l->p_y -= sin(m->l->pa) * 5;
		m->l->p_x -= cos(m->l->pa) * 5;
	}
	else if (m->map_desc[next_case_y][(int)(m->l->p_x / m->pps_pix)] == '1'
			&& m->map_desc[(int)(m->l->p_y / m->pps_pix)][next_case_x] != '1')
		m->l->p_x -= cos(m->l->pa) * 5;
	else if (m->map_desc[(int)(m->l->p_y / m->pps_pix)][next_case_x] == '1'
			&& m->map_desc[next_case_y][(int)(m->l->p_x / m->pps_pix)] != '1')
		m->l->p_y -= sin(m->l->pa) * 5;
}

void	go_up(t_map *m)
{
	int	i;

	i = 5;
	if (!is_there_wall(m, 10))
	{
		while (i != 0 && !is_there_wall(m, 10))
		{
			m->l->p_y += sin(m->l->pa) * 1;
			m->l->p_x += cos(m->l->pa) * 1;
			i--;
		}
	}
}
