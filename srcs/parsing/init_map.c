/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchabli <nchabli@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 17:08:53 by nchabli           #+#    #+#             */
/*   Updated: 2022/07/20 15:11:29 by nchabli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../../includes/cub3d.h"

/* 
Read from file passed as argument character by character, then return string
*/
char	*get_file_str(char *file_entry)
{
	int		fd;
	int		r;
	char	buffer[2];
	char	*strmap;
	char	*tmp;

	strmap = NULL;
	if (open(file_entry, O_DIRECTORY) != -1)
		ft_error(PATH_IS_DIRECTORY, NULL);
	fd = open(file_entry, O_RDONLY);
	if (fd == -1)
		ft_error(NO_MAP_FILE, NULL);
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
	r = 0;
/* 	while (strmap[r])
	{
		if (strmap[r])
		{
			
		}
		
	} */
	
	return (strmap);
}