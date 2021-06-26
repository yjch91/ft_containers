NAME = a.out

CC = clang++ -std=c++98

CFLAGS = -Wall -Wextra -Werror

SRCS = main.cpp vector_test.cpp list_test.cpp map_test.cpp stack_test.cpp queue_test.cpp

SRCS_B = main_bonus.cpp set_test.cpp multiset_test.cpp multimap_test.cpp

OBJS = $(SRCS:.cpp=.o)

OBJS_B = $(SRCS_B:.cpp=.o)

.cpp.o:
	$(CC) $(CFLAGS) -c $< -o $(<:.cpp=.o)

all:	$(NAME)

$(NAME):	$(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean:
	rm -f $(OBJS) $(OBJS_B)

fclean:	clean
	rm -f $(NAME)

re:	fclean all

bonus:	$(OBJS_B)
	$(CC) $(CFLAGS) $(OBJS_B) -o $(NAME)

.PHONY: all clean fclean re bonus
