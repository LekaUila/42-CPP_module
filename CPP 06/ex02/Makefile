# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lflandri <lflandri@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/28 11:10:23 by lflandri          #+#    #+#              #
#    Updated: 2023/02/07 16:11:21 by lflandri         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME 		= ex02

MAKEFLAGS	= --no-print-directory

SRC 		=	main.cpp\
				Base.cpp\
				A.cpp\
				B.cpp\
				C.cpp




#couleur
BLACK		=\\e[0;30m
GREY		=\\e[1;30m
BLACKRED	=\\e[0;31m
PINK		=\\e[1;31m
BLACKGREEN	=\\e[0;32m
WHITEGREEN	=\\e[1;32m
ORANGE		=\\e[0;33m
YELLOW		=\\e[1;33m
BLACKBLUE	=\\e[0;34m
WHITEBLUE	=\\e[1;34m
BLACKPURPLE	=\\e[0;35m
WHITEPURPLE	=\\e[;1;35m
BLACKCYAN	=\\e[0;36m
WHITECYAN	=\\e[1;36m
WHITEGREY	=\\e[0;37m
WHITE		=\\e[1;37m

NEUTRE		= \\e[0;m

#effect
BLINK		=\\e[5m

RESET		=\\e[25m

all :	${NAME}
			@echo "${WHITEGREEN}PROGRAMME \"${BLINK}${NAME}${RESET}\" PRET POUR EXECUTION !${NEUTRE}"

${NAME}: ${SRC}
			@echo "${BLACKPURPLE}==================== CRÉATION ==================${WHITE}" 
			c++  -Wall -Wextra -Werror -std=c++98 -o ${NAME} ${SRC}
			@echo "${BLACKPURPLE}================== FIN CRÉATION ================${NEUTRE}" 

clean :
			@echo -n "${BLACKRED}"
			@echo "Nothing to supress"
			@echo -n "${NEUTRE}"

fclean :	#clean
			@echo -n "${BLACKRED}"
			rm -f ${NAME}
			@echo -n "${NEUTRE}"

re :		fclean all

rebonus : fclean bonus

.PHONY : all clean fclean re bonus