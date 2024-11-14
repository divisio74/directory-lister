##
## EPITECH PROJECT, 2024
## B-CPE-101-LYN-1-1-myprintf-pierre.baud
## File description:
## Makefile
##

SRC		=		my_ls.c \
				annexe1.c \
				annexel.c \
				flagl.c \
				fonction_tri.c \
				fonction_tri_t.c \
				pre_ls.c \
				main.c \



OBJ 	=		$(SRC:.c=.o)

NAME    = 		my_ls


all: 	$(NAME)

$(NAME): 		$(OBJ)
		gcc -o $(NAME) $(OBJ)
		ar rc libmy.a $(OBJ)

clean:
		rm -f $(OBJ)

fclean: clean
		rm -f $(NAME)

re: 	fclean all
