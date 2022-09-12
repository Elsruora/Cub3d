/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fetch_texture_colors.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchabli <nchabli@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 09:38:53 by jvalenci          #+#    #+#             */
/*   Updated: 2022/09/12 14:47:44 by nchabli          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

/**
	@brief Feches all chars from the specified file passed as argument
	@param return a char array
*/
char	*get_rgbffile(char *file)
{
	char	*buffer;
	char	temp[1];
	int		count;
	int		fd;
	int		i;

	fd = open(file, O_RDONLY, 00700);
	count = 0;
	if (fd < 0)
		perror("Permission denied: %s\n");
	while (read(fd, temp, 1))
		count++;
	close(fd);
	fd = open(file, O_RDONLY, 00700);
	buffer = malloc(count + 1);
	if (!buffer)
		return (NULL);
	i = -1;
	while (++i < count)
		read(fd, &buffer[i], 1);
	close(fd);
	buffer[i] = 0;
	return (buffer);
}

/**
	@brief split file elements by ',' character
	and store each element in a int array
	@param return a int array
 */
int	*filter_rgb_file(char *file)
{
	char	*input;
	char	**output;
	int		*result;
	int		i;
	int		count;

	i = 0;
	count = 0;
	input = get_rgbffile(file);
	output = ft_split(input, ',');
	if (!input || !output)
		return (NULL);
	i = -1;
	while (output[++i])
		count++;
	result = malloc(count * sizeof(int));
	if (!result)
		return (NULL);
	i = -1;
	while (output[++i])
		result[i] = ft_atoi(output[i]);
	free(input);
	ft_free((void **)output);
	return (result);
}
