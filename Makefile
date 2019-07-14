# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tkatolik <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/05/23 16:53:05 by tkatolik          #+#    #+#              #
#    Updated: 2019/07/14 01:24:52 by tkatolik         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	:= ft_ssl

SRCDIR	:=	srcs
INCDIR	:=	includes
OBJDIR	:=	obj
LIBDIR	:=	libft

#SRC		:=	ssl_main.c \
			ssl_main_read_n_print.c \
			padding.c \
		
#SRC		+=	md5.c \
			mixer_md5.c \
			sha256.c \
			mixer_sha256.c \
			sha512.c \
			mixer_sha512.c \
			sha1.c \
			mixer_sha1.c

SRC		:=	$(addprefix $(SRCDIR)/,*.c)
OBJ		:=	$(addprefix $(OBJDIR)/,*.o)

CC		:=	gcc
#DEBUG	:=	-g
#DEBUG	+=	-fsanitize=address

FLAGS	:=	-Wall -Wextra -Werror
FLAGS	+=	-c -I

all: $(NAME)
	@echo "\n ______________ ALL: EVERYTHING IS DONE ______________ \n"

$(NAME): OBJ
	$(CC) $(DEBUG) $(OBJ) -o $(NAME) ./libft/libft.a
	@echo "\n __________ (NAME): DONE ________\n\n"

OBJ: LIB
	mkdir $(OBJDIR)
	$(CC) -g $(FLAGS) $(INCDIR) $(SRC)
	mv *.o ./$(OBJDIR)
	@echo "\n __________ (OBJ): DONE ________\n\n"

LIB:	
	@make -C $(LIBDIR)
	@echo "\n __________ LIB: DONE ________\n\n"

clean:
	@make -C $(LIBDIR) clean
	rm -rf $(OBJDIR)
	@echo "\n __________ CLEAN: DONE ________\n\n"

fclean: clean
	@make -C $(LIBDIR) fclean
	rm -f $(NAME)
	@echo "\n __________ FCLEAN: DONE ________\n\n"

re: fclean all
