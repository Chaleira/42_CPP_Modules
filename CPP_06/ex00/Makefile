NAME = convert

CC = c++

SRCS = main.cpp ScalarConverter.cpp

OBJS_PATH = obj/
SRC_PATH = sources/

CPPFLAGS = -Wall -Werror -Wextra -std=c++98 -Wshadow -I./includes -fsanitize=address

RM = rm -fr

$(OBJS): $(OBJS_PATH)

OBJS = $(SRCS:$(SRC_PATH)%.cpp=$(OBJS_PATH)%.o)

all : $(NAME)

$(OBJS_PATH)%.o: $(SRC_PATH)%.cpp | $(OBJS_PATH)
			@$(CC) $(CPPFLAGS) -c $< -o $@

$(OBJS_PATH):
	@mkdir -p $(OBJS_PATH)

$(NAME):	$(OBJS)
			@$(CC) $(CPPFLAGS) $(OBJS) -o $(NAME)

clean:			
				@$(RM) $(OBJS_PATH)	

fclean:			clean
				@$(RM) $(NAME)

re:				fclean $(NAME)

r:				re
				@valgrind ./$(NAME)