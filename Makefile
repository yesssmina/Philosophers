SRCS	=	main.c \
			utils.c \
			init.c \
			routine.c \

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