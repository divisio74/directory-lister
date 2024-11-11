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
				struct.c \


OBJ 	=		$(SRC:.c=.o)

NAME    = 		libmy.a


all: 	$(NAME)

$(NAME): 		$(OBJ)
		gcc -c $(SRC)
		ar rc libmy.a $(OBJ)

clean:
		rm -f $(OBJ)

fclean: clean
		rm -f $(NAME)

re: 	fclean all
