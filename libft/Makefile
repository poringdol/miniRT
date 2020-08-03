SHELL = /bin/sh

B&W = \033[0;0m
RED =  \033[0;31m
GREEN = \033[0;32m
PURPLE = \033[0;35m

CC = gcc
FLAGS = -Wall -Werror -Wextra -ggdb

RM = rm -rf
AR = ar rs
RANLIB = ranlib

SRCS = ft_memset.c\
	ft_bzero.c\
	ft_memcpy.c\
	ft_memccpy.c\
	ft_memmove.c\
	ft_memchr.c\
	ft_memcmp.c\
	ft_strlen.c\
	ft_strlcpy.c\
	ft_strlcat.c\
	ft_strchr.c\
	ft_strrchr.c\
	ft_strnstr.c\
	ft_strncmp.c\
	ft_atoi.c\
	ft_isalpha.c\
	ft_isdigit.c\
	ft_isalnum.c\
	ft_isascii.c\
	ft_isprint.c\
	ft_toupper.c\
	ft_tolower.c\
	ft_calloc.c\
	ft_strdup.c\
	ft_substr.c\
	ft_strjoin.c\
	ft_strtrim.c\
	ft_split.c\
	ft_itoa.c\
	ft_strmapi.c\
	ft_putchar_fd.c\
	ft_putstr_fd.c\
	ft_putendl_fd.c\
	ft_putnbr_fd.c
SRCDIR = ./sources/

OBJS = $(SRCS:.c=.o)
OBJDIR = ./objects/
OBJ = $(addprefix $(OBJDIR), $(OBJS))

DEP = $(OBJ:.o=.d)

SRCS_B = ft_lstnew.c\
	ft_lstadd_front.c\
	ft_lstsize.c\
	ft_lstlast.c\
	ft_lstadd_back.c\
	ft_lstdelone.c\
	ft_lstclear.c\
	ft_lstiter.c\
	ft_lstmap.c\
	ft_strnew.c\
	ft_memdel.c\
	ft_striter.c\
	ft_strequ.c\
	ft_strclr.c\
	ft_putchar.c\
	ft_putstr.c\
	ft_putendl.c\
	ft_putnbr.c\
	ft_putunbr.c\
	ft_strnequ.c\
	ft_striteri.c\
	ft_strdel.c\
	ft_strmap.c\
	ft_strcpy.c\
	ft_strncpy.c\
	ft_strcat.c\
	ft_strncat.c\
	ft_strstr.c\
	ft_strcmp.c\
	ft_islower.c\
	ft_isupper.c\
	ft_isblank.c\
	ft_iscntrl.c\
	ft_isgraph.c\
	ft_isspace.c\
	ft_isxdigit.c\
	ft_strcasecmp.c\
	ft_strncasecmp.c\
	ft_strcasestr.c\
	ft_strupcase.c\
	ft_strlowcase.c\
	ft_lltoa.c\
	ft_pow.c\
	ft_abs.c\
	get_next_line.c\
	get_next_line_utils.c\
	ft_atof.c

SRC_BDIR = ./sources_bonus/

OBJS_B = $(SRCS_B:.c=.o)
OBJ_BDIR = $(OBJDIR)
OBJ_B = $(addprefix $(OBJ_BDIR), $(OBJS_B))

DEP_B = $(OBJ_B:.o=.d)

NAME = libft.a
HEADER = ./includes/

all: $(NAME)

$(NAME): $(OBJ) $(OBJ_B)
	@$(AR) $(NAME) $(OBJ) $(OBJ_B)
	@echo "$(PURPLE)  Library $(NAME) created  $(B&W)"

-include $(DEP) $(DEP_B)

$(OBJDIR)%.o: $(SRCDIR)%.c
	@test -d $(OBJDIR) || mkdir $(OBJDIR)
	@$(CC) -I$(HEADER) -MMD -c $< -o $@ $(FLAGS)
	@echo "$(GREEN)  Object file $(PURPLE)$@ $(GREEN)created  $(B&W)"

$(OBJDIR)%.o: $(SRC_BDIR)%.c
	@test -d $(OBJDIR) || mkdir $(OBJDIR)
	@$(CC) -I$(HEADER) -MMD -c $< -o $@ $(FLAGS)
	@echo "$(GREEN)  Object file $(PURPLE)$@ $(GREEN)created  $(B&W)"

#so: $(OBJ) $(OBJ_B)
#	@test -d $(OBJDIR) || mkdir $(OBJDIR)
#	@$(CC) -L ./ -I$(HEADER) $(OBJ) $(OBJ_B) -shared -o libft.so $(FLAGS)

test: $(NAME)
	$(CC) main.c -L. -lft -I$(HEADER) -o test $(FLAGS)

clean:
	@$(RM) $(OBJDIR) libft.so
	@echo "$(RED)  Object files deleted  $(B&W)"

fclean: clean
	@$(RM) $(NAME)
	@echo "$(RED)  Library $(NAME) deleted  $(B&W)"

re: fclean all

.PHONY: all bonus clean fclean re test
