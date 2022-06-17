
NAME = multi

SRC = main.c list_utils.c utils.c

OBJ = ${SRC:.c=.o}

CFLAGS = -Wall -Wextra -Werror


all : ${NAME}

${NAME} : ${OBJ}
	@${CC} ${OBJ} -o ${NAME}
	@echo "multi is created"

clean :
	@rm -f ${OBJ}
	@echo "objects are removed"

fclean : clean
	@rm -f ${NAME}

re : fclean all

%.o : %.c
	@${CC} ${CFLAGS} -c $<
	
.PHONY: clean all fclean re