NAME = ex00

SRC = 	srcs/Bureaucrat.cpp \
		srcs/main.cpp

HEADER = include/

OBJS = $(SRC:%.cpp=%.o)

CXX = c++

CXXFLAGS = -Wall -Wextra -Werror -std=c++98

$(NAME): $(OBJS) $(HEADER)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

all: $(NAME)

clean: 
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

./PHONY: all re fclean clean
