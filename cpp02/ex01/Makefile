NAME = ex01
CC = c++
CFLAGS = -Wall -Werror -Wextra -std=c++98
HEAD = Fixed.hpp
RM = rm -f
SRC = main.cpp Fixed.cpp
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