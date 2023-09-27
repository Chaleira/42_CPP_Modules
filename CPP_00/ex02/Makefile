NAME = logs_file

CC = c++

SRCS = Account.cpp tests.cpp

CPPFLAGS = -Wall -Werror -Wextra -std=c++98 -I./

RM = rm -fr

all : $(NAME)

$(NAME):
			@$(CC) $(CPPFLAGS) $(SRCS) -o $(NAME)

clean:			
				@$(RM) $(OBJS)	

fclean:			clean
				@$(RM) $(NAME)

re:				fclean $(NAME)

r:				re
				@valgrind ./$(NAME)
