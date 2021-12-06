NAME =	libftprintf.a

SRCS =	utils.c output1.c \
		output2.c ft_printf.c \

OBJS =	$(SRCS:.c=.o)

SRC_D =	$(SRCS:.c=.d)

FT_PRINTF_H =  ft_printf.h

CC =	gcc

FLAGS =	-MMD -Wall -Werror -Wextra

.c.o:
	$(CC) $(FLAGS) -c $< -o ${<:.c=.o} -I $(FT_PRINTF_H)

all:	$(NAME)
		$(MAKE) -C ./libft all

$(NAME): $(OBJS)
		$(MAKE) -C ./libft
		ar rcs $(NAME) $(OBJS) libft/*.o

clean:
	rm -f $(OBJS)
	rm -f $(SRC_D)
	$(MAKE) -C ./libft clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C ./libft fclean

re:	fclean all

.PHONY: all clean fclean re

-include $(SRC_D)