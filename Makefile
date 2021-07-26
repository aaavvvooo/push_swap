NAME = push_swap

SRCS = push_swap.c utils.c parser.c operations.c index.c markup.c algorithm.c
OBJS = ${SRCS:.c=.o}
CC = gcc
RM = rm -rf

all:	${NAME}
		${RM} ${OBJS} 
		${RM} ./libft/*.o

${NAME}: ${OBJS}
	$(MAKE) bonus -C ./libft
	${CC} ${OBJS} ./libft/libft.a -o ${NAME}

clean:
	@$(MAKE) -C libft fclean
	@${RM} ${OBJS}

fclean: clean
	@${RM} ${NAME}

re: fclean all

.PHONY: clean fclean re all