/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchabli <nchabli@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 12:42:18 by nchabli           #+#    #+#             */
/*   Updated: 2022/07/08 16:02:42 by nchabli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

/**
    @brief Print error message on terminal then exit program.
    
    @param error string with error value
*/
void ft_error(char *error)
{
    printf("Error : %s", error);
    exit(EXIT_FAILURE);
}
