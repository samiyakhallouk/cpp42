NAME = megaphone
CC = c++
CFLAGS = -Wall -Werror -Wextra
RM = rm -f
SRC = megaphone.cpp
OBJ = $(SRC:.cpp=.o)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) -o $(NAME)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME) 

re: fclean all