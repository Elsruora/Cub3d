/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchabli <nchabli@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 12:42:18 by nchabli           #+#    #+#             */
/*   Updated: 2022/07/20 11:46:38 by nchabli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

/**
    @brief Print error message on terminal then exit program.
    
    @param error string with error value
*/
void ft_error(char *error, char *where)
{
    if (where)
        printf("Error\n on \"%s\" : %s", where, error);
    else
        printf("Error\n %s", error);
    exit(EXIT_FAILURE);
}
