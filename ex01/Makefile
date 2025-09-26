
NAME = PhoneBook

CPP = c++

FLAGS = -Wall -Werror -Wextra -std=c++98

SRC = PhoneBook.cpp

OBJ = $(SRC:.cpp=.o)


all : $(NAME)

$(NAME) : $(OBJ)
	$(CPP) $(FLAGS) -o $@

%.cpp:%.o
	$(CPP) $(FLAGS)  -c  $< -o $@
