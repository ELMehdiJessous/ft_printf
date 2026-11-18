SRC = ft_printf.c ft_printf_utils.c
OBJ = $(SRC:%.c=%.o)
NAME = libftprintf.a
AR = ar rcs
CC = cc
FLAGS = -Wall -Wextra -Werror
RM = rm -f

all: $(NAME)

$(NAME): $(OBJ)
	$(AR) $(NAME) $(OBJ)

%.o: %.c ft_printf.h
	$(CC) -c $(FLAGS) $< -o $@
      
clean:
	$(RM) $(OBJ)
	
fclean: clean
	$(RM) $(NAME)

re: fclean all