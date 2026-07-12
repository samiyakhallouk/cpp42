NAME = ex01
CC = c++
CFLAGS = -Wall -Werror -Wextra -std=c++98
HEAD = Form.hpp Bureaucrat.hpp
RM = rm -f
SRC = main.cpp Form.cpp Bureaucrat.cpp
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