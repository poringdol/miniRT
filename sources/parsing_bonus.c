/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdemocri <sashe@bk.ru>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/02 04:58:03 by pdemocri          #+#    #+#             */
/*   Updated: 2020/08/02 19:54:58 by pdemocri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"
#include "bonus.h"

int	fill_scene_bonus(double buf[BUF_S],
							char *line, char *freeline, int l)
{
	if (!ft_strncmp(line, "ld ", 3))
		fill_ld(buf, freeline, l);
	else if (!ft_strncmp(line, "cu ", 3))
		fill_cub(buf, freeline, l);
	else if (!ft_strncmp(line, "py ", 3))
		fill_pyramid(buf, freeline, l);
	else if (!ft_strncmp(line, "co ", 3))
		fill_cone(buf, freeline, l);
	else
		return (1);
	return (0);
}
