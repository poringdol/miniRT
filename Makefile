SHELL = /bin/sh
UNAME := $(shell uname)

B&W = \033[0;0m
RED  = \033[0;31m
GREEN = \033[0;32m
PURPLE = \033[0;35m
	
# FLAGS = -Wall -Werror -Wextra -pthread
FLAGS = -pthread
CC = gcc
ifeq ($(UNAME), Linux)
	FLAGS += -lXext -lX11 -lm -g\
	-D EXIT=65307\
	-D CAM=32\
	-D SAVE=115\
	-D SEPIA=102\
	-D REFLECT=122\
	-D RAINBOW=114\
	-D RIPPLES=103
	MINILIBXDIR = ./minilibx_linux/
endif
ifeq ($(UNAME), Darwin)
	FLAGS = -framework OpenGL -framework AppKit -lm -g\
	-D EXIT=53\
	-D CAM=49\
	-D SAVE=1\
	-D SEPIA=3\
	-D REFLECT=6\
	-D RAINBOW=15\
	-D RIPPLES=5
	MINILIBXDIR = ./minilibx_macos/
endif
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

SRC = check_input.c\
	  parsing.c\
	  fill_r_a_c_l.c\
	  fill_pl_sp_sq_cy_tr.c\
	  freemem.c\
	  freemem_struct.c\
	  init.c\
	  render.c\
	  render_utils.c\
	  color.c\
	  vector.c\
	  vector2.c\
	  normal.c\
	  substitution.c\
	  sphere.c\
	  plane.c\
	  triangle.c\
	  square.c\
	  cylinder.c\
	  cylinder_solution.c\
	  square_tops.c\
	  pixel.c\
	  light.c\
	  minirt_bonus.c\
	  shadows.c\
	  bmp.c\
	  sepia.c\
	  fill_bonus.c\
	  light_directional.c\
	  light_bonus.c\
	  pixel_bonus.c\
	  cub.c\
	  cub_util1.c\
	  cub_util2.c\
	  parsing_bonus.c\
	  pyramid.c\
	  pyramid_util1.c\
	  pyramid_util2.c\
	  cone.c\
	  cone_solution.c\
	  substitution2.c\
	  shadows_bonus.c
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
	@$(CC) minirt.c -L. -lminirt -L$(MINILIBXDIR) -lmlx $(FLAGS) -I$(MINILIBXDIR) -I$(LIBFTHEADERDIR) -I$(HEADERDIR) -o miniRT 

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
clean:
	@$(MAKE) clean -C $(LIBFTDIR)
	@$(MAKE) clean -C $(MINILIBXDIR)
	@$(RM) $(OBJDIR)

fclean:
	@$(MAKE) fclean -C $(LIBFTDIR)
	@$(MAKE) clean -C $(MINILIBXDIR)
	@$(RM) $(OBJDIR) $(NAME) miniRT
	@echo "$(RED)  Library $(NAME) deleted  $(B&W)"

re: fclean all

.PHONY: all bonus clean fclean re