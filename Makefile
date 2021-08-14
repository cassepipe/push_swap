# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tpouget <cassepipe@ymail.com>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/05/23 16:37:33 by tpouget           #+#    #+#              #
#    Updated: 2021/08/03 18:30:19 by tpouget          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#################
##  VARIABLES  ##
#################

PHONY			=	all clean fclean re test

BLACKLIST		=	push_swap.c checker.c 

SOURCEFILES		=	$(filter-out ${BLACKLIST}, $(wildcard *.c))

OBJECTFILES		=	$(patsubst %.c,obj/%.o,$(SOURCEFILES))
	
HEADERS			=	$(wildcard *.h)		
	
CFLAGS			=	-Wall -Wextra  -g3 -pedantic

CC	  		  	=	clang

SANITIZER		=	-fsanitize=address

NAME			=	prog


#	Rules

all:			push_swap  checker

test:			push_swap	
				cp push_swap push-swap-tester/
				push-swap-tester/test.sh

push_swap:		obj/push_swap.o ${OBJECTFILES} libft/libft.a
				${CC} ${SANITIZER} obj/push_swap.o ${OBJECTFILES} -Llibft -lft -o $@

checker:		obj/checker.o ${OBJECTFILES} libft/libft.a
				${CC} ${SANITIZER} obj/checker.o ${OBJECTFILES} -Llibft -lft -o $@

obj/%.o:		%.c	Makefile ${HEADERS} | obj
				${CC} ${CFLAGS} -c $< -o $@


obj:			
				mkdir obj

libft/libft.a:
				make -C libft

clean:			
				rm -rf obj

fclean:			clean
				rm -rf push_swap checker

re:				fclean all

.PHONY:			
				${PHONY}	
