##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Makefile of my projet minishelL1
##

NAME	= navy

NAME_TEST =	unit_tests

SRC = ./src

TEST = ./tests

PLAYER_ONE = player_one

PLAYER_TWO = player_two

CC	= gcc

RM	= rm -f

SRCS_UNIT	= $(SRC)/info.c	\
			  $(SRC)/error_handling.c	\
			  $(SRC)/get_next_line.c	\
			  $(TEST)/unit_test.c	\
			  $(SRC)/my_strcalloc.c	\
			  $(SRC)/generate_map.c	\
			  $(SRC)/display_map.c	\
			  $(SRC)/check_error_boat.c	\
			  $(SRC)/my_free.c	\
			  $(SRC)/my_put_nbr.c	\
			  $(SRC)/my_get_nbr.c	\
			  $(SRC)/count_boat.c	\
			  $(SRC)/error_input.c	\
			  $(SRC)/send_signal.c	\
			  $(SRC)/receive_signal.c	\
			  $(SRC)/fill_map.c	\
			  $(SRC)/check_signal.c	\
			  $(SRC)/set_point.c	\
			  $(SRC)/$(PLAYER_ONE)/player_one.c	\
		  	  $(SRC)/$(PLAYER_ONE)/handler_pl_one.c	\
			  $(SRC)/$(PLAYER_TWO)/player_two.c

SRCS	= main.c	\
		  $(SRC)/info.c	\
		  $(SRC)/error_handling.c	\
		  $(SRC)/get_next_line.c	\
		  $(SRC)/my_strcalloc.c	\
		  $(SRC)/generate_map.c	\
		  $(SRC)/display_map.c	\
		  $(SRC)/check_error_boat.c	\
		  $(SRC)/my_free.c	\
		  $(SRC)/my_get_nbr.c	\
		  $(SRC)/my_put_nbr.c	\
		  $(SRC)/count_boat.c	\
		  $(SRC)/error_input.c	\
		  $(SRC)/send_signal.c	\
		  $(SRC)/receive_signal.c	\
		  $(SRC)/fill_map.c	\
		  $(SRC)/check_signal.c	\
		  $(SRC)/set_point.c	\
		  $(SRC)/$(PLAYER_ONE)/player_one.c	\
		  $(SRC)/$(PLAYER_ONE)/handler_pl_one.c	\
		  $(SRC)/$(PLAYER_TWO)/player_two.c

OBJS	= $(SRCS:.c=.o)

OBJS_UNIT	=	$(SRCS_UNIT:.c=.o)

CFLAGS = -I./include/ -g3

CFLAGS += -lcriterion

all: $(NAME)

$(NAME): $(OBJS)
	 $(CC) $(OBJS) -o $(NAME)
	
tests_run:	$(OBJS_UNIT)
	$(CC) -o $(NAME_TEST) $(OBJS_UNIT) $(CFLAGS)
	./$(NAME_TEST)

clean:
	$(RM) $(OBJS)
	$(RM) $(OBJS_UNIT)

fclean: clean
	$(RM) $(NAME)
	$(RM) $(NAME_TEST)

re: fclean all

.PHONY: all tests_run clean fclean re
