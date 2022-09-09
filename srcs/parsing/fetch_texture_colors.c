/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fetch_texture_colors.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvalenci <jvalenci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 09:38:53 by jvalenci          #+#    #+#             */
/*   Updated: 2022/09/09 15:23:21 by jvalenci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

/** 
    @param replases the character c passed as argument in the string buffer 
    by 0
 */
void    erase_char(char **buffer, char c)
{
    int i;

    i = 0;
    while (buffer[0][i])
    {
        if (buffer[0][i] == c)
            buffer[0][i] = 0;
        i++;
    }
}

/** 
    @param Feches all chars from the specified file passed as argument 
    @param return a char array
*/
char *get_rgbffile(char *file)
{
    char *buffer;
    char temp[1];
    int count;
    int fd;
    int i;

    fd = open(file, O_RDONLY, 00700);
    if (fd < 0)
    {
        printf("Permission denied: %s\n", file);
        return NULL;
    }
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
    @param split file elements by '\n', then get rid of ',' character 
    and store each element in a int array
    @param return a int array
 */
int *filter_rgb_file(char *file)
{
    char    *input;
    char    **output;
    int     *result;
    int     i;
    int     count;

    i = 0;
    count = 0;
    input = get_rgbffile(file);
    output = ft_split(input, '\n');
    if (!input || !output)
        return (NULL);
    i = -1;
    while (output[++i])
    {
        erase_char(&output[i], ',');
        count++;
    }
    result = malloc(count * sizeof(int));
    if (!result)
        return (NULL);
    i = -1;
    while (output[++i])
        result[i] = ft_atoi(output[i]);
    return (result);
}