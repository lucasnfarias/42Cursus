STD_BINARY		= 	std_containers
FT_BINARY		= 	ft_containers

SOURCE			= 	main.cpp
OBJECT			=	$(SOURCE:.cpp=.o)
OUTPUT_FILES    =   outputfiles/ft_output.txt outputfiles/std_output.txt

COMPILER			= 	c++

STD_FLAGS		= 	-Wall -Wextra -Werror -std=c++98 -D STD_OPTION=1
FT_FLAGS		= 	-Wall -Wextra -Werror -std=c++98 -D STD_OPTION=0

ifeq ($(SANITIZE_A),true)
        STD_FLAGS += -fsanitize=address
        FT_FLAGS += -fsanitize=address
endif

ifeq ($(SANITIZE_L),true)
        STD_FLAGS += -fsanitize=leak
        FT_FLAGS += -fsanitize=leak
endif

RESET			= 	\033[0m
GREEN 			= 	\033[38;5;46m
WHITE 			= 	\033[38;5;15m
GRAY 			= 	\033[38;5;8m
RED 			= 	\033[38;5;160m

all: $(STD_BINARY) $(FT_BINARY)

$(STD_BINARY): $(OBJECT)
	@echo "$(GREEN)----------------------------------------------------"
	@$(COMPILER) $(STD_FLAGS) $(SOURCE) -o $(STD_BINARY)
	@echo "STD Executable				./$(STD_BINARY) $(RESET)"

$(FT_BINARY): $(OBJECT)
	@echo "$(GREEN)----------------------------------------------------"
	@$(COMPILER) $(FT_FLAGS) $(SOURCE) -o $(FT_BINARY)
	@echo "FT Executable				./$(FT_BINARY) $(RESET)"

clean:
	@echo "$(RED)----------------------------------------------------"
	@/bin/rm -f $(OBJECT)
	@echo "$(GRAY)REMOVED O-FILES $(RESET)"

fclean: clean
	@echo "$(RED)----------------------------------------------------"
	@/bin/rm -f $(STD_BINARY) $(FT_BINARY) $(OUTPUT_FILES)
	@echo "$(GRAY)REMOVED EXECUTABLE FILE & OUTPUT FILES $(RESET)"

re: fclean all

.PHONY: all clean fclean re
