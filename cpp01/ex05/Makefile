NAME = ex05
CC = c++
CFLAGS = -Wall -Werror -Wextra -std=c++98
HEAD = Harl.hpp
RM = rm -f
SRC = main.cpp Harl.cpp
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