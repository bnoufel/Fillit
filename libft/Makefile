NAME = libft.a

SRCSDIR = srcs

FLAGS = -Wall -Werror -Wextra

INCLUDES = libft.h

OBJSDIR = objects

SRCS = $(SRCSDIR)/ft_memset.c\
	   $(SRCSDIR)/ft_bzero.c\
	   $(SRCSDIR)/ft_memcpy.c\
	   $(SRCSDIR)/ft_memccpy.c\
	   $(SRCSDIR)/ft_memmove.c\
	   $(SRCSDIR)/ft_memchr.c\
	   $(SRCSDIR)/ft_memcmp.c\
	   $(SRCSDIR)/ft_strlen.c\
	   $(SRCSDIR)/ft_strdup.c\
	   $(SRCSDIR)/ft_strcpy.c\
	   $(SRCSDIR)/ft_strncpy.c\
	   $(SRCSDIR)/ft_strcat.c\
	   $(SRCSDIR)/ft_strncat.c\
	   $(SRCSDIR)/ft_strlcat.c\
	   $(SRCSDIR)/ft_strchr.c\
	   $(SRCSDIR)/ft_strrchr.c\
	   $(SRCSDIR)/ft_strstr.c\
	   $(SRCSDIR)/ft_strnstr.c\
	   $(SRCSDIR)/ft_strcmp.c\
	   $(SRCSDIR)/ft_strncmp.c\
	   $(SRCSDIR)/ft_atoi.c\
	   $(SRCSDIR)/ft_isalpha.c\
	   $(SRCSDIR)/ft_isdigit.c\
	   $(SRCSDIR)/ft_isalnum.c\
	   $(SRCSDIR)/ft_isascii.c\
	   $(SRCSDIR)/ft_isprint.c\
	   $(SRCSDIR)/ft_toupper.c\
	   $(SRCSDIR)/ft_tolower.c\
	   $(SRCSDIR)/ft_memalloc.c\
	   $(SRCSDIR)/ft_memdel.c\
	   $(SRCSDIR)/ft_strnew.c\
	   $(SRCSDIR)/ft_strdel.c\
	   $(SRCSDIR)/ft_strclr.c\
	   $(SRCSDIR)/ft_striter.c\
	   $(SRCSDIR)/ft_striteri.c\
	   $(SRCSDIR)/ft_strmap.c\
	   $(SRCSDIR)/ft_strmapi.c\
	   $(SRCSDIR)/ft_strequ.c\
	   $(SRCSDIR)/ft_strnequ.c\
	   $(SRCSDIR)/ft_strsub.c\
	   $(SRCSDIR)/ft_strjoin.c\
	   $(SRCSDIR)/ft_strtrim.c\
	   $(SRCSDIR)/ft_strsplit.c\
	   $(SRCSDIR)/ft_itoa.c\
	   $(SRCSDIR)/ft_putchar.c\
	   $(SRCSDIR)/ft_putstr.c\
	   $(SRCSDIR)/ft_putendl.c\
	   $(SRCSDIR)/ft_putnbr.c\
	   $(SRCSDIR)/ft_putchar_fd.c\
	   $(SRCSDIR)/ft_putstr_fd.c\
	   $(SRCSDIR)/ft_putendl_fd.c\
	   $(SRCSDIR)/ft_putnbr_fd.c\
	   $(SRCSDIR)/ft_convert_base.c\
	   $(SRCSDIR)/ft_strndup.c

OBJS = $(SRCS:$(SRCSDIR)/%.c=$(OBJSDIR)/%.o)

all: $(NAME)

$(NAME): build $(OBJS)
	@ar rc $(NAME) $(OBJS)
	@ranlib $(NAME)

clean:
	@rm -f $(OBJS)
	@rm -rf $(OBJSDIR)

fclean: clean
	@rm -f $(NAME)

re: fclean all

build:
	@mkdir -p objects

$(OBJSDIR)/%.o: $(SRCSDIR)/%.c
	@gcc -c -o $@ $< $(FLAGS) -I$(INCLUDES)
