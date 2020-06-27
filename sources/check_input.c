#include <fcntl.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include "libft.h"

void	check_input(int argc, char *argv, int *fd)
{
	if (argc < 2 || argc > 3)
	{
		errno = 22;
		perror("Exit with error");
		exit(1);
	}
	if (ft_strncmp(&(argv[ft_strlen(argv) - 3]), ".rt", 4) != 0)
	{
		ft_putstr_fd("Exit with error: Invalid file extension\n", 2);
		exit(1);
	}
	if ((*fd = open(argv, O_RDONLY)) < 0)
	{
		perror("Exit with error");
		exit(1);
	}
}
