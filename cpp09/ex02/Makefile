RED=\033[1;31m
GREEN=\033[1;32m
YELLOW=\033[1;33m
BLUE=\033[1;34m
MAGENTA=\033[1;35m
CYAN=\033[1;36m
END=\033[0m

CC = g++
SRCS = main.cpp PmergeMe.cpp
HEADERS = PmergeMe.hpp
OBJ = $(SRCS:%.cpp=$(OBJ_DIR)/%.o)
OBJ_DIR = obj
NAME = PmergeMe

ifdef DEBUG
CXXFLAGS = -Wall -Werror -Wextra -std=c++98 -pedantic -g -fsanitize=address
else
CXXFLAGS = -Wall -Werror -Wextra -std=c++98 -pedantic
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

run:
	@ARG=`seq -w 1 10000 | shuf -n 3000 | paste -s -d ' '`; \
	./PmergeMe $$ARG

.PHONY: all clean fclean re debug