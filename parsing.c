#include <errno.h>
#include "libft.h"
#include "minirt.h"
#include "minirt_struct.h"

void	read_rt(int fd)
{
	char	*line;
	char	*tmp;

	while (get_next_line(fd, &line) == 1 && errno == 0)
	{
		tmp = line;
		while (ft_isspace(*line))
			line++;
		if (*line == '#' || *line == 0)
			line++;
		else if ((*line == 'R') || (*line == 'A') || (*line == 'c') ||
		(*line == 'l') || (*line == 'p') || (*line == 's') ||
		(*line == 's') || (*line == 'c') || (*line == 't'))
			parsing_rt(line);
		else
		{
			free(tmp);
			exit(ft_putstr_fd("Invalid .rt file", 2));
		}
		free(tmp);
	}
}

void	parsing_rt(char *line)
{
	float	buf[BUF_S];
	char	*tmp;
	int		i;

	i = 0;
	ft_bzero(buf, BUF_S * sizeof(float));
	tmp = line;
	while (ft_isalpha(*line))
		line++;
	while (*line)
	{
		if (ft_isspace(*line) || *line == ',')
			line++;
		else if ((ft_isdigit(*line)) || *line == '+' || *line == '-')
			buf[i++] = get_fnumber(&line);
		else
			exit(ft_putstr_fd("Invalid .rt file", 2));
	}
	fill_scene(buf, tmp);
}

void	fill_scene(float buf[BUF_S], char *line)
{
	if (*line == 'R' && *(line + 1) == ' ')
		fill_r(buf);
	else if (*line == 'A' && *(line + 1) == ' ')
		fill_a(buf);
	else if (*line == 'c' && *(line + 1) == ' ')
		fill_c(buf);
	else if (*line == 'l' && *(line + 1) == ' ')
		fill_l(buf);
	else if (*line == 'p' && *(line + 1) == 'l' && *(line + 2) == ' ')
		fill_pl(buf);
	else if (*line == 's' && *(line + 1) == 'p' && *(line + 2) == ' ')
		fill_sp(buf);
	else if (*line == 's' && *(line + 1) == 'q' && *(line + 2) == ' ')
		fill_sq(buf);
	else if (*line == 'c' && *(line + 1) == 'y' && *(line + 2) == ' ')
		fill_cy(buf);
	else if (*line == 't' && *(line + 1) == 'r' && *(line + 2) == ' ')
		fill_tr(buf);
	else
		exit(ft_putstr_fd("Invalid .rt file", 2));
}

float	get_fnumber(char **arr)
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
