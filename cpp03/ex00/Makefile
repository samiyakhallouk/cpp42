NAME = ex00
CC = c++
CFLAGS = -Wall -Werror -Wextra -std=c++98
HEAD = ClapTrap.hpp
RM = rm -f
SRC = main.cpp ClapTrap.cpp
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