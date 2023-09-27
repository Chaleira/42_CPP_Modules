NAME = PhoneBook

CC = c++

SRCS = Main.cpp PhoneBook.cpp Contact.cpp

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
