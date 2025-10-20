
NAME = PhoneBook

CPP = c++

FLAGS = -Wall -Werror -Wextra -std=c++98

SRC = PhoneBook.cpp

OBJ = $(SRC:.cpp=.o)


all : $(NAME)

$(NAME) : $(OBJ)
	$(CPP) $(FLAGS) $(OBJ) -o $@

%.o:%.cpp Contact.h PhoneBook.h
	$(CPP) $(FLAGS) -c  $< -o $@

clean:
	rm -rf $(OBJ)

re : fclean all 

fclean : clean
	rm -rf $(NAME)