SRC = main.cpp Conversion.cpp
INC = Conversion.hpp
CC = c++
RM = rm -f
CPPFLAGS = -Wall -Wextra -Werror -std=c++98
NAME = convert

all: $(NAME)

$(NAME): $(SRC) $(INC)
	$(CC) $(CPPFLAGS) $(SRC) -o $(NAME)

clean:

fclean: clean
	$(RM) $(NAME)

re: fclean $(NAME)

.PHONY: all clean fclean re
