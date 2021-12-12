SERVER = server

CLIENT = client

HEADER = minitalk.h 

LIST_S = serv.c

LIST_C = cli.c

OBJ_S = ${patsubst %.c, %.o, ${LIST_S}}

OBJ_C = ${patsubst %.c, %.o, ${LIST_C}}

FLAGS = -Wall -Wextra -Werror

all : ${SERVER} ${CLIENT}

${SERVER} : ${OBJ_S}
	gcc -o ${SERVER} ${FLAGS} ${OBJ_S}

${CLIENT} : ${OBJ_C}
	gcc -o ${CLIENT} ${FLAGS} ${OBJ_C}

%.o : %.c ${HEADER}
	gcc ${FLAGS} -c $< -o $@

clean :
	rm -f ${OBJ_C} ${OBJ_S}

fclean : clean
	rm -f ${SERVER} ${CLIENT}

re : fclean all

.PHONY : all clean fclean re 