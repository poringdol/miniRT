/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdemocri <sashe@bk.ru>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/27 06:10:08 by pdemocri          #+#    #+#             */
/*   Updated: 2020/07/31 05:04:57 by pdemocri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"
#include "bonus.h"

static void		camera_loop(t_cam **camera)
{
	t_cam	*start;

	start = *camera;
	while ((*camera)->next)
		*camera = (*camera)->next;
	(*camera)->next = start;
}

static double	get_fnumber(char **arr)
{
	int		k;
	char	*tmp;
	char	str[40];

	k = 0;
	tmp = *arr;
	if (*tmp == '-' || *tmp == '+')
	{
		str[k++] = *tmp;
		tmp++;
	}
	while (*tmp && ft_isdigit(*tmp))
		str[k++] = *tmp++;
	if (*tmp == '.')
		str[k++] = *tmp++;
	while (*tmp && ft_isdigit(*tmp))
		str[k++] = *tmp++;
	str[k] = '\0';
	*arr = tmp;
	return (ft_atof(str));
}

void			fill_scene(double buf[BUF_S], char *line, char *freeline, int l)
{
	if (*line == 'R' && *(line + 1) == ' ')
		fill_r(buf, freeline, l);
	else if (*line == 'A' && *(line + 1) == ' ')
		fill_a(buf, freeline, l);
	else if (*line == 'c' && *(line + 1) == ' ')
		fill_c(buf, freeline, l);
	else if (*line == 'l' && *(line + 1) == ' ')
		fill_l(buf, freeline, l);
	else if (*line == 'p' && *(line + 1) == 'l' && *(line + 2) == ' ')
		fill_pl(buf, freeline, l);
	else if (*line == 's' && *(line + 1) == 'p' && *(line + 2) == ' ')
		fill_sp(buf, freeline, l);
	else if (*line == 's' && *(line + 1) == 'q' && *(line + 2) == ' ')
		fill_sq(buf, freeline, l);
	else if (*line == 'c' && *(line + 1) == 'y' && *(line + 2) == ' ')
		fill_cy(buf, freeline, l);
	else if (*line == 't' && *(line + 1) == 'r' && *(line + 2) == ' ')
		fill_tr(buf, freeline, l);
	else if (*line == 'l' && *(line + 1) == 'd' && *(line + 2) == ' ')
		fill_ld(buf, freeline, l);
	else if (*line == 'c' && *(line + 1) == 'u' && *(line + 2) == ' ')
		fill_cub(buf, freeline, l);
	else
		exit(freemem_line(freeline) + freemem_struct(INVAL_P, l));
}

static void		parsing_rt(char *line, char *freeline, int l)
{
	double	buf[BUF_S];
	char	*tmp;
	int		i;

	i = 0;
	ft_bzero(buf, BUF_S * sizeof(double));
	tmp = line;
	while (ft_isalpha(*line))
		line++;
	while (*line && i < BUF_S)
	{
		if (ft_isspace(*line) || *line == ',')
			line++;
		else if ((ft_isdigit(*line)) || *line == '+' || *line == '-')
			buf[i++] = get_fnumber(&line);
		else if (*line == '#')
			break ;
		else
			exit(freemem_line(freeline) + freemem_struct(INVAL_V, l));
	}
	fill_scene(buf, tmp, freeline, l);
}

void			read_rt(int fd)
{
	char	*line;
	char	*tmp;
	int		l;

	l = 0;
	errno = 0;
	while (get_next_line(fd, &line) == 1 && errno == 0)
	{
		l++;
		tmp = line;
		while (ft_isspace(*line))
			line++;
		if (*line == '#' || *line == 0)
			line++;
		else if ((*line == 'R') || (*line == 'A') || (*line == 'c') ||
		(*line == 'l') || (*line == 'p') || (*line == 's') ||
		(*line == 's') || (*line == 'c') || (*line == 't'))
			parsing_rt(line, tmp, l);
		else
			exit(freemem_line(tmp) + freemem_struct(INVAL_P, l));
		free(tmp);
	}
	if (!g_scene.cam)
		exit(freemem_struct(NO_CAMERA, 0));
	camera_loop(&g_scene.cam);
}
