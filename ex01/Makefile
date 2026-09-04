NAME		= Form
CXX			= c++
CXXFLAGS	= -Wall -Wextra -Werror -std=c++98 -g
RM			= rm -f

OBJ_DIR		= obj

VPATH		= src

SRCS 		=	main.cpp \
				Bureaucrat.cpp \
				Form.cpp

OBJS		= $(SRCS:%.cpp=$(OBJ_DIR)/%.o)

INCLUDES	= -Iinclude 

all: $(NAME)

$(NAME): $(OBJS)
	@$(CXX) $(CXXFLAGS) $(INCLUDES) $(OBJS) -o $(NAME)
	@echo "Form OK\n"

$(OBJ_DIR)/%.o: %.cpp
	@mkdir -p $(OBJ_DIR)
	@$(CXX) $(CXXFLAGS) $(INCLUDES) -c $< -o $@

clean: 
	@$(RM) -r $(OBJ_DIR)
	@echo "Objects removed\n"

fclean: clean
	@$(RM) -r $(NAME)

re: fclean all

.PHONY : all clean fclean re
