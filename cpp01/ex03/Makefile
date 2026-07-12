NAME = ex03
CC = c++
CFLAGS =  -Wall -Werror -Wextra -std=c++98
HEADW = Weapon.hpp
HEADA = HumanA.hpp
HEADB = HumanB.hpp
RM = rm -f
SRC = main.cpp HumanA.cpp HumanB.cpp Weapon.cpp
OBJ = $(SRC:.cpp=.o)

%.o: %.cpp $(HEAD) $(HEADA) $(HEADB) 
	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) -o $(NAME)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME) 

re: fclean all