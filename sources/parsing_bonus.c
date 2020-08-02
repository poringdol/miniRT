#include "parsing.h"
#include "bonus.h"

int	fill_scene_bonus(double buf[BUF_S],
							char *line, char *freeline, int l)
{
	if (!ft_strncmp(line, "ld ", 3))
		fill_ld(buf, freeline, l);
	else if (!ft_strncmp(line, "cu ", 3))
		fill_cub(buf, freeline, l);
	else if(!ft_strncmp(line, "py ", 3))
		fill_pyramid(buf, freeline, l);
	else
		return (1);
	return (0);
}