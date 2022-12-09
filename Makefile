##
## EPITECH PROJECT, 2022
## projet
## File description:
## Makefile
##

SRC	=	src/main.c		\
		src/open_win.c	\
		src/background.c	\
		src/cat.c	\
		src/tools.c	\
		src/mouse.c	\
		src/sound.c	\
		src/score.c	\
		src/menu.c	\
		src/cat_menu.c	\
		src/drawer.c	\
		lib/my/my_putchar.c	\
		lib/my/my_putstr.c	\
		lib/my/my_strlen.c	\
		lib/my/my_put_nbr.c	\


OBJ	=	$(SRC:.c=.o)

NAME	=	my_hunter

CFLAGS	=	-Wall -Wextra

COMPIL	=	-lcsfml-graphics -lcsfml-window -lcsfml-audio -lcsfml-system

all:	$(NAME)

$(NAME): $(OBJ)
		gcc -o $(NAME) $(SRC) $(COMPIL) -g3

clean:
		$(RM) *.o
		$(RM) src/*.o
		$(RM) lib/my/*.o
		$(RM) coding-style-reports.log

fclean: clean
		$(RM) $(NAME)

re: clean fclean all

.PHONY: all clean fclean re
