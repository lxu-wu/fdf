NAME = fdf

SRCS = 			src/draw/draw.c\
				src/draw/draw_bg.c\
				src/draw/draw_line.c\
				src/draw/project.c\
				src/draw/project_info.c\
				src/ft_error.c\
				src/lst/coor.c\
				src/lst/coor2.c\
				src/main.c\
				src/parsing/ft_saved.c\
				src/parsing/parsing.c\
				src/parsing/parsing2.c\
				src/parsing/parsing3.c\
				src/utils/hook.c\
				src/utils/hook2.c\
				src/utils/hook_utils.c\
				src/utils/utils.c

SRCS_BONUS =	src/draw/draw.c\
				src/draw/draw_bg.c\
				src/draw/draw_line.c\
				src/draw/project.c\
				src/draw/project_info.c\
				src/ft_error.c\
				src/lst/coor.c\
				src/lst/coor2.c\
				src/main_bonus.c\
				src/parsing/ft_saved.c\
				src/parsing/parsing.c\
				src/parsing/parsing2.c\
				src/parsing/parsing3.c\
				src/utils/hook.c\
				src/utils/hook2.c\
				src/utils/hook_utils.c\
				src/utils/utils.c

RM =	rm -f

CC = gcc

FLAGS = -Wall -Werror -Wextra -I /usr/local/include -L /usr/local/lib/ -lmlx -framework OpenGL -framework AppKit

OBJS =	${SRCS:.c=.o}

OBJS_BONUS =	${SRCS_BONUS:.c=.o}

all:		${OBJS}

$(NAME):	${OBJS}
			@make bonus libft.a -C ./libft
			@cp ./libft/libft.a libft.a
			gcc ${FLAGS} -o ${NAME} ${OBJS} libft.a

bonus:		${OBJS_BONUS}
			@make bonus libft.a -C ./libft
			@cp ./libft/libft.a libft.a
			gcc ${FLAGS} -o ${NAME} ${OBJS_BONUS} libft.a

clean:
			@make clean -C ./libft
			${RM} ${OBJS} ${OBJS_BONUS} libft.a

fclean:		clean
			@make fclean -C ./libft
			${RM} ${NAME}

re:			fclean all

.PHONY:		all clean fclean re bonus
