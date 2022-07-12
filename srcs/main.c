/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvalenci <jvalenci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 04:35:19 by nchabli           #+#    #+#             */
/*   Updated: 2022/07/12 22:52:51 by jvalenci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	ft_set_window(t_map *m)
{
	int cols;
	int	lines;

	ft_map_size(m, &cols, &lines);
	m->mlx = mlx_init(); 
	m->win = mlx_new_window(m->mlx, cols * 64, lines * 64, "Cub3d");

}

int main(int ac, char **av)
{
	t_map m;
	int i = -1; 


 	control_arg(ac, av);
	m.map = ft_split(get_file_str(av[1]), '\n');
	control_map(m.map);
	ft_set_window(&m);
	while (m.map[++i])
		printf("%s\n", m.map[i]);
	return (0);
}
