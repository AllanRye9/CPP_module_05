NAME = ex01

SRC = 	srcs/Bureaucrat.cpp \
		srcs/Form.cpp \
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
