NAME	=	phonebook

SRC		=	$(addprefix src/, Contact.cpp main.cpp PhoneBook.cpp utils.cpp)

OBJ		=	$(SRC:.cpp=.o)

CC		=	c++

CFLAGS	=	-Wall -Werror -Wextra -std=c++98

INCLUDE	=	-I include/

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) -o $(NAME)

%.o: %.cpp
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

clean:
	$(RM) $(OBJ)

fclean:
	$(RM) $(OBJ)
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
