# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hrothery <hrothery@student.42wolfsburg.de> +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/09 09:41:29 by bvarlamo          #+#    #+#              #
#    Updated: 2022/09/28 09:44:25 by hrothery         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

ifeq ($(shell uname), Darwin)

cub3D=	src/main.c src/keys.c src/raycastinghelpers.c src/helpers.c src/init_pos.c src/parser_utils0.c \
		src/parser_utils1.c src/parser_utils2.c src/parser.c src/space_check.c src/wall_check.c \
		src/stepforward.c src/free.c src/color_utils.c src/main_helpers.c \

endif

ifeq ($(shell uname), Linux)

cub3D=	src/main_linux.c src/keys.c src/raycastinghelpers.c src/helpers.c src/init_pos.c src/parser_utils0.c \
		src/parser_utils1.c src/parser_utils2.c src/parser.c src/space_check.c src/wall_check.c \
		src/stepforward.c src/free.c src/color_utils.c src/main_helpers.c \

endif

NAME	=	cub3D

CC	=	gcc

RM	=	rm -f

CFLAGS	=	-Wall -Wextra -Werror

cub3DO=	$(cub3D:.c=.o)

lib	=./Libft

all :		$(NAME)

ifeq ($(shell uname), Darwin)

minilbx=./minilibx_opengl

FRAMEWORKS	=		-lmlx -framework OpenGL -framework AppKit -lz -L minilibx_opengl

INCLUDES	=		libft/libft.a minilibx_opengl/libmlx.a

${NAME}:	${cub3DO}
		make -C ${lib}
		make -C ${minilbx}
		${CC} ${CFLAGS} ${cub3DO} $(INCLUDES) $(FRAMEWORKS) -o ${NAME}

clean :
	make clean -C ${lib}
	$(RM) ${cub3DO}

fclean :	clean
	$(RM) $(NAME)
	$(RM) Libft/libft.a
	make clean -C ${minilbx}

endif

ifeq ($(shell uname), Linux)

mlx = ./mlx

$(NAME):	${cub3DO}
	make -C ${lib}
	make -C ${mlx}
	$(CC) $(cub3DO) -Lmlx -lmlx -L/usr/lib -Imlx -lXext -lX11 -lm -lz $(CFLAGS) Libft/libft.a -o $(NAME)

%o: %c 
	$(CC) $(CFLAGS) -I/usr/include -Imlx -03 -c $< -o $@

clean :
	make clean -C ${lib}
	$(RM) ${cub3DO}

fclean :	clean
	$(RM) $(NAME)
	make clean -C ${mlx}
	make fclean -C ${lib}

endif

re :		fclean all