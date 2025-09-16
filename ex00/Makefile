NAME		= convert

CXX			= c++
CFLAGS		= -Wall -Wextra -Werror -std=c++98

SRC			= main.cpp ScalarConverter.cpp

OBJ			= $(SRC:.cpp=.o)

all:		$(NAME)

$(NAME):	$(OBJ)
			$(CXX) $(CFLAGS) -o $@ $(OBJ)

%.o: %.cpp
	$(CXX) $(CFLAGS) -c $< -o $@

clean:
			rm -f $(OBJ)

fclean: 	clean
			rm -f $(NAME)

re: 		fclean all

.PHONY: all clean fclean re
