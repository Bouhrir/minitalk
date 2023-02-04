NAME	= server client

NAME_BONUS = server_bonus client_bonus

SRC 	= client.c server.c utiles.c 

SRC_BONUS = client_bonus.c server_bonus.c utiles_bonus.c 

OBJ 	= ${SRC:.c=.o}

OBJ_BONUS = ${SRC_BONUS:.c=.o} 

RM		= rm -f

CC      = cc

CFLAGS	= -Wall -Wextra -Werror

#Make standard colour 
RED        = "\033[0;31m"
GREEN     = "\033[0;32m"
YELLOW    = "\033[0;33m"

all     : ${NAME} 

bonus : ${NAME_BONUS}

${NAME} : ${OBJ}
		@echo ${GREEN}
		${CC} ${CFLAGS} server.o utiles.o -o server
		${CC} ${CFLAGS} client.o utiles.o -o client
	
${NAME_BONUS} : ${OBJ_BONUS}
		@echo ${YELLOW}
		${CC} ${CFLAGS} server_bonus.o utiles_bonus.o -o server_bonus
		${CC} ${CFLAGS} client_bonus.o utiles_bonus.o -o client_bonus

clean 	: 
		@echo ${RED} 
		${RM} ${OBJ} ${OBJ_BONUS}

fclean 	: clean
		${RM} ${NAME} ${NAME_BONUS} 

re 		: fclean all

.PHONY	: all bonus clean fclean re