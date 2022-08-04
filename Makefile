# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nchabli <nchabli@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/23 00:32:08 by nchabli           #+#    #+#              #
#    Updated: 2022/08/04 10:21:07 by nchabli          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

-include ./Config/Sources.mk
-include ./Config/Header.mk
#################################################################################
#                                   Colors                                      #
#################################################################################
GREY        = \033[4;34m
RED         = \033[1;31m
GREEN       = \033[3;32m
YELLOW      = \033[2;49;33m
BLUE        = \033[4;34m
BLUEE       = \033[3;34m
PURPLE      = \033[3;35m
CYAN        = \033[3;36m
RESET       = \033[0m
ICONOK      = \033[1;32m
ICONKO      = \033[1;31m
CO_DELET    = \033[4;31m
CO_A_OUT    = \033[96m
WHITE       = \033[1;49;97m
#################################################################################
#                                   Variables                                   #
#################################################################################

NAME        = Cub3d
MK_DIR      = Config
OBJS        = $(SRCS:%.c=%.o)
EXEC_FLAGS_MAC = -Lmlx -lmlx -framework OpenGL -framework AppKit 
OBJS_FLAGS_MAC = -Imlx 
EXEC_FLAGS_LINUX := linux_mlx/libmlx.a -L/usr/include/ -L/usr/lib  -lXext -lX11 -lm -lbsd
OBJS_FLAGS_LINUX := -I/usr/include -lmlx -Ilinux_mlx -Llinux_mlx
LINUX = 
OBJ_DIR     = Objects
OBJ_PATH    = $(addprefix $(OBJ_DIR)/, $(OBJS))
DEPENDES    = $(OBJ_PATH:%.o=%.d)
CFLAGS      = -g -Wall -Werror -Wextra
TRACKER     = srcs/utils/tracker/libtracker.a
DIR_TRACK   = srcs/utils/tracker
CONFIG      = $(shell find [0-9a-zA-Z]* -type d -name "Config")
CNAME := $(shell uname -s)
ifeq ($(CNAME), Linux)
	EXEC_FLAGS_MAC = $(EXEC_FLAGS_LINUX)
	OBJS_FLAGS_MAC = $(OBJS_FLAGS_LINUX)
	LINUX = -D __LINUX__=1
endif

#################################################################################
#                                   Compilation C                               #
#################################################################################
$(NAME): mlx $(OBJ_PATH) 
	@gcc $(LINUX) $(CFLAGS)  $(OBJ_PATH) -o $(NAME) $(EXEC_FLAGS_MAC)
	@printf "\033[2K\r$(BLUE)$(NAME)$(RESET)$(BLUEE): $(ICONOK)Compiled [√]$(RESET)\n"
	
all: gmk $(NAME) $(HEADER)

#################################################################################
#                                   Compilation Objects                         #
#################################################################################
$(OBJ_DIR)/%.o: %.c | $(OBJ_DIR)
	@mkdir -p $(@D)
	@gcc $(LINUX) $(CFLAGS) $(INC_INC) \
	-c $< -o $@
	@printf "\033[2K\r$(PURPLE)$<: $(CYAN)loading..$(RESET)"

$(OBJ_DIR):
	@printf "\033[1;32mCreate OBJS_DIR $(CO_DELET)\033[3;32m [√]\033[0m\n"
	
mlx:
	$(MAKE) -C ./mlx

ifeq ($(CNAME), Linux)
mlx:
	$(MAKE) -C ./linux_mlx
	
endif

#################################################################################
#                                   Clean                                       #
#################################################################################
clean:
	@$(RM) $(OBJ_PATH)
	@printf "\033[1;31mDelete OBJS $(CO_DELET)$(NAME)\033[3;32m [√]\033[0m\n"

fclean:
	@$(RM) $(OBJ_PATH)
	@$(RM) $(NAME)
	@$(RM) -rf $(NAME).dSYM a.out Objects
	@printf "\033[1;31mDelete $(CO_DELET)$(NAME)\033[3;32m [√]\033[0m\n"
#################################################################################
#                                   Gen MK                                      #
#################################################################################
$(MK_DIR):
ifneq ($(CONFIG), Config)
	@mkdir Config
endif

gmk: $(MK_DIR)
	@echo "SRCS += " > ./Config/Sources.mk
	@find srcs -name '*.c' | sed 's/^/SRCS += /' >> ./Config/Sources.mk
	@echo "HEADER += " > ./Config/Header.mk
	@find ./includes -name '*.h' | sed 's/^/HEADER += /' >> ./Config/Header.mk
	@echo "`sed '/tracker/d' ./Config/Sources.mk`" > ./Config/Sources.mk

#################################################################################
#                                   Norminette                                  #
#################################################################################
norme:
	@printf "\033[1;36m"
	norminette -R CheckDefine ./includes/
	@printf "\n\033[1;32m"
	norminette -R CheckForbiddenSourceHeader ./srcs/

#################################################################################
#                                   Clena & Compilation                         #
#################################################################################

re: fclean all

.PHONY: re fclean clean all gmk norme

-include $(DEPENDES)