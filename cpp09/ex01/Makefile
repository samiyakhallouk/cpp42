NAME = RPN
CC = c++
CFLAGS = -Wall -Werror -Wextra -std=c++98
HEAD = RPN.hpp
RM = rm -f
SRC = main.cpp RPN.cpp
OBJ = $(SRC:.cpp=.o)

%.o: %.cpp $(HEAD)
	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME) 

re: fclean all