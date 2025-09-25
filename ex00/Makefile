

NAME = megaphone
CPP = c++ 
FLAGS = -Wall -Wextra -Werror -std=c++98
SRC = megaphone.cpp
OBJ = $(SRC:.cpp=.o)


all : $(NAME)


$(NAME) : $(OBJ)
	$(CPP) $(FLAGS) $(OBJ) -o $(NAME)


%.o:%.cpp 
	$(CPP) $(FLAGS) -c $< -o $@


fclean : clean
	rm -rf $(NAME)

clean :
	rm -rf $(OBJ)

re : fclean all 

.PHONY : clean
