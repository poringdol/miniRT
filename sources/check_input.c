/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdemocri <sashe@bk.ru>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/27 06:07:43 by pdemocri          #+#    #+#             */
/*   Updated: 2020/08/03 04:55:10 by pdemocri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include "libft.h"
#include "bmp.h"
#include "errors.h"

void	check_input(int argc, char *rt, char *save, int *fd)
{
	if (argc < 2 || argc > 3)
	{
		errno = 22;
		perror("Exit with error");
		exit(1);
	}
	if (ft_strncmp(&(rt[ft_strlen(rt) - 3]), ".rt", 4))
	{
		ft_putstr_fd("Exit with error: Invalid file extension\n", 2);
		exit(1);
	}
	if (save && ft_strcmp(save, "--save"))
	{
		ft_putstr_fd(INV_SECOND, 2);
		exit(1);
	}
	if ((*fd = open(rt, O_RDONLY)) < 0)
	{
		perror("Exit with error");
		exit(1);
	}
}
