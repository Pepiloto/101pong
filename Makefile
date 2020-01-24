##
## EPITECH PROJECT, 2019
## 101pong
## File description:
## Pong
##

SRC	=	src/pong.c	\
		src/vector_position.c	\
		src/vector_velocity.c

OBJ	=	$(SRC:.c=.o)

NAME	=	101pong

all:	$(OBJ)
	gcc -o $(NAME) $(OBJ) -lm

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all