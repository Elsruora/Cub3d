/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control_textures.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchabli <nchabli@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 16:05:16 by nchabli           #+#    #+#             */
/*   Updated: 2022/09/20 17:57:29 by jvalenci         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

char	*find_scnd_word(char *line)
{
	int	i;

	i = 0;
	while (line[i] && line[i] == ' ')
		i++;
	while (ft_isprint(line[i]))
		i++;
	while (line[i] == ' ')
		i++;
	return (line + i);
}

void	check_texture_ext(char *path)
{
	char	extension[5];
	int		i;
	int		j;

	j = 0;
	i = 4;
	if (path[4])
	{
		while (i)
			extension[j++] = path[ft_strlen(path) - i--];
		extension[4] = '\0';
		if (ft_strcmp(extension, ".ppm"))
			ft_error(WRONG_TEXTURE_EXT, path);
	}
}

char	*open_one_texture(char *path)
{
	int	fd;

	check_texture_ext(path);
	if (open(path, O_DIRECTORY) != -1)
		ft_error(PATH_IS_DIRECTORY, path);
	fd = open(path, O_RDONLY);
	if (fd == -1)
		ft_error(BAD_TEXTURE_PATH, path);
	close(fd);
	return (path);
}

void	open_each_texture(t_map *m, char *path, int i)
{
	if (!ft_strncmp(m->map[i], "NO ", 3))
		m->t->no = open_one_texture(path);
	else if (!ft_strncmp(m->map[i], "SO ", 3))
		m->t->so = open_one_texture(path);
	else if (!ft_strncmp(m->map[i], "WE ", 3))
		m->t->we = open_one_texture(path);
	else if (!ft_strncmp(m->map[i], "EA ", 3))
		m->t->ea = open_one_texture(path);
}

void	check_textures_doublons(char **map)
{
	int	i;
	int	comb;

	i = 0;
	comb = 0;
	while (i < 6)
	{
		if (!ft_strncmp(map[i], "NO ", 3))
			comb += 3;
		else if (!ft_strncmp(map[i], "SO ", 3))
			comb += 5;
		else if (!ft_strncmp(map[i], "WE ", 3))
			comb += 7;
		else if (!ft_strncmp(map[i], "EA ", 3))
			comb += 11;
		else if (!ft_strncmp(map[i], "F ", 2))
			comb += 13;
		else if (!ft_strncmp(map[i], "C ", 2))
			comb += 17;
		i++;
	}
	if (comb != 56)
		ft_error(DOUBL_ON_TEXTURES, NULL);
}
