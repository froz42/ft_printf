# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tmatis <tmatis@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/10/08 16:38:19 by tmatis            #+#    #+#              #
#    Updated: 2020/11/22 17:41:17 by tmatis           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS		= ft_memcpy.c ft_strchr.c ft_strdup.c ft_strlcat.c ft_strlcpy.c\
			  ft_strrchr.c ft_strlen.c ft_strlcpy.c ft_strnstr.c\
			  ft_strncmp.c ft_isalnum.c ft_isalpha.c ft_isascii.c \
			  ft_isprint.c ft_toupper.c ft_tolower.c ft_isdigit.c ft_memmove.c \
			  ft_memccpy.c ft_memset.c ft_bzero.c ft_memcmp.c ft_memchr.c ft_calloc.c\
			  ft_atoi.c ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c\
			  ft_itoa.c ft_strmapi.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c\
			  ft_putnbr_fd.c ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c\
			  ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c ft_strnlen.c ft_strncpy.c\
			  ft_strcmp.c ft_islower.c ft_isupper.c ft_str_is_alpha.c ft_str_is_lowercase.c \
			  ft_str_is_uppercase.c ft_strequ.c ft_assert.c

OBJS		= ${SRCS:.c=.o}

NAME		= libft.a

.c.o:
			gcc -Wall -Wextra -Werror -c $< -o ${<:.c=.o}

$(NAME):	${OBJS}
			ar -rcs $@ $^

all:		${NAME}

clean:
			rm -f ${OBJS} ${BONUS_OBJS}

fclean:		clean
			rm -f ${NAME}

re:			fclean all


.PHONY:		all clean fclean re
