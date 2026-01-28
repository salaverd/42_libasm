NAME = libasm.a

SRCS =  ft_strlen.s \
        ft_strcpy.s \
        ft_strcmp.s \
        ft_write.s \
        ft_read.s \
        ft_strdup.s

CC = nasm -felf64
OBJS = $(SRCS:.s=.o)

all: $(NAME)

$(NAME): $(OBJS)
	ar rc $(NAME) $(OBJS)

%.o: %.s
	$(CC) -o $@ $<

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)
	rm -rf a.out
	
re: fclean all

.PHONY: all clean fclean re