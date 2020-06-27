#include "parsing.h"

static void	lstclear_32(void **lst, void (*del)(void *))
{
	void	*tmp;
	t_lht	*type;

	type = *lst;
	if (lst != NULL && del != NULL)
	{
		while (type != NULL)
		{
			tmp = type->next;
			free(type);
			type = tmp;
		}
	}
}

static void	lstclear_40(void **lst, void (*del)(void *))
{
	void	*tmp;
	t_cam	*type;

	type = *lst;
	if (lst != NULL && del != NULL)
	{
		while (type != NULL)
		{
			tmp = type->next;
			free(type);
			type = tmp;
		}
	}
}

static void	lstclear_48(void **lst, void (*del)(void *))
{
	void	*tmp;
	t_cyl	*type;

	type = *lst;
	if (lst != NULL && del != NULL)
	{
		while (type != NULL)
		{
			tmp = type->next;
			free(type);
			type = tmp;
		}
	}
}

int			freemem_line(char *s)
{
	if (s)
	{
		free(s);
		s = NULL;
	}
	return (0);
}








int 		freemem_struct(char *error, int l)
{
	get_next_line(-1, NULL);
	// if (g_scene.res)
	// 	free(g_scene.res);
	// if (g_scene.amb)
	// 	free(g_scene.amb);
	lstclear_40((void *)&g_scene.cam, free);
	lstclear_32((void *)&g_scene.lht, free);
	lstclear_40((void *)&g_scene.pln, free);
	lstclear_32((void *)&g_scene.sph, free);
	lstclear_40((void *)&g_scene.sqr, free);
	lstclear_48((void *)&g_scene.cyl, free);
	lstclear_48((void *)&g_scene.tri, free);
	if (!error && !errno)
		return (0);
	else if (error)
	{
		ft_putstr_fd("Exit with error: ", 2);
		ft_putstr_fd(error, 2);
		l ? ft_putnbr_fd(l, 2) : 0;
		ft_putstr_fd("\n", 2);
	}
	else
		perror("Exit with error");
	return (1);
}