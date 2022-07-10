/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control_arg.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchabli <nchabli@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 09:46:25 by nchabli           #+#    #+#             */
/*   Updated: 2022/07/08 11:47:44 by nchabli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../../includes/cub3d.h"

int control_arg(int ac, char **av)
{
    int     i;
    int     j;
    char    extension[5];
    
    i = 4;
    j = 0;
    if (ac == 2)
    {
        if(av[1][5])
        {
            while(av[1][ft_strlen(av[1]) - i])
            {
                extension[j++] = av[1][ft_strlen(av[1]) - i];
                i--;
            }
            extension[4] = '\0';
            if (ft_strcmp(extension, ".cub"))
                ft_error(WRONG_EXT);
        }
    }
    return (1);
}