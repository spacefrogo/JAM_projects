##
## EPITECH PROJECT, 2019
## makefile
## File description:
## makefile
##

NAME = my_streetart

SRC = $(shell find . -name "*.c" -o -name "*.cpp")
CC = gcc

H = ./include/

all: $(NAME)

$(NAME):
	$(CC) $(SRC) -I$(H) -o $(NAME) -lm  -lcsfml-graphics -lcsfml-system -lcsfml-window

clean:
	find . -name '*.gc*' -o -name '*.o' -o -name '*.out' -delete

fclean: clean
	rm -f $(NAME)

re: fclean all

tests_run:
	$(MAKE) -C ./tests/
	./tests/units

.PHONY: all clean fclean re
