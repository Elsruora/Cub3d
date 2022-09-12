/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchabli <nchabli@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 09:45:11 by jvalenci          #+#    #+#             */
/*   Updated: 2022/09/12 15:01:07 by nchabli          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	get_r(int trgb)
{
	return ((trgb >> 16) & 0xFF);
}

int	get_g(int trgb)
{
	return ((trgb >> 8) & 0xFF);
}

int	get_b(int trgb)
{
	return (trgb & 0xFF);
}

int	rgb_to_int(int r, int g, int b)
{
	return ((r << 16) + (g << 8) + b);
}

int	add_shadow(int rgb, float intensity)
{
	int	r;
	int	g;
	int	b;
	int	temp;

	r = get_r(rgb);
	g = get_b(rgb);
	b = get_g(rgb);
	temp = rgb_to_int(r, g, b);
	r = get_r(temp);
	g = get_b(temp);
	b = get_g(temp);
	return (rgb_to_int(r * intensity, g * intensity, b * intensity));
}
