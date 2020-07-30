/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   freemem_struct.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdemocri <sashe@bk.ru>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/27 06:09:21 by pdemocri          #+#    #+#             */
/*   Updated: 2020/07/30 06:12:28 by pdemocri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

void	lstclear_pln(t_pln **lst, void (*del)(void *))
{
	t_pln	*type;
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

void	lstclear_sph(t_sph **lst, void (*del)(void *))
{
	t_sph	*type;
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

void	lstclear_sqr(t_sqr **lst, void (*del)(void *))
{
	t_sqr	*type;
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

void	lstclear_cyl(t_cyl **lst, void (*del)(void *))
{
	t_cyl	*type;
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

void	lstclear_tri(t_tri **lst, void (*del)(void *))
{
	t_tri	*type;
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
