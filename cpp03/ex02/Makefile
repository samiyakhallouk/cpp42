NAME = ex02
CC = c++
CFLAGS = -Wall -Werror -Wextra -std=c++98
HEAD = ClapTrap.hpp FragTrap.hpp ScavTrap.hpp
RM = rm -f
SRC = main.cpp ClapTrap.cpp FragTrap.cpp ScavTrap.cpp
OBJ = $(SRC:.cpp=.o)

%.o: %.cpp $(HEAD)
	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) -o $(NAME)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME) 

re: fclean all