
NAME = Account

CPP = c++

FLAGS = -Wall -Werror -Wextra -std=c++98

SRC = tests.cpp Account.cpp

OBJ = $(SRC:.cpp=.o)


all : $(NAME)

$(NAME) : $(OBJ)
	$(CPP) $(FLAGS) $(OBJ) -o $@

%.o:%.cpp Account.hpp 
	$(CPP) $(FLAGS) -c  $< -o $@

clean:
	rm -rf $(OBJ)

re : fclean all 

fclean : clean
	rm -rf $(NAME)

