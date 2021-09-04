# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tpouget <cassepipe@ymail.com>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/05/23 16:37:33 by tpouget           #+#    #+#              #
#    Updated: 2021/09/04 16:26:06 by tpouget          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#################
##  VARIABLES  ##
#################

SOURCEFILES		=	atoi_error.c \
					bit_sort.c \
					check_duplicates.c \
					dll_operations.c \
					fat_int_radix_sort.c \
					loop_exec_stack_ops.c \
					new_int_array.c \
					order.c \
					print_operations.c \
					stack_operations.c \
					stack_rotate.c \
					stack_sort.c \
					stack_utils.c

HEADERS			=	atoi_error.h \
					bit_sort.h \
					check_duplicates.h \
					checker.h \
					dll_node.h \
					dll_operations.h \
					fat_int.h \
					fat_int_radix_sort.h \
					insertion_sort.h \
					loop_exec_stack_ops.h \
					new_int_array.h \
					order.h \
					print_operations.h \
					push_swap.h \
					stack.h \
					stack_operations.h \
					stack_rotate.h \
					stack_sort.h \
					stack_utils.h

INC/HEADERS		=	$(addprefix inc/, $(HEADERS))

OBJECTFILES		=	$(patsubst %.c, obj/%.o, $(SOURCEFILES))
	
CFLAGS			=	-Wall -Wextra -g3 -pedantic -Iinc -I.

CC	  		  	=	clang

SANITIZER		=	-fsanitize=address

NAME			=	push_swap

#	Rules

all:			$(NAME)

bonus:			all checker

$(NAME):		obj/push_swap.o ${OBJECTFILES} libft/libft.a
				${CC} ${SANITIZER} obj/push_swap.o ${OBJECTFILES} -Llibft -lft -o $@

checker:		obj/checker.o ${OBJECTFILES} libft/libft.a
				${CC} ${SANITIZER} obj/checker.o ${OBJECTFILES} -Llibft -lft -o $@

obj/%.o:		src/%.c	Makefile ${INC/HEADERS} | obj
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

test:			push_swap	
				push-swap-tester/test.sh

.PHONY:			all clean fclean re test bonus
