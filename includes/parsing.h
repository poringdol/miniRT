/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdemocri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/27 06:13:35 by pdemocri          #+#    #+#             */
/*   Updated: 2020/07/27 06:14:36 by pdemocri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include <errno.h>
# include <stdlib.h>
# include <stdio.h>
# include "libft.h"
# include "structs.h"
# include "globals.h"
# include "errors.h"

# define RESOLUTION_X 1920
# define RESOLUTION_Y 1080
# define BUF_S 12

void	read_rt(int fd);
void	fill_r(double buf[BUF_S], char *freeline, int l);
void	fill_a(double buf[BUF_S], char *freeline, int l);
void	fill_c(double buf[BUF_S], char *freeline, int l);
void	fill_l(double buf[BUF_S], char *freeline, int l);
void	fill_pl(double buf[BUF_S], char *freeline, int l);
void	fill_sp(double buf[BUF_S], char *freeline, int l);
void	fill_sq(double buf[BUF_S], char *freeline, int l);
void	fill_cy(double buf[BUF_S], char *freeline, int l);
void	fill_tr(double buf[BUF_S], char *freeline, int l);

int		freemem_struct(char *error, int i);
int		freemem_line(char *s);
void	lstclear_cam(t_cam **lst, void (*del)(void *));
void	lstclear_lht(t_lht **lst, void (*del)(void *));
void	lstclear_pln(t_pln **lst, void (*del)(void *));
void	lstclear_sph(t_sph **lst, void (*del)(void *));
void	lstclear_sqr(t_sqr **lst, void (*del)(void *));
void	lstclear_cyl(t_cyl **lst, void (*del)(void *));
void	lstclear_tri(t_tri **lst, void (*del)(void *));

#endif
