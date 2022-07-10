/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchabli <nchabli@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 17:08:53 by nchabli           #+#    #+#             */
/*   Updated: 2022/07/08 17:13:08 by nchabli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../../includes/cub3d.h"

char	*get_file_str(char *file_entry)
{
	int		fd;
	int		r;
	char	buffer[2];
	char	*strmap;
	char	*tmp;

	strmap = NULL;
	if (open(file_entry, O_DIRECTORY) != -1)
		ft_error(PATH_IS_DIRECTORY);
	fd = open(file_entry, O_RDONLY);
	if (fd == -1)
		ft_error(NO_MAP_FILE);
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