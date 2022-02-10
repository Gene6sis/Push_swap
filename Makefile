# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: adben-mc <adben-mc@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/02 00:45:16 by adben-mc          #+#    #+#              #
#    Updated: 2022/02/10 14:47:13 by adben-mc         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS_DIR		=	srcs/
SRCS			=	$(SRCS_DIR)main.c			\
					$(SRCS_DIR)push.c			\
					$(SRCS_DIR)swap.c			\
					$(SRCS_DIR)reverse_rotate.c	\
					$(SRCS_DIR)rotate.c			\
					$(SRCS_DIR)median.c			\
					$(SRCS_DIR)sort.c			\
					$(SRCS_DIR)sortfirst.c		\
					$(SRCS_DIR)sortsecond.c		\
					$(SRCS_DIR)sortthird.c		\
					$(SRCS_DIR)sortlittle.c		\
					$(SRCS_DIR)utils.c			\
					$(SRCS_DIR)parsing.c		\
					$(SRCS_DIR)ft_check.c		\
					$(SRCS_DIR)ft_error.c

OBJS			= 	${SRCS:.c=.o}

EXEC			= 	push_swap

INC_DIR			=	./includes/.
CC				=	gcc
RM				=	rm -f
CFLAGS			=	-Wall -Wextra -Werror -I$(INC_DIR)#-g3 -fsanitize=address

PRINTF_DIR		=	ft_printf
PRINTF_LIB 		=	$(PRINTF_DIR)/libftprintf.a
PRINTF_FLAG  	=   -L ft_printf -lftprintf

all:		$(PRINTF_LIB) $(EXEC)

.c.o:
			${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

$(EXEC):	${OBJS}
			$(CC)  $(CFLAGS) $(OBJS) $(PRINTF_FLAG) -o $(EXEC)

$(PRINTF_LIB):
	@$(MAKE) -sC ft_printf all

clean:
			${RM} ${OBJS}
			@$(MAKE) -sC ft_printf clean

fclean:		clean
			${RM} ${EXEC}
			@$(MAKE) -sC ft_printf fclean

re:			fclean all

.PHONY:		all clean fclean re $(PRINTF_LIB)
