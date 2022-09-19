/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchabli <nchabli@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 17:08:53 by nchabli           #+#    #+#             */
/*   Updated: 2022/09/19 13:42:11 by nchabli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../../includes/cub3d.h"

void	control_nl_map2(char *strmap, int l)
{
	while (strmap[l])
	{
		if (strmap[l] == '\n')
		{
			while (strmap[l] && strmap[l] == '\n')
				l++;
			if (does_char_contain(strmap[l], "01 ")
				&& strmap[l - 2] == '\n')
				ft_error(TO_MUCH_NL, NULL);
		}
		l++;
	}
}

void	control_nl_map(char *strmap)
{
	size_t	l;
	size_t	i;

	l = 0;
	i = 0;
	while (strmap[l])
	{
		if (strmap[l] == '\n')
		{
			while (strmap[l] && strmap[l] == '\n')
				l++;
			if (does_char_contain(strmap[l], "NSEWCF "))
				l++;
			if (does_char_contain(strmap[l], "01"))
				control_nl_map2(strmap, l);
			i++;
		}
		l++;
	}
}

int	check_if_oppenable(char *file_entry, int fd)
{
	if (open(file_entry, O_DIRECTORY) != -1)
		ft_error(PATH_IS_DIRECTORY, NULL);
	fd = open(file_entry, O_RDONLY);
	if (fd == -1)
		ft_error(NO_MAP_FILE, NULL);
	return (fd);
}

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
	fd = 0;
	fd = check_if_oppenable(file_entry, fd);
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
	control_nl_map(strmap);
	return (strmap);
}
