#include <fcntl.h>
#include <errno.h>
#include <stdio.h>
#include "minirt.h"

void	check_input(int argc, char *argv, int *fd)
{
	if (argc < 2 || argc > 3)
	{
		errno = 22;
		perror("Exit with error");
		exit(1);
	}
	if ((*fd = open(argv, O_RDONLY)) < 0)
	{
		perror("Exit with error");
		exit(1);
	}
}
