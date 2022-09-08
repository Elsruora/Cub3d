#
#
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
NOM=libmlx.a
SRC= mlx_shaders.c mlx_new_window.m mlx_init_loop.m mlx_new_image.m mlx_xpm.c mlx_int_str_to_wordtab.c
SRC+= mlx_png.c mlx_mouse.m
OBJ1=$(SRC:.c=.o)
OBJ=$(OBJ1:.m=.o)
CFLAGS+=-O2

# add to match string put with X11 in size and position
CFLAGS+= -DSTRINGPUTX11

all: $(NOM)

$(NOM):	$(OBJ)
	ar -r $(NOM) $(OBJ)
	ranlib $(NOM)
	@clear
	@printf "\033[2K\r$(BLUE)$(NOM)$(RESET)$(BLUEE): $(ICONOK)Compiled [√]$(RESET)\n"

clean:
	rm -f $(NOM) $(OBJ) *~
	rm -f mlx_app
	@clear
	@printf "\033[1;31mDelete $(CO_DELET)$(NOM)\033[3;32m [√]\033[0m\n"

re: clean all
