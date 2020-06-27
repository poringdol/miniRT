SHELL = /bin/sh

B&W = \033[0;0m
RED  = \033[0;31m
GREEN = \033[0;32m
PURPLE = \033[0;35m
	
CC = gcc
FLAGS = -Wall -Werror -Wextra -lXext -lX11 -lm -g
#-O3 -fsanitize=address
AR = ar rs
RM = rm -rf

NAME = libminirt.a
HEADERDIR = ./includes/

LIBFT = libft.a
LIBFTDIR = ./libft/
LIBFTHEADER = libft.h
LIBFTHEADERDIR = ./libft/includes/

MINILIBX = libmlx_Linux.a
MINILIBXDIR = ./minilibx/

SRC = check_input.c\
	  parsing.c\
	  fill_r_a_c_l.c\
	  fill_pl_sp_sq_cy_tr.c\
	  freemem.c\
	  init.c\
	  line.c\
	  render.c\
	  cordinates.c
SRCDIR = ./sources/

OBJS = $(SRC:.c=.o)
OBJDIR = ./objects/
OBJ = $(addprefix $(OBJDIR), $(OBJS))

DEP = $(OBJ:.o=.d)

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT) $(MINILIBX)
	@cp $(LIBFTDIR)$(LIBFT) $(NAME)
	@$(AR) $(NAME) $(OBJ)
	@echo "$(PURPLE)  Library $(NAME) created  $(B&W)"

-include $(DEP)

bonus: $(NAME)

$(OBJDIR)%.o: $(SRCDIR)%.c
	@test -d $(OBJDIR) || mkdir $(OBJDIR)
	@$(CC) -I$(MINILIBXDIR) -I$(LIBFTHEADERDIR) -I$(HEADERDIR) -MMD -c $< -o $@ $(FLAGS)
	@echo "$(GREEN)  Object file $(PURPLE)$@ $(GREEN)created  $(B&W)"

$(LIBFT):
	@$(MAKE) -C $(LIBFTDIR)

$(MINILIBX):
	@$(MAKE) -C $(MINILIBXDIR)

test: $(NAME)
	$(CC) minirt.c -L. -lminirt -L$(MINILIBXDIR) -lmlx -I$(MINILIBXDIR) -I$(LIBFTHEADERDIR) -I$(HEADERDIR) -o $@ $(FLAGS)

clean:
	@$(MAKE) clean -C $(LIBFTDIR)
	@$(MAKE) clean -C $(MINILIBXDIR)
	@$(RM) $(OBJDIR)

fclean:
	@$(MAKE) fclean -C $(LIBFTDIR)
	@$(MAKE) clean -C $(MINILIBXDIR)
	@$(RM) $(OBJDIR) $(NAME) test
	@echo "$(RED)  Library $(NAME) deleted  $(B&W)"

re: fclean all

.PHONY: all bonus clean fclean re test