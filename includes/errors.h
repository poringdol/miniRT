#ifndef ERRORS_H
# define ERRORS_H

# define INVARGS "Invalid number of arguments\n"
# define INIT_FAIL "Failed mlx connection initialization\n"
# define DOUBLE_R \
"Invalid .rt file. Double initialization of Resolution at string "
# define DOUBLE_A \
"Invalid .rt file. Double initialization of Ambient light at string "
# define INVAL_P "Invalid .rt file. Invalid param at string "
# define INVAL_V "Invalid .rt file. Invalid value at string "

void	check_input(int argc, char *argv, int *fd);

#endif