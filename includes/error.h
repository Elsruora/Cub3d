/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchabli <nchabli@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 13:02:47 by nchabli           #+#    #+#             */
/*   Updated: 2022/07/08 17:14:05 by nchabli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Here are writen all error macros */

#define RED     "\x1b[31m"
#define GREEN   "\x1b[32m"
#define YELLOW  "\x1b[33m"
#define BLUE    "\x1b[34m"
#define MAGENTA "\x1b[35m"
#define CYAN    "\x1b[36m"
#define RESET   "\x1b[0m"

#define NO_MAP_FILE RED"Can't get map file,"GREEN" type : \"./cub3d map_path\" and make sure file is valid"RESET""
#define WRONG_EXT RED"Wrong argument extension,"GREEN" please put a .cub file\""RESET""
#define PARSING_ERROR RED"While parsing map,"GREEN" make sure file content is valid\""RESET""
#define TEXTURE_ERROR RED"While parsing map,"GREEN" make sure file content is valid\""RESET""
#define PATH_IS_DIRECTORY RED"Can't open a directory"GREEN" make sure entry is a file.\""RESET""
