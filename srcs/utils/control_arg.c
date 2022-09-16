/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control_arg.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvalenci <jvalenci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 09:46:25 by nchabli           #+#    #+#             */
/*   Updated: 2022/09/16 09:28:03 by jvalenci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

/* check extention .cub */
int	control_arg(int ac, char **av)
{
	int		i;
	int		j;
	char	extension[5];

	i = 4;
	j = 0;
	if (ac == 2)
	{
		if (av[1][4])
		{
			while (av[1][ft_strlen(av[1]) - i])
			{
				extension[j++] = av[1][ft_strlen(av[1]) - i];
				i--;
			}
			extension[4] = '\0';
			if (ft_strcmp(extension, ".cub"))
				ft_error(WRONG_EXT, NULL);
		}
		return (0);
	}
	ft_error(WRONG_ARG_NB, NULL);
	return (1);
}
