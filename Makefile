NAME = a.out

CC = clang++ -std=c++98

CFLAGS = -Wall -Wextra -Werror

SRCS = main.cpp vector_test.cpp list_test.cpp map_test.cpp stack_test.cpp queue_test.cpp

OBJS = $(SRCS:.cpp=.o)

.cpp.o:
	$(CC) $(CFLAGS) -c $< -o $(<:.cpp=.o)

all:	$(NAME)

$(NAME):	$(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean:
	rm -f $(OBJS)

fclean:	clean
	rm -f $(NAME)

re:	fclean all

.PHONY: all clean fclean re
