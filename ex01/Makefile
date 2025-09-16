NAME		= serializer

CXX			= c++
CFLAGS		= -Wall -Wextra -Werror -std=c++98

SRC			= main.cpp Serializer.cpp
OBJ			= $(SRC:.cpp=.o)

all:		$(NAME)

$(NAME):	$(OBJ)
			$(CXX) $(CFLAGS) -o $@ $(OBJ)

# Explicit dependencies
main.o:			main.cpp Serializer.hpp Data.hpp
Serializer.o:	Serializer.cpp Serializer.hpp Data.hpp

%.o: %.cpp
	$(CXX) $(CFLAGS) -c $< -o $@

clean:
			rm -f $(OBJ)

fclean: 	clean
			rm -f $(NAME)

re: 		fclean all

.PHONY: all clean fclean re
