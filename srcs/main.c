/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchabli <nchabli@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 04:35:19 by nchabli           #+#    #+#             */
/*   Updated: 2022/07/18 12:08:56 by nchabli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int main(int ac, char **av)
{
	t_map m;

 	control_arg(ac, av);
	m.map = ft_split(get_file_str(av[1]), '\n');
	check_all_map_file(m);
	return (0);
}
