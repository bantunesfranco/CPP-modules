RED=\033[1;31m
GREEN=\033[1;32m
YELLOW=\033[1;33m
BLUE=\033[1;34m
MAGENTA=\033[1;35m
CYAN=\033[1;36m
END=\033[0m

CC = g++
SRCS = main.cpp PhoneBook.cpp Contact.cpp
HEADERS = PhoneBook.hpp Contact.hpp
INCS = -I .
OBJ = $(SRCS:%.cpp=$(OBJ_DIR)/%.o)
OBJ_DIR = obj
NAME = phonebook

ifdef DEBUG
CPPFLAGS = -Wall -Werror -Wextra -std=c++98 -pedantic -g -fsanitize=address
else
CPPFLAGS = -Wall -Werror -Wextra -std=c++98 -pedantic
endif

all: $(NAME)

$(NAME): $(OBJ)
	@echo "${MAGENTA}Creating $@${END}"
	@$(CC) $(CPPFLAGS) $(INCS) $(OBJ) -o $(NAME)
	@echo "${GREEN}Done!${END}"

$(OBJ_DIR)/%.o: %.cpp $(HEADERS) | $(OBJ_DIR)
	@echo "${BLUE}Compiling $<${END}"
	@$(CC) $(CPPFLAGS) $(INCS) -c -o $@ $<

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