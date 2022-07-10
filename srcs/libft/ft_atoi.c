/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchabli <nchabli@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 10:37:51 by nchabli           #+#    #+#             */
/*   Updated: 2022/07/08 10:05:33 by nchabli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static int	ft_atoi2(unsigned int res, int sign)
{
	if (res > 2147483648 && sign == -1)
		return (0);
	if (res > 2147483648 && sign == 1)
		return (-1);
	return (res * sign);
}

int	ft_atoi(const char *str)
{
	unsigned int	result;
	int				sign;

	while (*str == '\t' || *str == '\n' || *str == '\v'
		|| *str == '\f' || *str == '\r' || *str == ' ')
		str++;
	sign = 1;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}	
	result = 0;
	while (ft_isdigit(*str))
	{
		result = (int)(*str - '0') + result * 10;
		str++;
	}
	return (ft_atoi2(result, sign));
}
