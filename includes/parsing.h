#ifndef PARSING_H
# define PARSING_H

# include <errno.h>
# include <stdlib.h>
# include <stdio.h>
# include "libft.h"
# include "structs.h"
# include "globals.h"
# include "errors.h"

# define RESOLUTION_X 1600
# define RESOLUTION_Y 900
# define BUF_S 12

void	read_rt(int fd);
void	parsing_rt(char *line, char *freeline, int l);
void	fill_scene(float buf[BUF_S], char *tmp, char *freeline, int l);
float	get_fnumber(char **arr);
void	fill_r(float buf[BUF_S], char *freeline, int l);
void	fill_a(float buf[BUF_S], char *freeline, int l);
void	fill_c(float buf[BUF_S], char *freeline, int l);
void	fill_l(float buf[BUF_S], char *freeline, int l);
void	fill_pl(float buf[BUF_S], char *freeline, int l);
void	fill_sp(float buf[BUF_S], char *freeline, int l);
void	fill_sq(float buf[BUF_S], char *freeline, int l);
void	fill_cy(float buf[BUF_S], char *freeline, int l);
void	fill_tr(float buf[BUF_S], char *freeline, int l);

int     freemem_struct(char *error, int i);
int		freemem_line(char *s);

#endif