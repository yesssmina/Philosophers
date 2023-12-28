SRCS	=	main.c \
			utils.c \
			init.c \
			routine_loop.c \
			time.c \
			destroy.c \
			create_and_join.c \
<<<<<<< HEAD
			ft_checks.c \
			ft_eat.c \
			sleep_and_think.c \
=======
			checks.c \
>>>>>>> 4a61101077f61d28a8ec75d61409c3520b9ff57e

OBJS	= $(SRCS:.c=.o)
NAME	= philo

CC	= gcc
FLAGS	= -Wall -Wextra -Werror -g3

all:	$(NAME)

%.o: %.c
	@printf "\033[KCompiling: $<\r"
	@$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	@printf "\033[KCompiling: $$file\r"; \
	$(CC) $(FLAGS) -o $(NAME) $(OBJS) $(INCLUDE) $(READLINE_FLAGS)
	@echo "\033[1;32mPhilo: successful compilation\033[0m 🎇"

clean:
	@printf "\033[KRemoving $$file\r";
	@rm -f $(OBJS) $(B_OBJS)
	@echo "\033[1;36m===>Philo: .o correctly cleaned\033[0m"

fclean: clean
	@printf "\033[KRemoving $(NAME)\r"
	@rm -f $(NAME)
	@echo "\033[1;36m===>Philo: .a correctly cleaned\033[0m"
	
re: fclean all


.PHONY:	clean fclean re