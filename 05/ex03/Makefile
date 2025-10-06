FILES = main.cpp Bureaucrat.cpp AForm.cpp PresidentialPardonForm.cpp RobotomyRequestForm.cpp ShrubberyCreationForm.cpp Intern.cpp
OBJ_FILES = $(FILES:.cpp=.o)
CXX_FLAGS = -Wall -Wextra -Werror -std=c++98 -g3
CXX_COMPILER = c++
NAME = Wagie

all: $(NAME)

$(NAME): $(OBJ_FILES)
	$(CXX_COMPILER) $(CXX_FLAGS) $^ -o $@

%.o: %.cpp
	$(CXX_COMPILER) $(CXX_FLAGS) -c $< -o $@

clean:
	rm -f $(OBJ_FILES)

fclean: clean
	rm -f $(NAME)

re: fclean all
