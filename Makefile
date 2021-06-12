# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tpouget <cassepipe@ymail.com>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/05/23 16:37:33 by tpouget           #+#    #+#              #
#    Updated: 2021/06/07 10:24:53 by tpouget          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#################
##  VARIABLES  ##
#################

PHONY			=	all clean fclean re 

BLACKLIST		=	

SOURCEFILES		=	$(filter-out ${BLACKLIST}, $(wildcard *.c))

OBJECTFILES		=	$(patsubst %.c,obj/%.o,$(SOURCEFILES))
	
HEADERS			=	$(wildcard *.h)		
	
CFLAGS			=	-Wall -Wextra  -g3

CC	  		  	=	gcc

SANITIZER		=	-fsanitize=address

NAME			=	prog


#	Rules

all:			${NAME} 

test:			${OBJECTFILES} libft/libft.a
				${CC} ${SANITIZER} ${OBJECTFILES} -Llibft -lft -lcriterion -o test 

${NAME}:		${OBJECTFILES} libft/libft.a
				${CC} ${SANITIZER} ${OBJECTFILES} -Llibft -lft -o $@

obj/%.o:		%.c	Makefile ${HEADERS}| obj
				${CC} ${CFLAGS} -c $< -o $@

obj:			
				mkdir obj

libft/libft.a:
				make -C libft

clean:			
				rm -rf obj

fclean:			clean
				rm -rf miniRT

re:				fclean all

.PHONY:			
				${PHONY}	
