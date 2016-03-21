# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mdos-san <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/01/06 17:24:47 by mdos-san          #+#    #+#              #
#    Updated: 2016/03/21 16:33:33 by mdos-san         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= rtv1

COMPILER	= gcc
FLAGS		= -Wall -Werror -Wextra -I./includes
DEBUG		= -g3 -fsanitize=address
LIBS		= -L./libs -lft -lmlx -lcolor -lm

OS			= $(shell uname)

MLX_DIR		= minilibx_macos

ifeq ($(OS), Linux)
MLX_DIR		= minilibx_linux
endif

TMP_C		=\
			 rt_v1_init.c\
			 rt_v1_exit.c\
			 rt_v1_get_info.c\
			 parse.c\
			 obj_add.c\
			 obj_destroy.c\
			 rt_mlx_init.c\
			 pnt_translate.c\
			 render_loop.c\
			 img_pixel_put.c\
			 check_colision.c\
			 init_sph.c\
			 init_pla.c\
			 init_lum.c\
			 main.c
SRC_C		= $(TMP_C:%=src/%)

TMP_O		= $(TMP_C:.c=.o)
SRC_O		= $(TMP_O:%=objects/%)

all			: $(NAME)

$(NAME)		: libs/libcolor.a libs/libft.a libs/libmlx.a objects $(SRC_O)
ifeq ($(OS), Linux)
	@$(COMPILER) $(SRC_O) $(FLAGS) $(LIBS) -lX11 -lXext -o $(NAME)
else
	@$(COMPILER) $(SRC_O) $(FLAGS) $(LIBS) -framework OpenGL -framework AppKit -o $(NAME)
endif

libs/libft.a	:
	@echo "Making libft: \t\t"
	@make -C libs/libft
	@mv libs/libft/libft.a libs
	@make -C libs/libft/ fclean
	@echo "[LIBFT]: \t\t\t[OK]"

libs/libmlx.a	:
	@echo "Making libmlx: \t\t"
	@make -C libs/$(MLX_DIR)
	@mv libs/$(MLX_DIR)/libmlx.a libs
	@make -C libs/$(MLX_DIR) clean
	@echo "[LIBMLX]: \t\t\t[OK]"

libs/libcolor.a	:
	@echo "Making libcolor: \t\t"
	@make -C libs/libcolor
	@cp libs/libcolor/libcolor.a libs
	@make -C libs/libcolor fclean
	@echo "[LIBCOLOR]: \t\t\t[OK]"

objects		:
	@mkdir objects

objects/%.o	: srcs/%.c
	@echo "Compiling $<: \t\t\c"
	@$(COMPILER) $(FLAGS) -c $<
	@mv $(notdir $@) objects
	@echo "[OK]"

clean		:
	@echo "Removing objects: \t\t\c"
	@rm -rf objects
	@echo "[OK]"

fclean		: clean
	@echo "Removing binaries: \t\t\c"
	@rm -rf $(NAME)
	@rm -rf libs/libft.a
	@rm -rf libs/libmlx.a
	@rm -rf libs/libcolor.a
	@rm -rf libs/minilibx_linux/libmlx_Linux.a
	@echo "[OK]"

re			: fclean all

norm		:
	@norminette srcs includes

full_norm	: norm
	@make norm -C libs/libft
	@make norm -C libs/libcolor

.PHONY: all clean fclean re norm full_norm
