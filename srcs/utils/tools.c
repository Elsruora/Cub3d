/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvalenci <jvalenci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 17:50:31 by jvalenci          #+#    #+#             */
/*   Updated: 2022/09/16 09:28:16 by jvalenci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

/** 
  @brief find player inicial position
 */
void	ft_find_player(t_map *m)
{
	int	i;
	int	j;
	int	j_len;

	i = 0;
	j_len = 0;
	while (i < m->lines)
	{
		j = 0;
		j_len = strlen(m->map_desc[i]);
		while (j < j_len)
		{
			if (does_char_contain(m->map_desc[i][j], "SEWN"))
			{
				m->l->pa = player_direction(m->map_desc[i][j]);
				m->l->p_x = (j * 32) + 5;
				m->l->p_y = (i * 32) + 5;
				break ;
			}
			j++;
		}
		i++;
	}
}

int	choose_color(t_map *m, int color)
{
	if (m->ray->c_dir == 'h')
		return (color);
	else
		return (add_shadow(color, 0.5));
}

/** 
  @brief determines the max with and heigth of the map chart
 */
void	ft_map_size(t_map *m, int *cols, int *lines)
{
	int	i;
	int	temp;

	i = 0;
	temp = 0;
	*cols = 0;
	*lines = 0;
	while (m->map_desc[++i])
	{
		temp = ft_strlen(m->map_desc[i]);
		if (temp > *cols)
			*cols = temp;
	}
	*lines = i;
	m->height = *lines * 32;
	m->width = *cols * 32;
}

/* 
   @brief Costumized mlx_pixel_put function in order to write pixels faster
   see documentation to know more: 
https://harm-smits.github.io/42docs/libs/minilibx/getting_started.html
 */
void	my_mlx_pixel_put(t_img *stru, int x, int y, int color)
{
	char	*dst;

	dst = stru->addr + (y * stru->line_length + x * (stru->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

/** 
  @brief draw a square pipex by pixel, we need to provide x and y coordinates
  and color
 */
void	ft_draw_square(t_map *m, int x, int y, int color)
{
	int	i;
	int	j;

	i = 0;
	if (m->height <= 448 && m->width <= 1024)
	{
		while (i < m->pps_pix)
		{
			j = 0;
			while (j < m->pps_pix)
			{
				my_mlx_pixel_put(m->s_img[0], j + x, i + y, color);
				j++;
			}
			i++;
		}
	}
}
