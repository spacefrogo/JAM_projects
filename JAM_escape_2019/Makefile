##
## EPITECH PROJECT, 2020
## jello
## File description:
## jello
##

NAME = EscapeRona	
LDFLAGS =  -lsfml-graphics -lsfml-window -lsfml-system
CCPP = g++	
SRC =	./main.cpp		\
	./view/Display.cpp	\
	./Errors.cpp		\
	./CoronaStats.cpp 	\
	./Alert.cpp

OBJ = $(SRC:.cpp=.o)

CPPFLAGS = -Wextra -Wall -I. --std=c++11

all: $(NAME)

$(NAME): $(OBJ)
	$(CCPP) -o $(NAME) $(OBJ) $(LDFLAGS)

clean:
	$(foreach var, $(OBJ), if [ -e $(var) ] ; then $(RM) $(var) ; fi;)
	rm -f vgcore.*

fclean: clean
	rm -f $(NAME)

re: fclean all

%.o: %.cpp
	$(CCPP) $(CPPFLAGS) -o $@ -c $<

.PHONY: all clean fclean re
