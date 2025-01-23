NAME = ex03

SRC = 	srcs/Bureaucrat.cpp \
		srcs/RobotomyRequestForm.cpp \
		srcs/PresidentialPardonForm.cpp \
		srcs/ShrubberyCreationForm.cpp \
		srcs/AForm.cpp \
		srcs/Intern.cpp \
		srcs/main.cpp

HEADER = include/

OBJS = $(SRC:%.cpp=%.o)

CXX = c++

CXXFLAGS = -Wall -Wextra -Werror -std=c++98

$(NAME): $(OBJS) $(HEADER)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

all: $(NAME)

clean: 
	/bin/rm -f $(OBJS)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all

./PHONY: all re fclean clean
