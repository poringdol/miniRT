/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   freemem.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdemocri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/27 06:09:11 by pdemocri          #+#    #+#             */
/*   Updated: 2020/07/27 06:09:13 by pdemocri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

void	lstclear_cam(t_cam **lst, void (*del)(void *))
{
	t_cam	*type;
	void	*tmp;

	if (lst != NULL && del != NULL)
	{
		type = *lst;
		while (type != NULL)
		{
			tmp = type;
			if (type && type->next == *lst)
			{
				free(tmp);
				return ;
			}
			type = type->next;
			free(tmp);
		}
	}
}

void	lstclear_lht(t_lht **lst, void (*del)(void *))
{
	t_lht	*type;
	void	*tmp;

	if (lst != NULL && del != NULL)
	{
		type = *lst;
		while (type != NULL)
		{
			tmp = type;
			if (type && type->next == *lst)
			{
				free(tmp);
				return ;
			}
			type = type->next;
			free(tmp);
		}
	}
}

int		freemem_line(char *s)
{
	if (s)
	{
		free(s);
		s = NULL;
	}
	return (0);
}

int		freemem_struct(char *error, int l)
{
	get_next_line(-1, NULL);
	lstclear_cam((void *)&g_scene.cam, free);
	lstclear_lht((void *)&g_scene.lht, free);
	lstclear_pln((void *)&g_scene.pln, free);
	lstclear_sph((void *)&g_scene.sph, free);
	lstclear_sqr((void *)&g_scene.sqr, free);
	lstclear_cyl((void *)&g_scene.cyl, free);
	lstclear_tri((void *)&g_scene.tri, free);
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
