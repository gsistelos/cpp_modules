NAME	=	I_dont_want_to_set_the_world_on_fire

SRC		=	AAnimal.cpp Brain.cpp Cat.cpp Dog.cpp main.cpp WrongAAnimal.cpp WrongCat.cpp

OBJ		=	$(SRC:.cpp=.o)

CC		=	c++

CFLAGS	=	-Wall -Werror -Wextra -std=c++98

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ)

fclean:
	$(RM) $(OBJ)
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
