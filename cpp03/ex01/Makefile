NAME = ScavTrap

CC = c++
CFLAGS = -std=c++98 -Wall -Werror -Wextra -I include

VPATH = src
FILES = main.cpp \
		ClapTrap.cpp \
		ScavTrap.cpp

OBJS = $(FILES:%.cpp=$(OBJ_DIR)/%.o)
OBJ_DIR = obj

all: $(NAME)

$(OBJ_DIR)/%.o: %.cpp
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -I . -c $< -o $@ && printf "Compiling: $(notdir $<)\n"

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean:
	@rm -rf $(OBJ_DIR)
	@rm -f *.replace

fclean: clean
	@rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re