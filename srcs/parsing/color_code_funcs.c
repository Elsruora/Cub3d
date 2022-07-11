
#include "../../includes/cub3d.h"

int get_color_code(char *rgb_code)
{
    int     i;
    int     j;
    int     k;
    int     rgb[3];
    char    *tmp;

    i = 0;
    k = 0;
    j = 0;
    tmp = NULL;
    while (rgb_code[i])
    {

        while(ft_isdigit(rgb_code[i]))
            tmp[k] = rgb_code[i++];
        rgb[j] = atoi(tmp);
        if (rgb_code[i] == ',')
            j++;
    }
    return (rgb[0] << 16 | rgb[1] << 8 | rgb[2]);
}

int is_color_code (char *code)
{
    int i;
    int j;
    
    i = 0;
    j = 0;
    while (code[i])
    {
        if(ft_isdigit(code[i]))
            i++;
        else if (code[i] == ',')
        {
            j++;
            i++;
        }
        else
            return (0);
    }
    if (j == 2)
        return (1);
    return (0);
}
