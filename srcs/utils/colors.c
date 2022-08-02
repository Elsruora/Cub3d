/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvalenci <jvalenci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 09:45:11 by jvalenci          #+#    #+#             */
/*   Updated: 2022/08/02 09:51:06 by jvalenci         ###   ########.fr       */
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

int rgb_to_int(int r, int g, int b)
{
	return ((r<<16) + (g<<8) + b);
}

int	add_shadow(int rgb)
{
    int r;
    int g;
    int b;

    r = get_r(rgb);
    b = get_g(rgb);
    g = get_b(rgb);
    return (rgb_to_int(r * 0.5, g * 0.5 , b * 0.5));
}
