# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tpouget <cassepipe@ymail.com>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/05/23 16:37:33 by tpouget           #+#    #+#              #
#    Updated: 2021/05/13 21:03:18 by tpouget          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#################
##  VARIABLES  ##
#################

PHONY			=	all clean fclean re 

BLACKLIST		=	checker.c

SOURCEFILES		=	$(filter-out ${BLACKLIST}, $(wildcard *.c))

OBJECTFILES		=	$(patsubst %.c,obj/%.o,$(SOURCEFILES))
	
HEADERS			=	$(wildcard *.h)		
	
CFLAGS			=	-Wall -Wextra  -g3

CC	  		  	=	gcc

SANITIZER		=	-fsanitize=address

NAME			=	prog


#	Rules

all:			${NAME} 

${NAME}:		${OBJECTFILES} 
				${CC} ${SANITIZER} ${OBJECTFILES} -o $@

obj/%.o:		%.c	Makefile ${HEADERS}| obj
				${CC} ${CFLAGS} -c $< -o $@

obj:			
				mkdir obj

clean:			
				rm -rf obj

fclean:			clean
				rm -rf miniRT

re:				fclean all

.PHONY:			
				${PHONY}	
