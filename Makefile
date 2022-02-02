# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: adben-mc <adben-mc@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/02 00:45:16 by adben-mc          #+#    #+#              #
#    Updated: 2022/02/02 01:04:40 by adben-mc         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #



SRCS			=	main.c

OBJS			= 	${SRCS:.c=.o}

EXEC			= 	push_swap

CC				=	gcc
RM				=	rm -f
CFLAGS			=	-Wall -Werror -Wextra

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
