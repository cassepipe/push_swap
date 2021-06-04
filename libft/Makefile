# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tpouget <cassepipe@ymail.com>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/05/23 16:37:33 by tpouget           #+#    #+#              #
#    Updated: 2021/04/19 17:09:52 by tpouget          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#################
##  VARIABLES  ##
#################

#	Sources

SRC			=	ft_atoi.c    			\
				ft_strlcat.c			\
				ft_strlcpy.c 			\
				ft_strncmp.c 			\
				ft_bzero.c   			\
				ft_calloc.c  			\
				ft_isalnum.c 			\
				ft_isalpha.c 			\
				ft_isascii.c 			\
				ft_isdigit.c 			\
				ft_isprint.c 			\
				ft_isspace.c			\
				ft_memset.c  			\
				ft_memcpy.c 			\
				ft_memchr.c 			\
				ft_memccpy.c			\
				ft_memmove.c			\
				ft_memcmp.c				\
				ft_strchr.c				\
				ft_strdup.c				\
				ft_strndup.c			\
				ft_strlen.c  			\
				ft_strncmp.c 			\
				ft_strrchr.c 			\
				ft_tolower.c 			\
				ft_toupper.c 			\
				ft_strnstr.c 			\
				ft_substr.c 			\
				ft_strjoin.c 			\
				ft_strjoin_and_free.c	\
				ft_strtrim.c 			\
				ft_split.c				\
				ft_itoa.c				\
				ft_strmapi.c			\
				ft_putchar_fd.c			\
				ft_putstr_fd.c			\
				ft_putendl_fd.c			\
				ft_putnbr_fd.c			\
				ft_strnstr.c 			\
				ft_lstnew.c				\
				ft_lstsize.c			\
				ft_lstadd_front.c		\
				ft_lstadd_back.c		\
				ft_lstlast.c			\
				ft_lstdelone.c			\
				ft_lstclear.c			\
				ft_lstiter.c			\
				ft_lstmap.c				\
				get_next_line.c			\
				ft_printf/repr.c		\
				ft_printf/pad.c			\
				ft_printf/ft_vdprintf.c	\
				ft_printf/ft_printf.c	\
				ft_printf/ft_lutoa_base.c 	\
				ft_printf/ft_dprintf.c		\
				ft_printf/format_utils.c	\


#	Includes
INCLUDES		=	libft.h	get_next_line.h	

#	Objects
OBJS		= 	${SRC:.c=.o}

#	Output
NAME			= 	libft.a

#	Compiler
CFLAGS		=	-Werror -Wall -Wextra -g3

RM			= 	rm -rf

AR			= 	ar rcs

CC			= 	gcc

ATTRIBUT 	= 	-c

#	Rules

all:			${NAME}

-c.o:			
				${CC} ${CFLAGS} ${ATTRIBUT} $< -o $(<:.c=.o) -I${INCLUDES}

${NAME}:		${OBJS} Makefile
				${AR} ${NAME} ${OBJS}

clean:			
				${RM} ${OBJS} ${OBJS_B}

fclean:			clean
				${RM} ${NAME}

re:				fclean all

.PHONY:			all clean fclean re
