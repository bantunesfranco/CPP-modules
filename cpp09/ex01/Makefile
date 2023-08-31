RED=\033[1;31m
GREEN=\033[1;32m
YELLOW=\033[1;33m
BLUE=\033[1;34m
MAGENTA=\033[1;35m
CYAN=\033[1;36m
END=\033[0m

CC = g++
SRCS = main.cpp
HEADERS = easyfind.hpp
OBJ = $(SRCS:%.cpp=$(OBJ_DIR)/%.o)
OBJ_DIR = obj
NAME = RPN

ifdef DEBUG
CXXFLAGS = -Wall -Werror -Wextra -pedantic -g -fsanitize=leak
else
CXXFLAGS = -Wall -Werror -Wextra -pedantic
endif

all: $(NAME)

$(NAME): $(OBJ) $(HEADERS)
	@echo "${MAGENTA}Creating $@${END}"
	@$(CC) $(CXXFLAGS) $(OBJ) -o $(NAME)
	@echo "${GREEN}Done!${END}"

$(OBJ_DIR)/%.o: %.cpp | $(OBJ_DIR)
	@echo "${BLUE}Compiling $<${END}"
	@$(CC) $(CXXFLAGS) -c -o $@ $<

$(OBJ_DIR):
	@mkdir $(OBJ_DIR)

clean:
	@echo "${RED}Removing $(OBJ_DIR)${END}"
	@rm -rf $(OBJ_DIR)

fclean: clean
	@echo "${RED}Removing ${NAME}${END}"
	@rm -rf $(NAME)

re: fclean all

debug: fclean
	@echo "$(YELLOW)Debug Mode -g -fsanitize=address$(END)"
	@$(MAKE) DEBUG=1 all


.PHONY: all clean fclean re debug