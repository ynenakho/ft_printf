# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ynenakho <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/26 19:51:51 by ynenakho          #+#    #+#              #
#    Updated: 2017/12/02 23:01:25 by ynenakho         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

LIBFT = libft/ft_isascii.c libft/ft_memcmp.c libft/ft_strchr.c libft/ft_strlen.c libft/ft_strrchr.c \
		libft/ft_atoi.c libft/ft_isdigit.c libft/ft_memcpy.c libft/ft_strcmp.c libft/ft_strncat.c \
		libft/ft_strstr.c libft/ft_bzero.c libft/ft_isprint.c libft/ft_memmove.c libft/ft_strcpy.c \
		libft/ft_strncmp.c libft/ft_tolower.c libft/ft_isalnum.c libft/ft_memccpy.c libft/ft_memset.c \
		libft/ft_strdup.c libft/ft_strncpy.c libft/ft_toupper.c libft/ft_isalpha.c libft/ft_memchr.c \
		libft/ft_strcat.c libft/ft_strlcat.c libft/ft_strnstr.c \
		libft/ft_memalloc.c libft/ft_memdel.c libft/ft_strnew.c libft/ft_strdel.c libft/ft_strclr.c \
		libft/ft_striter.c libft/ft_striteri.c libft/ft_strmap.c libft/ft_putchar.c libft/ft_putstr.c \
		libft/ft_strmapi.c libft/ft_strequ.c libft/ft_strnequ.c libft/ft_strsub.c libft/ft_strjoin.c \
		libft/ft_strtrim.c libft/ft_putnbr.c libft/ft_strsplit.c libft/ft_itoa.c libft/ft_putendl.c \
		libft/ft_putchar_fd.c libft/ft_putstr_fd.c libft/ft_putendl_fd.c libft/ft_putnbr_fd.c libft/ft_strnlen.c\
		libft/ft_lstnew.c libft/ft_lstdelone.c libft/ft_lstadd.c libft/ft_lstiter.c libft/ft_lstmap.c \
		libft/ft_lstdel.c libft/ft_bzero_bwd.c libft/ft_memcpy_bwd.c libft/ft_isspace.c libft/ft_print2d.c \
		libft/ft_print_byte.c libft/ft_bubblesort.c libft/ft_print_array_int.c libft/ft_push.c libft/ft_lstcount.c \
		libft/ft_lstpush.c libft/ft_strnjoin.c libft/ft_strmjoin.c
PRINTF = conversions.c ft_printf.c functions.c handle_char.c handle_int.c handle_str.c ft_itoaf.c \
		 handle_addr.c handle_hex.c handle_octal.c handle_uint.c parse_funcs.c spec_handling.c \
		 ft_wcharlen.c handle_wchar.c handle_wstr.c ft_wstr_helper.c

SRCS = $(LIBFT)  $(PRINTF)

RM = @rm -f

EXE = test

all: $(NAME)

$(NAME):
	@gcc -Wall -Wextra -Werror -c -g $(SRCS)
	@ar rc $(NAME) *.o
	@ranlib $(NAME)
	@echo "\033[33;32mLibft: Ready >:D"

clean:
	$(RM) *.o
	@echo "\033[33mLibft: cleaned..."

fclean: clean
	$(RM) $(NAME)
	@echo "\033[31mLibft: fcleaned..."

re: fclean all
