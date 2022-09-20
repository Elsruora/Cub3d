/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_file_str2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchabli <nchabli@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 15:28:14 by nchabli           #+#    #+#             */
/*   Updated: 2022/09/20 15:35:56 by nchabli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	check_if_oppenable2(char *file_entry, int fd)
{
	if (open(file_entry, O_DIRECTORY) != -1)
		ft_error(PATH_IS_DIRECTORY, NULL);
	fd = open(file_entry, O_RDONLY);
	if (fd == -1)
		ft_error(BAD_TEXTURE_PATH, NULL);
	return (fd);
}

char	*get_file_str2(char *file_entry)
{
	int		fd;
	int		r;
	char	buffer[2];
	char	*strmap;
	char	*tmp;

	strmap = NULL;
	fd = 0;
	fd = check_if_oppenable2(file_entry, fd);
	r = read(fd, &buffer, 1);
	while (r)
	{
		buffer[r] = '\0';
		tmp = strmap;
		if (!strmap)
			strmap = ft_strdup(buffer);
		else
			strmap = ft_strjoin(strmap, buffer);
		free(tmp);
		r = read(fd, &buffer, 1);
	}
	return (strmap);
}
