/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchabli <nchabli@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 13:02:47 by nchabli           #+#    #+#             */
/*   Updated: 2022/09/08 17:04:47 by nchabli          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef __ERROR_H
# define __ERROR_H

/* Here are writen all error macros */

#define RED     "\x1b[31m"
#define GREEN   "\x1b[32m"
#define YELLOW  "\x1b[33m"
#define BLUE    "\x1b[34m"
#define MAGENTA "\x1b[35m"
#define CYAN    "\x1b[36m"
#define RESET   "\x1b[0m"

#define NO_MAP_FILE         RED"Can't get map file,"GREEN" type : \"./cub3d map_path\" and make sure file is valid"RESET""
#define WRONG_EXT           RED"Wrong argument extension,"GREEN" please put a .cub file\""RESET""
#define PARSING_ERROR       RED"While parsing map,"GREEN" make sure file content is valid\""RESET""
#define TEXTURE_ERROR       RED"While parsing map,"GREEN" make sure file content is valid\""RESET""
#define PATH_IS_DIRECTORY   RED"Can't open a directory"GREEN" make sure entry is a file.\""RESET""
#define TEXTURE_NAME_ERROR  RED"Texture name error"GREEN" check your map file.\""RESET""
#define BAD_TEXTURE_PATH    RED"Unable to find file at path"GREEN" check your map file.\""RESET""
#define BAD_COLOR_CODE      RED"Bad color code format"GREEN" check your map file.\""RESET""
#define WRONG_ARG_NB        RED"Wrong arguments number"GREEN" please type just one\""RESET""
#define BAD_RGB_VALUE       RED"Bad RGB value"GREEN" please type a number between 0 and 255 inclued\""RESET""
#define BAD_CHAR_ON_MAP     RED"Bad char on map"GREEN" please check map file and changes wrongs chars\""RESET""
#define BAD_PLAYER_NB       RED"Bad players numbers"GREEN" please put only one player on map\""RESET""
#define TO_MUCH_NL          RED"Detected new line on map file"GREEN" please fix this problem\""RESET""
#define DOUBL_ON_TEXTURES   RED"Doublons on textures"GREEN" please fix this problem\""RESET""
#define BAD_WALL            RED"Walls don't close map"GREEN" please fix this problem\""RESET""
#define WRONG_TEXTURE_EXT   RED"Wrong texture extention"GREEN" please put .xpm files\""RESET""

#endif