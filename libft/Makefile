# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tmatis <tmatis@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/10/08 16:38:19 by tmatis            #+#    #+#              #
#    Updated: 2021/01/04 17:20:56 by tmatis           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


SRCS_ASSERT		= assert.c assert_utils.c

SRCS_CHAR		= ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c \
				  ft_islower.c ft_isprint.c ft_isupper.c ft_toupper.c \
				  ft_utf8_encode.c

SRCS_LST		= ft_lstadd_back.c ft_lstadd_front.c ft_lstclear.c \
				  ft_lstdelone.c ft_lstiter.c ft_lstmap.c ft_lstnew.c \
				  ft_lstsize.c

SRCS_MEMORY		= ft_bzero.c ft_memccpy.c ft_memcmp.c ft_memmove.c \
				  ft_realloc.c ft_calloc.c ft_memchr.c ft_memcpy.c ft_memset.c

SRCS_MISC		= ft_atoi.c ft_itoa.c

SRCS_PUT		= ft_putchar_fd.c ft_putnbr_fd.c ft_putstr_fd.c \
				  ft_putendl_fd.c ft_putstr.c ft_putwstr_fd.c

SRCS_STRING		= ft_christr.c ft_split.c ft_str_is_alpha.c \
				  ft_str_is_lowercase.c ft_str_is_uppercase.c ft_strcat.c \
				  ft_strchr.c ft_strcmp.c ft_strcpy.c ft_strdup.c ft_strequ.c \
				  ft_strjoin.c ft_strlcat.c ft_strlcpy.c ft_strlen.c \
				  ft_strmapi.c ft_strncat.c ft_strncmp.c ft_strncpy.c \
				  ft_strnlen.c ft_strnstr.c ft_strrchr.c ft_strtrim.c \
				  ft_substr.c

SRCS_WSTRING	= ft_wstr_strlen.c ft_wstrlen.c ft_wstrnlen.c ft_wstrtostr.c

OBJS_ASSERT		= $(addprefix assert/, ${SRCS_ASSERT:.c=.o})
OBJS_CHAR		= $(addprefix char/, ${SRCS_CHAR:.c=.o})
OBJS_LST		= $(addprefix lst/, ${SRCS_LST:.c=.o})
OBJS_MEMORY		= $(addprefix memory/, ${SRCS_MEMORY:.c=.o})
OBJS_MISC		= $(addprefix misc/, ${SRCS_MISC:.c=.o})
OBJS_PUT		= $(addprefix put/, ${SRCS_PUT:.c=.o})
OBJS_STRING		= $(addprefix string/, ${SRCS_STRING:.c=.o})
OBJS_WSTRING	= $(addprefix wstring/, ${SRCS_WSTRING:.c=.o})

NAME			= libft.a

.c.o:
			@echo Compiling: $<
			@clang -Wall -Wextra -Werror -c $< -o ${<:.c=.o}

$(NAME):	${OBJS_ASSERT} ${OBJS_CHAR} ${OBJS_LST} ${OBJS_MEMORY} \
			${OBJS_MISC} ${OBJS_PUT} ${OBJS_STRING} ${OBJS_WSTRING}
			@echo Linking library...
			@ar -rcs  $@ $^

all:		${NAME}

clean:
			@echo CLeaning OBJS 
			@rm -f ${OBJS_ASSERT} ${OBJS_CHAR} ${OBJS_LST} ${OBJS_MEMORY}\
				${OBJS_MISC} ${OBJS_PUT} ${OBJS_STRING} ${OBJS_WSTRING}
 
fclean:		clean
			@echo CLeaning library...
			@rm -f ${NAME}

re:			fclean all


.PHONY:		all clean fclean re
