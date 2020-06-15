#ifndef MINIRT_H
# define MINIRT_H

# include <stdlib.h>
# include <fcntl.h>
# include <errno.h>
# include <stdio.h>
# include "libft.h"
# include "minirt_struct.h"

# define INVARGS "Invalid number of arguments"
# define DOUBLE_R "Exit with error: Double initialization of Resolution"
# define DOUBLE_A "Exit with error: Double initialization of Ambient light"
# define INVAL_P "Exit with error: Invalid params for scene"

# define RESOLUTION_X 1920
# define RESOLUTION_Y 1024

# define BUF_S 30

t_scene	g_scene;

void	check_input(int argc, char *argv, int *fd);

void	read_rt(int fd);
void	parsing_rt(char *line);
void	fill_scene(float buf[BUF_S], char *tmp);
float	get_fnumber(char **arr);
void	fill_r(float buf[BUF_S]);
void	fill_a(float buf[BUF_S]);
void	fill_c(float buf[BUF_S]);
void	fill_l(float buf[BUF_S]);
void	fill_pl(float buf[BUF_S]);
void	fill_sp(float buf[BUF_S]);
void	fill_sq(float buf[BUF_S]);
void	fill_cy(float buf[BUF_S]);
void	fill_tr(float buf[BUF_S]);

#endif
