# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tmatis <tmatis@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/10/08 16:38:19 by tmatis            #+#    #+#              #
#    Updated: 2020/12/18 16:47:37 by tmatis           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS_LIBFT	= ft_memcpy.c ft_strchr.c ft_strdup.c ft_strlcat.c ft_strlcpy.c\
			  ft_strrchr.c ft_strlen.c ft_strlcpy.c ft_strnstr.c\
			  ft_strncmp.c ft_isalnum.c ft_isalpha.c ft_isascii.c \
			  ft_isprint.c ft_toupper.c ft_tolower.c ft_isdigit.c ft_memmove.c \
			  ft_memccpy.c ft_memset.c ft_bzero.c ft_memcmp.c ft_memchr.c ft_calloc.c\
			  ft_atoi.c ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c\
			  ft_itoa.c ft_strmapi.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c\
			  ft_putnbr_fd.c ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c\
			  ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c ft_strnlen.c ft_strncpy.c\
			  ft_strcmp.c ft_islower.c ft_isupper.c ft_str_is_alpha.c ft_str_is_lowercase.c \
			  ft_str_is_uppercase.c ft_strequ.c ft_assert.c ft_christr.c ft_utf8_encode.c\
			  ft_putwstr_fd.c ft_wstrlen.c ft_wstrnlen.c ft_wstrtostr.c ft_realloc.c\
			  ft_wstr_strlen.c ft_strcpy.c 

SRCS_PRINTF	= ft_printf.c ft_buffutils.c ft_parsesyntax.c ft_parseutils.c\
			  ft_char_conversion.c ft_lengths.c ft_str_conversion.c\
			  ft_int_conversion.c ft_nbrutils.c ft_conversion.c\
			  ft_uint_conversion.c ft_uhex_conversion.c ft_ptr_conversion.c\
			  ft_n_conversion.c

SRCS_TESTS	= ft_test.c ft_test_syntax.c ft_test_buffer.c ft_test_char.c ft_test_str.c\
			  ft_test_int.c

OBJS_LIBFT	= $(addprefix libft/, ${SRCS_LIBFT:.c=.o})
OBJS_PRINTF = $(addprefix srcs/, ${SRCS_PRINTF:.c=.o})
OBJS_TESTS 	= $(addprefix tests/, ${SRCS_TESTS:.c=.o})

NORMINETTE_PATH = norminette

NAME		= libftprintf.a

.c.o:
			@echo Compiling: $<
			@gcc -Wall -Wextra -Werror -c $< -o ${<:.c=.o}

$(NAME):	${OBJS_LIBFT} ${OBJS_PRINTF}
			@echo Linking library...
			@ar -rcs $@ ${OBJS_LIBFT} ${OBJS_PRINTF}

all:		${NAME}

clean:
			@echo CLeaning OBJS and tests...
			@rm -f ${OBJS_LIBFT} ${OBJS_PRINTF} ${OBJS_TESTS} test

fclean:		clean
			@echo CLeaning library...
			@rm -f ${NAME}

re:			fclean all

bonus:		all

test:		${NAME} ${OBJS_TESTS}
			@echo Compiling tests with -fsanitize=address -fsanitize=undefined
			@gcc -Wall -Wextra -Werror -fsanitize=address -fsanitize=undefined -o ./test ${OBJS_TESTS} -L. -lftprintf

run_test:	test
			@echo "Running tests.."
			@sleep 2
			@./test
			@echo "Everything ok ?"

norminette:
			@echo "------------ NORMINETTE ------------"
			${NORMINETTE_PATH} $(addprefix srcs/,${SRCS_PRINTF}) $(addprefix tests/,${SRCS_TESTS}) $(addprefix libft/,${SRCS_LIBFT}) ./ft_printf.h ./srcs/ft_printf.h
			@echo "-----------------------------------"


.PHONY:		all clean fclean re run_test norminette bonus
