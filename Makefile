# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: adben-mc <adben-mc@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/02 00:45:16 by adben-mc          #+#    #+#              #
#    Updated: 2022/02/06 22:51:06 by adben-mc         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS_DIR		=	srcs/
SRCS			=	$(SRCS_DIR)main.c			\
					$(SRCS_DIR)push.c			\
					$(SRCS_DIR)swap.c			\
					$(SRCS_DIR)reverse_rotate.c	\
					$(SRCS_DIR)rotate.c			\
					$(SRCS_DIR)median.c			\
					$(SRCS_DIR)sort.c

OBJS			= 	${SRCS:.c=.o}

EXEC			= 	push_swap

CC				=	gcc
RM				=	rm -f
CFLAGS			=	-Wall -Werror -Wextra #-g3 -fsanitize=address

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
