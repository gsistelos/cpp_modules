NAME	=	Moar_brainz!

SRC		=	main.cpp Zombie.cpp zombieHorde.cpp

OBJ		=	$(SRC:.cpp=.o)

CC		=	c++

CFLAGS	=	-Wall -Werror -Wextra -std=c++98

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) -o $(NAME)

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ)

fclean:
	$(RM) $(OBJ)
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
