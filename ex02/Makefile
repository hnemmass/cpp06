NAME = Identifier

CXX = c++ -std=c++98 -Wall -Werror -Wextra

SRC = Base.cpp Generate.cpp Identify.cpp main.cpp
INC = Base.hpp A.hpp B.hpp C.hpp Generate.hpp Identify.hpp
OBJ = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(OBJ) -o $(NAME)

%.o: %.cpp $(INC)
	$(CXX) -c $< -o $@

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re