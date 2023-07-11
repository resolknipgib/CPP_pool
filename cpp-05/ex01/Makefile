SRC = main.cpp Bureaucrat.cpp Form.cpp
INC = Bureaucrat.hpp Form.hpp
CC = c++
RM = rm -f
CPPFLAGS = -Wall -Wextra -Werror -std=c++98
NAME = Form_up_maggots

all: $(NAME)

$(NAME): $(SRC) $(INC)
	$(CC) $(CPPFLAGS) $(SRC) -o $(NAME)

clean:

fclean: clean
	$(RM) $(NAME)

re: fclean $(NAME)

.PHONY: all clean fclean re