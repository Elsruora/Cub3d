/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_code_funcs.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchabli <nchabli@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 14:44:11 by nchabli           #+#    #+#             */
/*   Updated: 2022/09/12 14:44:42 by nchabli          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	get_color_code(char *rgb_code)
{
	t_counter	c;
	int			rgb[3];
	char		tmp[10];

	c.i = 0;
	c.k = 0;
	c.j = 0;
	while (rgb_code[c.i++])
	{
		while (ft_isdigit(rgb_code[c.i]))
			tmp[c.k++] = rgb_code[c.i++];
		tmp[c.k] = '\0';
		rgb[c.j] = atoi(tmp);
		if (rgb[c.j] < 0 || rgb[c.j] > 255)
			ft_error(BAD_RGB_VALUE, tmp);
		if (rgb_code[c.i] == ',')
		{
			c.j++;
			c.k = 0;
		}
	}
	return (rgb[0] << 16 | rgb[1] << 8 | rgb[2]);
}

int	is_color_code(char *code)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (code[i])
	{
		if (ft_isdigit(code[i]) || code[i] == ' ')
			i++;
		else if (code[i] == ',')
		{
			j++;
			i++;
		}
		else
			return (0);
	}
	if (j == 2)
		return (1);
	return (0);
}
