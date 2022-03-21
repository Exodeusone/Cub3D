# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jbonniva <jbonniva@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/22 11:35:26 by jbonniva          #+#    #+#              #
#    Updated: 2022/03/21 14:45:04 by jbonniva         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Variable de modification dans le makefile :

# Style de typo :
_FIN		=	\033[0m
_GRAS		=	\033[1m
_ITA		=	\033[3m
_SOUS		=	\033[4m
_CLIGN		=	\033[5m
_REV		=	\033[7m

# Couleurs des lettres :
_GRIS		=	\033[30m
_ROUGE		=	\033[31m
_VERT		=	\033[32m
_JAUNE		=	\033[33m
_BLEU		=	\033[34m
_VIOLET		=	\033[35m
_CYAN		=	\033[36m
_BLANC		=	\033[37m

# Couleurs de fonds :
_IGRIS		=	\033[40m
_IROUGE		=	\033[41m
_IVERT		=	\033[42m
_IJAUNE		=	\033[43m
_IBLEU		=	\033[44m
_IVIOLET	=	\033[45m
_ICYAN		=	\033[46m
_IBLANC		=	\033[47m

#General variable :
NAME	= cub3D

CC		= gcc

CFLAG	= -Wall -Werror -Wextra

#SRCS :
SRCS_NAME	= main.c\
			  ft_check_name_map.c\
			  ft_utils.c\
			  get_next_line_utils.c\
			  get_next_line.c\
			  ft_putmsg.c\
			  ft_parsing_map.c\
			  ft_clean_garbage.c\
			  ft_malloc.c\
			  garbage_collector.c\
			  ft_create_map.c\

SRCS_PATH	= cub3D_srcs


#INCLUDE :

INC_PATH	= cub3D_include

#FOR_COMPIL :

SRCS 	= 	${addprefix ${SRCS_PATH}/,${SRCS_NAME}}

OBJS	=	${SRCS:.c=.o}

#Regles :
all:	${NAME}

${NAME}:	${OBJS} ${INC_PATH}/cub3D.h
			$(CC) ${CFLAG} ${OBJS} -Lmlx -lmlx -L/usr/lib -I mlx -lXext -lX11 -lm -lz -o ${NAME}


%.o : %.c
	${CC} ${CFLAG} -I/usr/include -Imlx -c $< -o $@

clean:
		${RM} ${OBJS}

fclean:		clean
			${RM} ${NAME}

re:		fclean all

.PHONY:	all clean fclean re
