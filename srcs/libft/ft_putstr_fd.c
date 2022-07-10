/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchabli <nchabli@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 02:06:03 by hjordan           #+#    #+#             */
/*   Updated: 2022/07/08 10:05:13 by nchabli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	ft_putstr_fd(char *s, int fd)
{
	if (s == NULL || !fd)
		return ;
	write(fd, s, ft_strlen(s));
	write(fd, "\n", 1);
}
