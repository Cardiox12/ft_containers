CLANG = clang++
CFLAGS = -Wall -Werror -Wextra # -fsanitize=address # -std=c++98

SRCS = main.cpp
HEADERS = vector.hpp stack.hpp map.hpp

NAME = ft_containers

all: $(NAME)

$(NAME): $(SRCS) $(HEADERS)
	$(CLANG) $(CFLAGS) -o $(NAME) $(SRCS)

re: fclean all

clean: fclean

fclean:
	rm -f $(NAME)